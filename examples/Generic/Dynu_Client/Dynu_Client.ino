/****************************************************************************************************************************
   Dynu_Client.ino
   
   For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1
   with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A

   DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
   duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org

   Based on and modified from EasyDDNS https://github.com/ayushsharma82/EasyDDNS
   Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic
   Licensed under MIT license
   Version: 1.0.0

   Version Modified By   Date      Comments
   ------- -----------  ---------- -----------
    1.0.0   K Hoang      11/09/2020 Initial coding for Generic boards using many WiFi/Ethernet modules/shields.
 *****************************************************************************************************************************/

#include "defines.h"

#if (ESP8266 || ESP32 || USE_WIFI_NINA || DDNS_USING_WIFI)
int status = WL_IDLE_STATUS;     // the Wifi radio's status
#endif

void onUpdateCallback(const char* oldIP, const char* newIP)
{
  Serial.print("DDNSGeneric - IP Change Detected: ");
  Serial.println(newIP);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart Dynu_Client on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

#if DDNS_USING_WIFI_AT
  // initialize serial for ESP module
  EspSerial.begin(115200);
  // initialize ESP module
  WiFi.init(&EspSerial);

  Serial.println(F("WiFi shield init done"));

#endif

#if (ESP8266 || ESP32)
  WiFi.mode(WIFI_STA);
  
#elif USE_WIFI_NINA
  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }
#elif (DDNS_USING_WIFI)
  if (WiFi.status() == WL_NO_SHIELD)
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  } 
#endif

#if USE_WIFI_NINA
  String fv = WiFi.firmwareVersion();
  
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println("Please upgrade the firmware");
  }
  
#endif

#if DDNS_USING_WIFI

  WiFi.begin(ssid, password);
  
  Serial.println("Connecting to WiFi SSID: " + String(ssid));

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print(F("\nHTTP WebServer is @ IP : "));
  Serial.println(WiFi.localIP());
  
#elif (DDNS_USING_ETHERNET)

  // For other boards, to change if necessary
#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )
  // Must use library patch for Ethernet, Ethernet2, EthernetLarge libraries

  Ethernet.init (USE_THIS_SS_PIN);

#elif USE_ETHERNET3
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #ifndef ETHERNET3_MAX_SOCK_NUM
    #define ETHERNET3_MAX_SOCK_NUM      4
  #endif

  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);

#endif  // #if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )


  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("\nHTTP WebServer is @ IP : "));
  Serial.println(Ethernet.localIP());
  
#endif

  server.begin();

  DDNSGeneric.service("dynu");

  DDNSGeneric.client("hostname","username","password");    // Enter ddns Hostname - Username - Client-key
}

void loop()
{
  // Check for New Ip Every 10 mins.
  DDNSGeneric.update(600000);
}
