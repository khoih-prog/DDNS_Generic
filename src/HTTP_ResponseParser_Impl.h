/****************************************************************************************************************************
  HTTP_ResponseParser_Impl.h

  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
  Version: 1.0.1

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/09/2020 Initial coding for Generic boards using many WiFi/Ethernet modules/shields.
  1.0.1   K Hoang      28/09/2020 Fix issue with nRF52 and STM32F/L/H/G/WB/MP1 using ESP8266/ESP32-AT
 *****************************************************************************************************************************/

#ifndef HTTP_ResponseParser_Impl_h
#define HTTP_ResponseParser_Impl_h

HTTP_ResponseParser::HTTP_ResponseParser()
{
  resetState();
}

void HTTP_ResponseParser::resetState()
{
  iState                = eRequestSent;   //eIdle;
  iStatusCode           = 0;
  iContentLength        = kNoContentLengthHeader;
  iBodyLengthConsumed   = 0;
  iContentLengthPtr     = kContentLengthPrefix;
  iIsChunked            = false;
  iChunkLength          = 0;

  iTransferEncodingChunkedPtr = kTransferEncodingChunked;

  responseStringPos     = 0;
}

////////////////////////////


int HTTP_ResponseParser::responseStatusCode(String responseString)
{
  resetState();
  
  DDNS_LOGDEBUG1("responseStatusCode: responseString = ", responseString);

  // The first line will be of the form Status-Line:
  //   HTTP-Version SP Status-Code SP Reason-Phrase CRLF
  // Where HTTP-Version is of the form:
  //   HTTP-Version   = "HTTP" "/" 1*DIGIT "." 1*DIGIT

  int c = '\0';

  do
  {
    // Make sure the status code is reset, and likewise the state.  This
    // lets us easily cope with 1xx informational responses by just
    // ignoring them really, and reading the next line for a proper response
    iStatusCode = 0;
    iState = eRequestSent;

    // Pseudo-regexp we're expecting before the status-code
    const char* statusPrefix = "HTTP/*.* ";
    const char* statusPtr = statusPrefix;

    // Whilst we haven't reached the end of the headers
    while ( c != '\n' )
    {
      c = read(responseString);
      
      //DDNS_LOGDEBUG1("c =", String(c));

      if (c != -1)
      {
        switch (iState)
        {
          case eRequestSent:
            // We haven't reached the status code yet
            if ( (*statusPtr == '*') || (*statusPtr == c) )
            {
              // This character matches, just move along
              statusPtr++;
              
              if (*statusPtr == '\0')
              {
                // We've reached the end of the prefix
                iState = eReadingStatusCode;
              }
            }
            else
            {
              return HTTP_ERROR_INVALID_RESPONSE;
            }
            break;
          case eReadingStatusCode:
            if (isdigit(c))
            {
              // This assumes we won't get more than the 3 digits we
              // want
              iStatusCode = iStatusCode * 10 + (c - '0');
            }
            else
            {
              // We've reached the end of the status code
              // We could sanity check it here or double-check for ' '
              // rather than anything else, but let's be lenient
              iState = eStatusCodeRead;
            }
            break;
          case eStatusCodeRead:
            // We're just waiting for the end of the line now
            break;

          default:
            break;
        };
      }
    }

    if ( (c == '\n') && (iStatusCode < 200 && iStatusCode != 101) )
    {
      // We've reached the end of an informational status line
      c = '\0'; // Clear c so we'll go back into the data reading loop
    }

    // If we've read a status code successfully but it's informational (1xx)
    // loop back to the start
  } while ( (iState == eStatusCodeRead) && (iStatusCode < 200 && iStatusCode != 101) );
  
  if ( (c == '\n') && (iState == eStatusCodeRead) )
  {
    // We've read the status-line successfully
    return iStatusCode;
  }
  else if (c != '\n')
  {
    // We must've timed out before we reached the end of the line
    return HTTP_ERROR_TIMED_OUT;
  }
  else
  {
    // This wasn't a properly formed status line, or at least not one we
    // could understand
    return HTTP_ERROR_INVALID_RESPONSE;
  }
}

int HTTP_ResponseParser::skipResponseHeaders(String responseString)
{
  // Whilst we haven't reached the end of the headers
  while ( !endOfHeadersReached(responseString) )
  {
    if (available(responseString))
    {
      (void) readHeader(responseString);
    }
  }
  
  if (endOfHeadersReached(responseString))
  {
    // Success
    return HTTP_SUCCESS;
  }
  else
  {
    // We must've timed out
    return HTTP_ERROR_TIMED_OUT;
  }
}

