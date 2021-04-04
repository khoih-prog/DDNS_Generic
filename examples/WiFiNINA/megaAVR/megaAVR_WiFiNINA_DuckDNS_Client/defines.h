/****************************************************************************************************************************
  defines.h
   
  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, AVR, megaAVR, Teensy
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, ovh.com

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
  Version: 1.2.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/09/2020 Initial coding for Generic boards using many WiFi/Ethernet modules/shields.
  1.0.1   K Hoang      28/09/2020 Fix issue with nRF52 and STM32F/L/H/G/WB/MP1 using ESP8266/ESP32-AT
  1.1.0   K Hoang      03/04/2021 Add OVH.com support. Remove dependency on <functional>. Add support to AVR Mega and megaAVR.
  1.2.0   K Hoang      04/04/2021 Add support to Teensy LC, 3.x, 4.0 and 4.1 using Ethernet, NativeEthernet, WiFi or ESP-AT
 *****************************************************************************************************************************/

#ifndef defines_h
#define defines_h

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             4
#define _WIFININA_LOGLEVEL_         4
#define _DDNS_GENERIC_LOGLEVEL_     2

// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             true    //true
#define DDNS_USING_ETHERNET         false   //true

/////////////////////////////////

#if !( defined(__AVR_ATmega4809__) || defined(ARDUINO_AVR_UNO_WIFI_REV2) || defined(ARDUINO_AVR_NANO_EVERY) )
  #error This code is intended to run on megaAVR UNO_WIFI_REV2, NANO_EVERY ! Please check your Tools->Board setting.
#endif

#if defined(WIFI_USE_MEGA_AVR)
  #undef WIFI_USE_MEGA_AVR
#endif
#define WIFI_USE_MEGA_AVR          true

#warning Use megaAVR architecture with WiFi

/////////////////////////////////

#if defined(ARDUINO_AVR_UNO_WIFI_REV2)
  #define BOARD_TYPE      "ARDUINO_AVR_UNO_WIFI_REV2"
#elif defined(ARDUINO_AVR_NANO_EVERY)
  #define BOARD_TYPE      "ARDUINO_AVR_NANO_EVERY"
#else
  #define BOARD_TYPE      "Unknown MegaAVR ATmega4809"  
#endif

#warning megaAVR ATmega4809 board selected

#ifndef BOARD_TYPE
  #define BOARD_TYPE  "MegaAVR ATmega4809"
#endif

/////////////////////////////////

// Select one to be true: USE_WIFI_NINA, DDNS_USING_WIFI_AT or USE_WIFI_CUSTOM
#define USE_WIFI_NINA         true

#if defined(ARDUINO_SAMD_MKR1000)
  #if defined(USE_WIFI_NINA)
    #undef USE_WIFI_NINA
  #endif
  
  #define USE_WIFI_NINA         false
  #define USE_WIFI101           true
  #define SHIELD_TYPE           "WiFi101 using WiFiNINA_Generic Library"
#endif


#warning Using WiFiNINA and WiFiNINA_Generic Library
#define SHIELD_TYPE           "WiFiNINA using WiFiNINA_Generic Library"

/////////////////////////////////

#include <WiFiWebServer.h>

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

WiFiServer server(80);

#include "wifi_credentials.h"

const char* ssid      = SECRET_SSID;
const char* password  = SECRET_PASS;

/////////////////////////////////

#endif    //defines_h
