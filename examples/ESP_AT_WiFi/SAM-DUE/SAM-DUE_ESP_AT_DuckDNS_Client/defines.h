/****************************************************************************************************************************
  defines.h
   
  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, AVR, megaAVR
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, ovh.com

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             4
#define _DDNS_GENERIC_LOGLEVEL_     2

// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             true    //true
#define DDNS_USING_ETHERNET         false   //true

#define DDNS_USING_WIFI_AT          true

// Uncomment to use ESP32-AT commands
//#define USE_ESP32_AT              true

/////////////////////////////////

#if !( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )

  #error This code is intended to run on the SAM DUE platform! Please check your Tools->Board setting.
#endif

#if defined(WIFI_USE_SAM_DUE)
  #undef WIFI_USE_SAM_DUE
#endif
#define WIFI_USE_SAM_DUE          true

#warning Use SAM DUE architecture with WiFi

/////////////////////////////////
// To change according to usage
#define EspSerial Serial1
/////////////////////////////////

#warning SAM DUE board selected
#define BOARD_TYPE  "SAM DUE"

/////////////////////////////////

#define DDNS_USING_WIFI_AT    true

#warning Using ESP8266-AT/ESP32-AT and ESP8266_AT_WebServer Library
#define SHIELD_TYPE       "ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library" 

/////////////////////////////////

#include <ESP8266_AT_WebServer.h>

/////////////////////////////////

#ifndef BOARD_NAME
  #ifdef ARDUINO_BOARD
    #define BOARD_NAME          ARDUINO_BOARD
  #else
    #define BOARD_NAME          BOARD_TYPE
  #endif
#endif

#ifndef SHIELD_TYPE
  #define SHIELD_TYPE           "Unknown shield"
#endif

/////////////////////////////////
  
#include <DDNS_Generic.h>

ESP8266_AT_WebServer server(80);

#include "wifi_credentials.h"

const char* ssid      = SECRET_SSID;
const char* password  = SECRET_PASS;

/////////////////////////////////

#endif    //defines_h
