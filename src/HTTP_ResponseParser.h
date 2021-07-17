/****************************************************************************************************************************
  HTTP_ResponseParser.h
   
  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, AVR, megaAVR, Teensy
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A, WT32_ETH01

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, ovh.com

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
  Version: 1.4.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/09/2020 Initial coding for Generic boards using many WiFi/Ethernet modules/shields.
  1.0.1   K Hoang      28/09/2020 Fix issue with nRF52 and STM32F/L/H/G/WB/MP1 using ESP8266/ESP32-AT
  1.1.0   K Hoang      03/04/2021 Add OVH.com support. Remove dependency on <functional>. Add support to AVR Mega and megaAVR.
  1.2.0   K Hoang      04/04/2021 Add support to Teensy LC, 3.x, 4.0 and 4.1 using Ethernet, NativeEthernet, WiFi or ESP-AT
  1.3.0   K Hoang      15/05/2021 Add support to RP2040 using Ethernet or ESP-AT
  1.4.0   K Hoang      16/07/2021 Add support to WT32_ETH01 (ESP32 + LAN8720)
 *****************************************************************************************************************************/

#ifndef HTTP_ResponseParser_h
#define HTTP_ResponseParser_h

#include <Arduino.h>
#include <IPAddress.h>

//const int HTTP_SUCCESS = 0;

// Spent too long waiting for a reply
//const int HTTP_ERROR_TIMED_OUT = -3;

// The response from the server is invalid, is it definitely an HTTP server?
//const int HTTP_ERROR_INVALID_RESPONSE = -4;

// Define some of the common headers here
// That lets other code reuse them without having to declare another copy
// of them, so saves code space and RAM
#define HTTP_HEADER_CONTENT_LENGTH      "Content-Length"
#define HTTP_HEADER_CONTENT_TYPE        "Content-Type"
#define HTTP_HEADER_CONNECTION          "Connection"
#define HTTP_HEADER_TRANSFER_ENCODING   "Transfer-Encoding"
#define HTTP_HEADER_USER_AGENT          "User-Agent"
#define HTTP_HEADER_VALUE_CHUNKED       "chunked"

class HTTP_ResponseParser
{
  public:
    const int kNoContentLengthHeader = -1;

    HTTP_ResponseParser();

    // KH Add
    int responseStringRead(String responseString);

    // Get the HTTP status code contained in the response.
    // For example, 200 for successful request, 404 for file not found, etc.
    int responseStatusCode(String responseString);

    // Check if a header is available to be read.
    // Use readHeaderName() to read header name, and readHeaderValue() to read the header value
    // MUST be called after responseStatusCode() and before contentLength()
    bool headerAvailable(String responseString);

    // Read the name of the current response header.
    // Returns empty string if a header is not available.
    String readHeaderName(String responseString);

    // Read the value of the current response header.
    // Returns empty string if a header is not available.
    String readHeaderValue(String responseString);

    /** Read the next character of the response headers.
      This functions in the same way as read() but to be used when reading
      through the headers.  Check whether or not the end of the headers has
      been reached by calling endOfHeadersReached(), although after that point
      this will still return data as read() would, but slightly less efficiently
      MUST be called after responseStatusCode() and before contentLength()
      @return The next character of the response headers
    */
    int readHeader(String responseString);

    /** Skip any response headers to get to the body.
      Use this if you don't want to do any special processing of the headers
      returned in the response.  You can also use it after you've found all of
      the headers you're interested in, and just want to get on with processing
      the body.
      MUST be called after responseStatusCode()
      @return HTTP_SUCCESS if successful, else an error code
    */
    int skipResponseHeaders(String responseString);

    /** Test whether all of the response headers have been consumed.
      @return true if we are now processing the response body, else false
    */
    bool endOfHeadersReached(String responseString);

    /** Test whether the end of the body has been reached.
      Only works if the Content-Length header was returned by the server
      @return true if we are now at the end of the body, else false
    */
    bool endOfBodyReached(String responseString);

    /** Return the length of the body.
      Also skips response headers if they have not been read already
      MUST be called after responseStatusCode()
      @return Length of the body, in bytes, or kNoContentLengthHeader if no
      Content-Length header was returned by the server
    */
    int contentLength(String responseString);

    /** Returns if the response body is chunked
      @return true if response body is chunked, false otherwise
    */
    int isResponseChunked() 
    {
      return iIsChunked;
    }

    /** Return the response body as a String
      Also skips response headers if they have not been read already
      MUST be called after responseStatusCode()
      @return response body of request as a String
    */
    String responseBody(String responseString);

    virtual int available(String responseString);

    /** Read the next byte from the server.
      @return Byte read or -1 if there are no bytes available.
    */
    virtual int read(String responseString);

    virtual int read(uint8_t *buf, size_t size, String responseString);


  protected:
    // Reset internal state data back to the "just initialised" state
    void resetState();

    const char* kContentLengthPrefix = HTTP_HEADER_CONTENT_LENGTH ": ";
    const char* kTransferEncodingChunked = HTTP_HEADER_TRANSFER_ENCODING ": " HTTP_HEADER_VALUE_CHUNKED;


    typedef enum
    {
      eIdle,
      eRequestStarted,
      eRequestSent,
      eReadingStatusCode,
      eStatusCodeRead,
      eReadingContentLength,
      eSkipToEndOfHeader,
      eLineStartingCRFound,
      eReadingBody,
      eReadingChunkLength,
      eReadingBodyChunk
    } tHttpState;

    // Current state of the finite-state-machine
    tHttpState iState;

    // Stores the status code for the response, once known
    int iStatusCode;
    
    // Stores the value of the Content-Length header, if present
    int iContentLength;
    
    // How many bytes of the response body have been read by the user
    int iBodyLengthConsumed;
    
    // How far through a Content-Length header prefix we are
    const char* iContentLengthPtr;
    
    // How far through a Transfer-Encoding chunked header we are
    const char* iTransferEncodingChunkedPtr;
    
    // Stores if the response body is chunked
    bool iIsChunked;
    
    // Stores the value of the current chunk length, if present
    int iChunkLength;
    
    uint32_t  iHttpResponseTimeout;
    bool      iConnectionClose;
    bool      iSendDefaultRequestHeaders;
    String    iHeaderLine;

    uint16_t  responseStringPos = 0;
};

#include "HTTP_ResponseParser_Impl.h"

#endif    // HTTP_ResponseParser_h
