/****************************************************************************************************************************
  DDNS_Generic_Debug.h
   
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
 
#ifndef DDNS_Generic_Debug_H
#define DDNS_Generic_Debug_H

#ifdef DDNS_GENERIC_DEBUG_PORT
  #define DBG_PORT            DDNS_GENERIC_DEBUG_PORT
#else
  #define DBG_PORT            Serial
#endif

// Change _DDNS_GENERIC_LOGLEVEL_ to set tracing and logging verbosity
// 0: DISABLED: no logging
// 1: ERROR: errors
// 2: DEBUG: errors, warnings, informational and debug

#ifndef _DDNS_GENERIC_LOGLEVEL_
  #define _DDNS_GENERIC_LOGLEVEL_       0
#endif

#define DDNS_LOGERROR(x)         if(_DDNS_GENERIC_LOGLEVEL_>0) { DBG_PORT.print("[DDNS] "); DBG_PORT.println(x); }
#define DDNS_LOGERROR0(x)        if(_DDNS_GENERIC_LOGLEVEL_>0) { DBG_PORT.print(x); }
#define DDNS_LOGERROR1(x,y)      if(_DDNS_GENERIC_LOGLEVEL_>0) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DDNS_LOGERROR2(x,y,z)    if(_DDNS_GENERIC_LOGLEVEL_>0) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DDNS_LOGERROR3(x,y,z,w)  if(_DDNS_GENERIC_LOGLEVEL_>0) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

///////////////////////////////////////

#define DDNS_LOGWARN(x)          if(_DDNS_GENERIC_LOGLEVEL_>1) { DBG_PORT.print("[DDNS] "); DBG_PORT.println(x); }
#define DDNS_LOGWARN0(x)         if(_DDNS_GENERIC_LOGLEVEL_>1) { DBG_PORT.print(x); }
#define DDNS_LOGWARN1(x,y)       if(_DDNS_GENERIC_LOGLEVEL_>1) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DDNS_LOGWARN2(x,y,z)     if(_DDNS_GENERIC_LOGLEVEL_>1) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DDNS_LOGWARN3(x,y,z,w)   if(_DDNS_GENERIC_LOGLEVEL_>1) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

///////////////////////////////////////

#define DDNS_LOGINFO(x)          if(_DDNS_GENERIC_LOGLEVEL_>2) { DBG_PORT.print("[DDNS] "); DBG_PORT.println(x); }
#define DDNS_LOGINFO0(x)         if(_DDNS_GENERIC_LOGLEVEL_>2) { DBG_PORT.print(x); }
#define DDNS_LOGINFO1(x,y)       if(_DDNS_GENERIC_LOGLEVEL_>2) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DDNS_LOGINFO2(x,y,z)     if(_DDNS_GENERIC_LOGLEVEL_>2) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DDNS_LOGINFO3(x,y,z,w)   if(_DDNS_GENERIC_LOGLEVEL_>2) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

///////////////////////////////////////

#define DDNS_LOGDEBUG(x)         if(_DDNS_GENERIC_LOGLEVEL_>3) { DBG_PORT.print("[DDNS] "); DBG_PORT.println(x); }
#define DDNS_LOGDEBUG0(x)        if(_DDNS_GENERIC_LOGLEVEL_>3) { DBG_PORT.print(x); }
#define DDNS_LOGDEBUG1(x,y)      if(_DDNS_GENERIC_LOGLEVEL_>3) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.println(y); }
#define DDNS_LOGDEBUG2(x,y,z)    if(_DDNS_GENERIC_LOGLEVEL_>3) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.println(z); }
#define DDNS_LOGDEBUG3(x,y,z,w)  if(_DDNS_GENERIC_LOGLEVEL_>3) { DBG_PORT.print("[DDNS] "); DBG_PORT.print(x); DBG_PORT.print(" "); DBG_PORT.print(y); DBG_PORT.print(" "); DBG_PORT.print(z); DBG_PORT.print(" "); DBG_PORT.println(w); }

#endif    // DDNS_Generic_Debug_H
