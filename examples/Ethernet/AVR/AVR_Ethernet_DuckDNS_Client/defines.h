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

// Debug Level from 0 to 4
#define _DDNS_GENERIC_LOGLEVEL_     2

// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             false
#define DDNS_USING_ETHERNET         true

/////////////////////////////////
  
#if !( defined(__AVR_ATmega2560__) )
  #error This code is intended to run on AVR Mega, Mega2560 and Mega ADK! Please check your Tools->Board setting.
#endif

/////////////////////////////////

#if defined(ETHERNET_USE_AVR)
  #undef ETHERNET_USE_AVR
#endif

#define ETHERNET_USE_AVR          true
#warning Use AVR architecture with Ethernet   

// Default pin 10 to SS/CS
#define USE_THIS_SS_PIN       10

/////////////////////////////////
  
#if defined(ARDUINO_AVR_MEGA2560)
  #define BOARD_TYPE      "AVR_MEGA2560"
#elif defined(ARDUINO_AVR_MEGA)
  #define BOARD_TYPE      "ARDUINO_AVR_MEGA"
#elif defined(ARDUINO_AVR_ADK)
  #define BOARD_TYPE      "ARDUINO_AVR_ADK"  
#endif

#warning AVR Mega board selected

#ifndef BOARD_TYPE
  #define BOARD_TYPE  "AVR Mega"
#endif

///////////////////////////////////////////
// Select Ethernet Library for the Shield
///////////////////////////////////////////

#define USE_UIP_ETHERNET        false
#define USE_CUSTOM_ETHERNET     false

// Only one if the following to be true
#define USE_ETHERNET            false
#define USE_ETHERNET2           false //true
#define USE_ETHERNET3           false //true
#define USE_ETHERNET_LARGE      true
#define USE_ETHERNET_ESP8266    false //true
#define USE_ETHERNET_ENC        false

#if ( USE_ETHERNET2 || USE_ETHERNET3 || USE_ETHERNET_LARGE || USE_ETHERNET_ESP8266 || USE_ETHERNET_ENC )
  #ifdef USE_CUSTOM_ETHERNET
    #undef USE_CUSTOM_ETHERNET
    #define USE_CUSTOM_ETHERNET   false
  #endif
#endif

// Currently, only Ethernet lib available for STM32 using W5x00
#if !(USE_BUILTIN_ETHERNET || ETHERNET_USE_STM32)
  #if USE_ETHERNET3
    #include "Ethernet3.h"
    #warning Use Ethernet3 lib
    #define SHIELD_TYPE           "W5x00 using Ethernet3 Library"
  #elif USE_ETHERNET2
    #include "Ethernet2.h"
    #warning Use Ethernet2 lib
    #define SHIELD_TYPE           "W5x00 using Ethernet2 Library"
  #elif USE_ETHERNET_LARGE
    #include "EthernetLarge.h"
    #warning Use EthernetLarge lib
    #define SHIELD_TYPE           "W5x00 using EthernetLarge Library"
  #elif USE_ETHERNET_ESP8266
    #include "Ethernet_ESP8266.h"
    #warning Use Ethernet_ESP8266 lib
    #define SHIELD_TYPE           "W5x00 using Ethernet_ESP8266 Library"
  #elif USE_ETHERNET_ENC
    #include "EthernetENC.h"
    #warning Use EthernetENC lib
    #define SHIELD_TYPE           "ENC28J60 using EthernetENC Library"
  #elif USE_CUSTOM_ETHERNET
    #include "Ethernet_XYZ.h"
    #warning Use Custom Ethernet library from EthernetWrapper. You must include a library here or error.
    #define SHIELD_TYPE           "using Custom Ethernet Library"
  #elif USE_UIP_ETHERNET
    #include "UIPEthernet.h"
    #warning Use UIPEthernet library
    #define SHIELD_TYPE           "ENC28J60 using UIPEthernet Library"
  #else
    #ifdef USE_ETHERNET
      #undef USE_ETHERNET
    #endif
    #define USE_ETHERNET          true
    #include "Ethernet.h"
    #warning Use Ethernet lib
    #define SHIELD_TYPE           "W5x00 using Ethernet Library"
  #endif
#endif

/////////////////////////////////

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

#include <EthernetWebServer.h>  
#include <DDNS_Generic.h>

EthernetServer server(80);

// Enter a MAC address and IP address for your controller below.
#define NUMBER_OF_MAC      20

byte mac[][NUMBER_OF_MAC] =
{
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x01 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x02 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x03 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x04 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x05 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x06 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x07 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x08 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x09 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0A },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0B },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0C },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0D },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x0E },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x0F },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x10 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x11 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x12 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x13 },
  { 0xDE, 0xAD, 0xBE, 0xEF, 0xBE, 0x14 },
};

// Select the IP address according to your local network
IPAddress ip(192, 168, 2, 222);

/////////////////////////////////

#endif    //defines_h