bool HTTP_ResponseParser::endOfHeadersReached(String responseString)
{
  return (iState == eReadingBody || iState == eReadingChunkLength || iState == eReadingBodyChunk);
};

int HTTP_ResponseParser::contentLength(String responseString)
{
  // skip the response headers, if they haven't been read already
  if (!endOfHeadersReached(responseString))
  {
    skipResponseHeaders(responseString);
  }

  return iContentLength;
}

int HTTP_ResponseParser::responseStringRead(String responseString)
{
  return (responseString.charAt(responseStringPos));
}

String HTTP_ResponseParser::responseBody(String responseString)
{
  String response;
  
  int bodyLength = contentLength(responseString);
  
  DDNS_LOGDEBUG1("HTTP_ResponseParser::responseBody => bodyLength =", bodyLength);

  if (bodyLength > 0)
  {
    // try to reserve bodyLength bytes
    if ( !response.reserve(bodyLength) )
    {
      DDNS_LOGDEBUG("HTTP_ResponseParser::responseBody => String reserve failed");

      // String reserve failed
      return String();
    }
  }

  // Keep on Reading, until:
  // we have a content length: body length equals consumed or no bytes available

  int toRead = bodyLength;
  //  - no content length:  no bytes are available

  while (toRead-- > 0)
  {
    int c = responseStringRead(responseString);
    responseStringPos++;

    //DDNS_LOGDEBUG1("c =", String(c));

    if (c == -1)
    {
      // read done
      break;
    }

    if (!response.concat((char)c))
    {
      DDNS_LOGDEBUG("HTTP_ResponseParser::responseBody => adding char failed");

      // adding char failed
      return String();
    }
  }

  if (bodyLength > 0 && (unsigned int)bodyLength != response.length())
  {
    DDNS_LOGDEBUG("HTTP_ResponseParser::responseBody => bodyLength != response.length");

    // failure, we did not read in reponse content length bytes
    return String();
  }

  DDNS_LOGDEBUG1("HTTP_ResponseParser::responseBody => response=", response);

  return response;
}

bool HTTP_ResponseParser::endOfBodyReached(String responseString)
{
  if (endOfHeadersReached(responseString) && (contentLength(responseString) != kNoContentLengthHeader))
  {
    // We've got to the body and we know how long it will be
    return (iBodyLengthConsumed >= contentLength(responseString));
  }
  
  return false;
}

int HTTP_ResponseParser::available(String responseString)
{
  if (iState == eReadingChunkLength)
  {
    while (responseStringPos < responseString.length())
    {
      char c = responseStringRead(responseString);
      responseStringPos++;

      if (c == '\n')
      {
        iState = eReadingBodyChunk;
        break;
      }
      else if (c == '\r')
      {
        // no-op
      }
      else if (isHexadecimalDigit(c))
      {
        char digit[2] = {c, '\0'};

        iChunkLength = (iChunkLength * 16) + strtol(digit, NULL, 16);
      }
    }
  }

  if (iState == eReadingBodyChunk && iChunkLength == 0)
  {
    iState = eReadingChunkLength;
  }

  if (iState == eReadingChunkLength)
  {
    return 0;
  }

  int clientAvailable = (responseStringPos < responseString.length());

  if (iState == eReadingBodyChunk)
  {
    return min(clientAvailable, iChunkLength);
  }
  else
  {
    return clientAvailable;
  }
}

int HTTP_ResponseParser::read(String responseString)
{
  if (iIsChunked && !available(responseString))
  {
    return -1;
  }

  int ret = responseStringRead(responseString);
  responseStringPos++;

  if (ret >= 0)
  {
    if (endOfHeadersReached(responseString) && iContentLength > 0)
    {
      // We're outputting the body now and we've seen a Content-Length header
      // So keep track of how many bytes are left
      iBodyLengthConsumed++;
    }

    if (iState == eReadingBodyChunk)
    {
      iChunkLength--;

      if (iChunkLength == 0)
      {
        iState = eReadingChunkLength;
      }
    }
  }
  
  return ret;
}

