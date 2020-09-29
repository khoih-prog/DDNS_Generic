/****************************************************************************************************************************
  nRF52_WiFiNINA_DuckDNS_Client.ino
   
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

#include "defines.h"

int status = WL_IDLE_STATUS;     // the Wifi radio's status

void onUpdateCallback(const char* oldIP, const char* newIP)
{
  Serial.print(F("DDNSGeneric - IP Change Detected: "));
  Serial.println(newIP);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart nRF52_WiFiNINA_DuckDNS_Client on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));

  if (WiFi.status() == WL_NO_MODULE)
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

  String fv = WiFi.firmwareVersion();
  
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println(F("Please upgrade the firmware"));
  }

  WiFi.begin(ssid, password);
  
  Serial.println("Connecting to WiFi SSID: " + String(ssid));

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.print(F("\nHTTP WebServer is @ IP : "));
  Serial.println(WiFi.localIP());
  
  server.begin();

  DDNSGeneric.service("duckdns");    // Enter your DDNS Service Name - "duckdns" / "noip"

  /*
    For DDNS Providers where you get a token:
    DDNSGeneric.client("domain", "token");

    For DDNS Providers where you get username and password: ( Leave the password field empty "" if not required )
    DDNSGeneric.client("domain", "username", "password");
  */
  DDNSGeneric.client("account.duckdns.org", "12345678-1234-1234-1234-123456789012");

  DDNSGeneric.onUpdate(onUpdateCallback);
}

void loop() 
{
  // Check for New Ip Every 10 mins.
  DDNSGeneric.update(600000);
}
