/****************************************************************************************************************************
  defines.h
   
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

#ifndef defines_h
#define defines_h

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             4
#define _WIFININA_LOGLEVEL_         4
#define _DDNS_GENERIC_LOGLEVEL_     2

// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             false    //true
#define DDNS_USING_ETHERNET         true   //true

/////////////////////////////////
  
#if ( defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
        defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || defined(NRF52840_CLUE) || \
        defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )

  #if (DDNS_USING_WIFI) 
    #if defined(WIFI_USE_NRF528XX)
      #undef WIFI_USE_NRF528XX
    #endif
    #define WIFI_USE_NRF528XX          true
    #warning Use NRF52 architecture with WiFi
  #elif DDNS_USING_ETHERNET
    #if defined(ETHERNET_USE_NRF528XX)
      #undef ETHERNET_USE_NRF528XX
    #endif
    // Default pin 10 to SS/CS
    #define USE_THIS_SS_PIN       10
    #define ETHERNET_USE_NRF528XX          true
    #warning Use NRF52 architecture with Ethernet
  #endif
    
#endif

/////////////////////////////////

#if    ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
      || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
      || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
      || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
      || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )
  #if (DDNS_USING_WIFI)
    #if defined(WIFI_USE_SAMD)
      #undef WIFI_USE_SAMD
    #endif
    #define WIFI_USE_SAMD      true
    #warning Use SAMD architecture with WiFi
  #elif DDNS_USING_ETHERNET
    #if defined(ETHERNET_USE_SAMD)
      #undef ETHERNET_USE_SAMD
    #endif
    // For SAMD
    // Default pin 10 to SS/CS
    #define USE_THIS_SS_PIN       10
    #define ETHERNET_USE_SAMD      true
    #warning Use SAMD architecture with Ethernet
  #endif
    
#endif

/////////////////////////////////

#if ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  #if (DDNS_USING_WIFI)
    #if defined(WIFI_USE_SAM_DUE)
      #undef WIFI_USE_SAM_DUE
    #endif
    #define WIFI_USE_SAM_DUE      true
    #warning Use SAM_DUE architecture with WiFi
  #elif DDNS_USING_ETHERNET
    #if defined(ETHERNET_USE_SAM_DUE)
      #undef ETHERNET_USE_SAM_DUE
    #endif
    // Default pin 10 to SS/CS
    #define USE_THIS_SS_PIN       10
    #define ETHERNET_USE_SAM_DUE      true
    #warning Use SAM_DUE architecture with Ethernet
  #endif
#endif

/////////////////////////////////

#if ( defined(STM32F0) || defined(STM32F1) || defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
       defined(STM32L0) || defined(STM32L1) || defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
       defined(STM32WB) || defined(STM32MP1) )

  #if (DDNS_USING_WIFI)
    #if defined(WIFI_USE_STM32)
      #undef WIFI_USE_STM32
    #endif
    #define WIFI_USE_STM32      true
    #warning Use STM32 architecture with WiFi
  #elif DDNS_USING_ETHERNET
    #if defined(ETHERNET_USE_STM32)
      #undef ETHERNET_USE_STM32
    #endif
    // Default pin 10 to SS/CS
    #define USE_THIS_SS_PIN       10
    #define ETHERNET_USE_STM32      true
    #warning Use STM32 architecture with Ethernet
  #endif
  
#endif

/////////////////////////////////

#ifdef CORE_TEENSY
  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10
  #define EspSerial Serial2   //Serial2, Pin RX2 : 7, TX2 : 8
  
  #if defined(__IMXRT1062__)
    // For Teensy 4.1/4.0
    #define BOARD_TYPE      "TEENSY 4.1/4.0"
  #elif defined(__MK66FX1M0__)
    #define BOARD_TYPE "Teensy 3.6"
  #elif defined(__MK64FX512__)
    #define BOARD_TYPE "Teensy 3.5"
  #elif defined(__MKL26Z64__)
    #define BOARD_TYPE "Teensy LC"
  #elif defined(__MK20DX256__)
    #define BOARD_TYPE "Teensy 3.2" // and Teensy 3.1 (obsolete)
  #elif defined(__MK20DX128__)
    #define BOARD_TYPE "Teensy 3.0"
  #elif defined(__AVR_AT90USB1286__)
    #error Teensy 2.0++ not supported yet
  #elif defined(__AVR_ATmega32U4__)
    #error Teensy 2.0 not supported yet
  #else
    // For Other Boards
    #define BOARD_TYPE      "Unknown Teensy Board"
  #endif

#elif defined(WIFI_USE_NRF528XX)  || defined(ETHERNET_USE_NRF528XX)
  // For nRF52
  #define EspSerial Serial1
  
  #if defined(NRF52840_FEATHER)
    #define BOARD_TYPE      "NRF52840_FEATHER_EXPRESS"
  #elif defined(NRF52832_FEATHER)
    #define BOARD_TYPE      "NRF52832_FEATHER"
  #elif defined(NRF52840_FEATHER_SENSE)
    #define BOARD_TYPE      "NRF52840_FEATHER_SENSE"
  #elif defined(NRF52840_ITSYBITSY)
    #define BOARD_TYPE      "NRF52840_ITSYBITSY_EXPRESS"
  #elif defined(NRF52840_CIRCUITPLAY)
    #define BOARD_TYPE      "NRF52840_CIRCUIT_PLAYGROUND"
  #elif defined(NRF52840_CLUE)
    #define BOARD_TYPE      "NRF52840_CLUE"
  #elif defined(NRF52840_METRO)
    #define BOARD_TYPE      "NRF52840_METRO_EXPRESS"
  #elif defined(NRF52840_PCA10056)
    #define BOARD_TYPE      "NORDIC_NRF52840DK"
  #elif defined(NINA_B302_ublox)
    #define BOARD_TYPE      "NINA_B302_ublox"
  #elif defined(NINA_B112_ublox)
    #define BOARD_TYPE      "NINA_B112_ublox"
  #elif defined(PARTICLE_XENON)
    #define BOARD_TYPE      "PARTICLE_XENON"
  #elif defined(MDBT50Q_RX)
    #define BOARD_TYPE      "RAYTAC_MDBT50Q_RX"
  #elif defined(ARDUINO_NRF52_ADAFRUIT)
    #define BOARD_TYPE      "ARDUINO_NRF52_ADAFRUIT"
  #else
    #define BOARD_TYPE      "nRF52 Unknown"
  #endif

#elif defined(WIFI_USE_SAMD) || defined(ETHERNET_USE_SAMD)
  // For SAMD
  #define EspSerial Serial1
  
  #if ( defined(ARDUINO_SAMD_ZERO) && !defined(SEEED_XIAO_M0) )
    #define BOARD_TYPE      "SAMD Zero"
  #elif defined(ARDUINO_SAMD_MKR1000)
    #define BOARD_TYPE      "SAMD MKR1000"
  #elif defined(ARDUINO_SAMD_MKRWIFI1010)
    #define BOARD_TYPE      "SAMD MKRWIFI1010"
  #elif defined(ARDUINO_SAMD_NANO_33_IOT)
    #define BOARD_TYPE      "SAMD NANO_33_IOT"
  #elif defined(ARDUINO_SAMD_MKRFox1200)
    #define BOARD_TYPE      "SAMD MKRFox1200"
  #elif ( defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) )
    #define BOARD_TYPE      "SAMD MKRWAN13X0"
  #elif defined(ARDUINO_SAMD_MKRGSM1400)
    #define BOARD_TYPE      "SAMD MKRGSM1400"
  #elif defined(ARDUINO_SAMD_MKRNB1500)
    #define BOARD_TYPE      "SAMD MKRNB1500"
  #elif defined(ARDUINO_SAMD_MKRVIDOR4000)
    #define BOARD_TYPE      "SAMD MKRVIDOR4000"
  #elif defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS)
    #define BOARD_TYPE      "SAMD ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS"
  #elif defined(ADAFRUIT_FEATHER_M0_EXPRESS)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_FEATHER_M0_EXPRESS"
  #elif defined(ADAFRUIT_METRO_M0_EXPRESS)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_METRO_M0_EXPRESS"
  #elif defined(ADAFRUIT_CIRCUITPLAYGROUND_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_CIRCUITPLAYGROUND_M0"
  #elif defined(ADAFRUIT_GEMMA_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_GEMMA_M0"
  #elif defined(ADAFRUIT_TRINKET_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_TRINKET_M0"
  #elif defined(ADAFRUIT_ITSYBITSY_M0)
    #define BOARD_TYPE      "SAMD21 ADAFRUIT_ITSYBITSY_M0"
  #elif defined(ARDUINO_SAMD_HALLOWING_M0)
    #define BOARD_TYPE      "SAMD21 ARDUINO_SAMD_HALLOWING_M0"
  #elif defined(ADAFRUIT_METRO_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_EXPRESS"
  #elif defined(ADAFRUIT_GRAND_CENTRAL_M4)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_GRAND_CENTRAL_M4"
  #elif defined(ADAFRUIT_FEATHER_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_FEATHER_M4_EXPRESS"
  #elif defined(ADAFRUIT_ITSYBITSY_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_ITSYBITSY_M4_EXPRESS"
  #elif defined(ADAFRUIT_TRELLIS_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_TRELLIS_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYPORTAL)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL"
  #elif defined(ADAFRUIT_PYPORTAL_M4_TITANO)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYPORTAL_M4_TITANO"
  #elif defined(ADAFRUIT_PYBADGE_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_M4_EXPRESS"
  #elif defined(ADAFRUIT_METRO_M4_AIRLIFT_LITE)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_METRO_M4_AIRLIFT_LITE"
  #elif defined(ADAFRUIT_PYGAMER_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYGAMER_ADVANCE_M4_EXPRESS"
  #elif defined(ADAFRUIT_PYBADGE_AIRLIFT_M4)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_PYBADGE_AIRLIFT_M4"
  #elif defined(ADAFRUIT_MONSTER_M4SK_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_MONSTER_M4SK_EXPRESS"
  #elif defined(ADAFRUIT_HALLOWING_M4_EXPRESS)
    #define BOARD_TYPE      "SAMD51 ADAFRUIT_HALLOWING_M4_EXPRESS"
  #elif defined(SEEED_WIO_TERMINAL)
    #define BOARD_TYPE      "SAMD SEEED_WIO_TERMINAL"
  #elif defined(SEEED_FEMTO_M0)
    #define BOARD_TYPE      "SAMD SEEED_FEMTO_M0"
  #elif defined(SEEED_XIAO_M0)
    #define BOARD_TYPE      "SAMD SEEED_XIAO_M0"
    #ifdef USE_THIS_SS_PIN
      #undef USE_THIS_SS_PIN
    #endif
    #define USE_THIS_SS_PIN       A1
    #warning define SEEED_XIAO_M0 USE_THIS_SS_PIN == A1
  #elif defined(Wio_Lite_MG126)
    #define BOARD_TYPE      "SAMD SEEED Wio_Lite_MG126"
  #elif defined(WIO_GPS_BOARD)
    #define BOARD_TYPE      "SAMD SEEED WIO_GPS_BOARD"
  #elif defined(SEEEDUINO_ZERO)
    #define BOARD_TYPE      "SAMD SEEEDUINO_ZERO"
  #elif defined(SEEEDUINO_LORAWAN)
    #define BOARD_TYPE      "SAMD SEEEDUINO_LORAWAN"
  #elif defined(SEEED_GROVE_UI_WIRELESS)
    #define BOARD_TYPE      "SAMD SEEED_GROVE_UI_WIRELESS"
  #elif defined(__SAMD21E18A__)
    #define BOARD_TYPE      "SAMD21E18A"
  #elif defined(__SAMD21G18A__)
    #define BOARD_TYPE      "SAMD21G18A"
  #elif defined(__SAMD51G19A__)
    #define BOARD_TYPE      "SAMD51G19A"
  #elif defined(__SAMD51J19A__)
    #define BOARD_TYPE      "SAMD51J19A"
  #elif defined(__SAMD51P19A__)
    #define BOARD_TYPE      "__SAMD51P19A__"
  #elif defined(__SAMD51J20A__)
    #define BOARD_TYPE      "SAMD51J20A"
  #elif defined(__SAM3X8E__)
    #define BOARD_TYPE      "SAM3X8E"
  #elif defined(__CPU_ARC__)
    #define BOARD_TYPE      "CPU_ARC"
  #elif defined(__SAMD51__)
    #define BOARD_TYPE      "SAMD51"
  #else
    #define BOARD_TYPE      "SAMD Unknown"
  #endif

#elif defined(WIFI_USE_STM32) || defined(ETHERNET_USE_STM32)
  // For STM32
  #warning EspSerial using SERIAL_PORT_HARDWARE, can be Serial or Serial1. See your board variant.h
  #define EspSerial     SERIAL_PORT_HARDWARE    //Serial1
  
  #if defined(STM32F0)
    #warning STM32F0 board selected
    #define BOARD_TYPE  "STM32F0"
  #elif defined(STM32F1)
    #warning STM32F1 board selected
    #define BOARD_TYPE  "STM32F1"
  #elif defined(STM32F2)
    #warning STM32F2 board selected
    #define BOARD_TYPE  "STM32F2"
  #elif defined(STM32F3)
    #warning STM32F3 board selected
    #define BOARD_TYPE  "STM32F3"
  #elif defined(STM32F4)
    #warning STM32F4 board selected
    #define BOARD_TYPE  "STM32F4"
  #elif defined(STM32F7)
    #warning STM32F7 board selected
    #define BOARD_TYPE  "STM32F7"
  #elif defined(STM32L0)
    #warning STM32L0 board selected
    #define BOARD_TYPE  "STM32L0"
  #elif defined(STM32L1)
    #warning STM32L1 board selected
    #define BOARD_TYPE  "STM32L1"
  #elif defined(STM32L4)
    #warning STM32L4 board selected
    #define BOARD_TYPE  "STM32L4"
  #elif defined(STM32H7)
    #warning STM32H7 board selected
    #define BOARD_TYPE  "STM32H7"
  #elif defined(STM32G0)
    #warning STM32G0 board selected
    #define BOARD_TYPE  "STM32G0"
  #elif defined(STM32G4)
    #warning STM32G4 board selected
    #define BOARD_TYPE  "STM32G4"
  #elif defined(STM32WB)
    #warning STM32WB board selected
    #define BOARD_TYPE  "STM32WB"
  #elif defined(STM32MP1)
    #warning STM32MP1 board selected
    #define BOARD_TYPE  "STM32MP1"
  #else
    #warning STM32 unknown board selected
    #define BOARD_TYPE  "STM32 Unknown"
  #endif

#elif ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )
  // For SAM DUE
  #define EspSerial Serial1
  
  #warning SAM DUE board selected
  #define BOARD_TYPE  "SAM DUE"

#elif (ESP8266)
  #warning ESP8266 board selected

#elif (ESP32)
  #warning ESP32 board selected  

#else
  // For Mega
  #error Mega, UNO, Nano, etc. not supported now
  // Default pin 10 to SS/CS
  #define USE_THIS_SS_PIN       10
  #define BOARD_TYPE      "AVR Mega"
#endif    // #ifdef CORE_TEENSY

/////////////////////////////////

#if (ESP8266 || ESP32)

  #ifdef DDNS_USING_WIFI
    #undef DDNS_USING_WIFI
  #endif
  
  #ifdef DDNS_USING_ETHERNET
    #undef DDNS_USING_ETHERNET
  #endif

  #warning Using Built-in ESP WiFi for ESP8266/ESP32

  #define SHIELD_TYPE                 "Built-in ESP WiFi"

  #define DDNS_USING_WIFI             true
  #define DDNS_USING_ETHERNET         false 

#elif ( (DDNS_USING_WIFI) && !(ESP8266 || ESP32) )

  // Select one to be true: USE_WIFI_NINA, DDNS_USING_WIFI_AT or USE_WIFI_CUSTOM
  #define USE_WIFI_NINA         true
  //#define USE_WIFI_NINA         false

  //#define DDNS_USING_WIFI_AT    true
  #define DDNS_USING_WIFI_AT    false
  
  // If not USE_WIFI_NINA, you can USE_WIFI_CUSTOM, then include the custom WiFi library here 
  //#define USE_WIFI_CUSTOM       true
  #define USE_WIFI_CUSTOM       false

  #if !(USE_WIFI_NINA || DDNS_USING_WIFI_AT || USE_WIFI_CUSTOM)
    #error Select either USE_WIFI_NINA || DDNS_USING_WIFI_AT || USE_WIFI_CUSTOM to be true
  #endif

  #if defined(ARDUINO_SAMD_MKR1000)
    #if defined(USE_WIFI_NINA)
      #undef USE_WIFI_NINA
    #endif
    #define USE_WIFI_NINA         false
    #define USE_WIFI101           true
    #define SHIELD_TYPE           "WiFi101"
  #endif

  #if (!USE_WIFI101)
    #if USE_WIFI_NINA
      #warning Using WiFiNINA and WiFiNINA_Generic Library
      #define SHIELD_TYPE                 "WiFiNINA using WiFiNINA_Generic Library"
    #elif DDNS_USING_WIFI_AT
      #warning Using ESP8266-AT/ESP32-AT and ESP8266_AT_WebServer Library
      #define SHIELD_TYPE                 "ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library"        
    #elif USE_WIFI_CUSTOM
      #warning Using Custom WiFi
      #define SHIELD_TYPE                 "Custom WiFi"
      //#include "WiFi_XYZ.h"
      #include "WiFiEspAT.h"
    #endif
  #endif
  
#elif DDNS_USING_ETHERNET

  // This must be true if using LAN8742A for STM32F, such as Nucleo-144 F767ZI
  #define USE_BUILTIN_ETHERNET    false
  //////////
  
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
      #define USE_CUSTOM_ETHERNET   true
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
  #elif USE_BUILTIN_ETHERNET
      #warning Use built-in LAN8742A Library
      #define SHIELD_TYPE           "LAN8742A using STM32Ethernet Library"
  #endif

#endif    // (ESP6288 || ESP32)

/////////////////////////////////

#if ( (DDNS_USING_WIFI) && !(ESP8266 || ESP32) )

  #if DDNS_USING_WIFI_AT
    #include <ESP8266_AT_WebServer.h>
  #else
    #include <WiFiWebServer.h>
  #endif

#elif DDNS_USING_ETHERNET

  #if (ETHERNET_USE_STM32)
    #include <EthernetWebServer_STM32.h>
  #else
    #include <EthernetWebServer.h>
  #endif
#endif

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

#if (DDNS_USING_WIFI)

  #if DDNS_USING_WIFI_AT
    ESP8266_AT_WebServer server(80);
  #else
    WiFiServer server(80);
  #endif

  #include "wifi_credentials.h"

  const char* ssid = SECRET_SSID;
  const char* password = SECRET_PASS;

#elif (DDNS_USING_ETHERNET)

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
#endif

/////////////////////////////////

#endif    //defines_h