bool HTTP_ResponseParser::headerAvailable(String responseString)
{
  // clear the currently store header line
  iHeaderLine = "";

  while (!endOfHeadersReached(responseString))
  {
    // read a byte from the header
    int c = readHeader(responseString);

    if (c == '\r' || c == '\n')
    {
      if (iHeaderLine.length())
      {
        // end of the line, all done
        break;
      }
      else
      {
        // ignore any CR or LF characters
        continue;
      }
    }

    // append byte to header line
    iHeaderLine += (char)c;
  }

  return (iHeaderLine.length() > 0);
}

String HTTP_ResponseParser::readHeaderName(String responseString)
{
  int colonIndex = iHeaderLine.indexOf(':');

  if (colonIndex == -1)
  {
    return String();
  }

  return iHeaderLine.substring(0, colonIndex);
}


String HTTP_ResponseParser::readHeaderValue(String responseString)
{
  int colonIndex = iHeaderLine.indexOf(':');
  int startIndex = colonIndex + 1;

  if (colonIndex == -1)
  {
    return String();
  }

  // trim any leading whitespace
  while (startIndex < (int)iHeaderLine.length() && isSpace(iHeaderLine[startIndex]))
  {
    startIndex++;
  }

  return iHeaderLine.substring(startIndex);
}

int HTTP_ResponseParser::read(uint8_t *buf, size_t size, String responseString)
{
  strncpy((char*) buf, responseString.c_str(), size);

  int ret = size;

  if (endOfHeadersReached(responseString) && iContentLength > 0)
  {
    // We're outputting the body now and we've seen a Content-Length header
    // So keep track of how many bytes are left
    if (ret >= 0)
    {
      iBodyLengthConsumed += ret;
    }
  }
  
  return ret;
}

int HTTP_ResponseParser::readHeader(String responseString)
{
  char c = read(responseString);

  if (endOfHeadersReached(responseString))
  {
    // We've passed the headers, but rather than return an error, we'll just
    // act as a slightly less efficient version of read()
    return c;
  }

  // Whilst reading out the headers to whoever wants them, we'll keep an
  // eye out for the "Content-Length" header
  switch (iState)
  {
    case eStatusCodeRead:
      // We're at the start of a line, or somewhere in the middle of reading
      // the Content-Length prefix
      if (*iContentLengthPtr == c)
      {
        // This character matches, just move along
        iContentLengthPtr++;
        
        if (*iContentLengthPtr == '\0')
        {
          // We've reached the end of the prefix
          iState = eReadingContentLength;
          // Just in case we get multiple Content-Length headers, this
          // will ensure we just get the value of the last one
          iContentLength = 0;
          iBodyLengthConsumed = 0;
        }
      }
      else if (*iTransferEncodingChunkedPtr == c)
      {
        // This character matches, just move along
        iTransferEncodingChunkedPtr++;
        
        if (*iTransferEncodingChunkedPtr == '\0')
        {
          // We've reached the end of the Transfer Encoding: chunked header
          iIsChunked = true;
          iState = eSkipToEndOfHeader;
        }
      }
      else if (((iContentLengthPtr == kContentLengthPrefix) && (iTransferEncodingChunkedPtr == kTransferEncodingChunked)) && (c == '\r'))
      {
        // We've found a '\r' at the start of a line, so this is probably
        // the end of the headers
        iState = eLineStartingCRFound;
      }
      else
      {
        // This isn't the Content-Length or Transfer Encoding chunked header, skip to the end of the line
        iState = eSkipToEndOfHeader;
      }
      break;
    case eReadingContentLength:
      if (isdigit(c))
      {
        iContentLength = iContentLength * 10 + (c - '0');
      }
      else
      {
        // We've reached the end of the content length
        // We could sanity check it here or double-check for "\r\n"
        // rather than anything else, but let's be lenient
        iState = eSkipToEndOfHeader;
      }
      break;
    case eLineStartingCRFound:
      if (c == '\n')
      {
        if (iIsChunked)
        {
          iState = eReadingChunkLength;
          iChunkLength = 0;
        }
        else
        {
          iState = eReadingBody;
        }
      }
      break;
    default:
      // We're just waiting for the end of the line now
      break;
  };

  if ( (c == '\n') && !endOfHeadersReached(responseString) )
  {
    // We've got to the end of this line, start processing again
    iState = eStatusCodeRead;
    iContentLengthPtr = kContentLengthPrefix;
    iTransferEncodingChunkedPtr = kTransferEncodingChunked;
  }
  // And return the character read to whoever wants it
  return c;
}

#endif    // HTTP_ResponseParser_Impl_h
