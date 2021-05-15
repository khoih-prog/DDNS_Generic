/****************************************************************************************************************************
  DDNS_Generic.h
   
  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, AVR, megaAVR, Teensy
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, ovh.com

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
  Version: 1.3.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/09/2020 Initial coding for Generic boards using many WiFi/Ethernet modules/shields.
  1.0.1   K Hoang      28/09/2020 Fix issue with nRF52 and STM32F/L/H/G/WB/MP1 using ESP8266/ESP32-AT
  1.1.0   K Hoang      03/04/2021 Add OVH.com support. Remove dependency on <functional>. Add support to AVR Mega and megaAVR.
  1.2.0   K Hoang      04/04/2021 Add support to Teensy LC, 3.x, 4.0 and 4.1 using Ethernet, NativeEthernet, WiFi or ESP-AT
  1.3.0   K Hoang      15/05/2021 Add support to RP2040 using Ethernet or ESP-AT
 *****************************************************************************************************************************/
 
#ifndef DDNS_Generic_H
#define DDNS_Generic_H

#include "Arduino.h"
#include "DDNS_Generic_Debug.h"

#ifndef DDNS_GENERIC_VERSION
  #define DDNS_GENERIC_VERSION       "DDNS_Generic v1.3.0"
#endif

#if ( !defined(DDNS_USING_WIFI) || DDNS_USING_WIFI || !DDNS_USING_ETHERNET)
  #define DDNS_USING_WIFI         true
  #define DDNS_USING_ETHERNET     false
#endif

#if (DDNS_USING_ETHERNET && !(DDNS_USING_WIFI || DDNS_USING_ESP_WIFI))
  #define DDNS_USING_WIFI         false
  #define DDNS_USING_ETHERNET     true
#endif

#if defined(ESP8266)

  #include "ESP8266WiFi.h"
  #include "ESP8266HTTPClient.h"
  #include <WiFiClient.h>
  #define HARDWARE "esp8266"
  
#elif defined(ESP32)

  #include "WiFi.h"
  #include "HTTPClient.h"
  #include <WiFiClient.h>
  #define HARDWARE "esp32"
  
#elif DDNS_USING_WIFI
  //#include "WiFiNINA_Generic.h"
  #include "ArduinoHttpClient.h"
  
  #if ( (WIFI_USE_STM32 || WIFI_USE_NRF528XX || WIFI_USE_AVR || WIFI_USE_MEGA_AVR || WIFI_USE_TEENSY || WIFI_USE_RP2040) && DDNS_USING_WIFI_AT )
    #warning Using HTTP_ResponseParser to fix for ESP8266/ESP32-AT on nRF52/STM32/AVR/megaAVR/Teensy/RP2040
    #include "HTTP_ResponseParser.h"
  #endif
#elif DDNS_USING_ETHERNET

  #include "ArduinoHttpClient.h"

#endif

#if (ESP8266 || ESP32)
  #include "stdlib_noniso.h"
  
#else
  // To support lambda function in class
  //#include <functional>
  
#endif

  // Handler to notify user about new public IP
  //typedef std::function<void(const char* old_ip, const char* new_ip)> DDNSUpdateHandler;
  typedef void (*DDNSUpdateHandler)(const char* old_ip, const char* new_ip);

class DDNSGenericClass 
{
  public:
    void service(String ddns_service);
    void client(String ddns_domain, String ddns_username, String ddns_password = "");
    void update(unsigned long ddns_update_interval, bool use_local_ip = false);

    // Callback
    void onUpdate(DDNSUpdateHandler handler) 
    {
      _ddnsUpdateFunc = handler;
    }
  
  private:
    String publicIPRequest(Client& client);
    
    String server = "ipv4bot.whatismyipaddress.com";
  
    DDNSUpdateHandler _ddnsUpdateFunc = nullptr;
    
    unsigned long interval;
    unsigned long previousMillis = 0;

    String new_ip;
    String old_ip;
    String update_url;
    String ddns_u;
    String ddns_p;
    String ddns_d;
    String ddns_choice;
};

extern DDNSGenericClass DDNSGeneric;

#include "DDNS_Generic_Impl.h"

#endif    // DDNS_Generic_H
