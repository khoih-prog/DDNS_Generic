/****************************************************************************************************************************
  SAMD_WiFiNINA_DuckDNS_Client.ino
   
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

#include "defines.h"

int status = WL_IDLE_STATUS;     // the Wifi radio's status

String myPublicIP = "";

void printPublicIP()
{
  static unsigned long printPublicIP_timeout = 0;

  //KH
#define PRINT_INTERVAL    20000L
  // Print hearbeat every PRINT_INTERVAL (20) seconds.
  if ((millis() > printPublicIP_timeout))
  {
    if (myPublicIP != "")
    {
      Serial.println("==========================================");
      Serial.print("DDNSGeneric - Public IP : ");
      Serial.println(myPublicIP);
      Serial.println("==========================================");
    }
    
    printPublicIP_timeout = millis() + PRINT_INTERVAL;
  }
}

void onUpdateCallback(const char* oldIP, const char* newIP)
{
  myPublicIP = String(newIP); 
  Serial.print("DDNSGeneric - IP Change Detected: ");
  Serial.println(newIP); 
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart SAMD_WiFiNINA_DuckDNS_Client on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));
  Serial.println(DDNS_GENERIC_VERSION);

#if USE_WIFI_NINA
  if (WiFi.status() == WL_NO_MODULE)
#else
  if (WiFi.status() == WL_NO_SHIELD)
#endif  
  {
    Serial.println(F("WiFi shield not present"));
    // don't continue
    while (true);
  }

#if USE_WIFI_NINA
  String fv = WiFi.firmwareVersion();
  
  if (fv < WIFI_FIRMWARE_LATEST_VERSION)
  {
    Serial.println("Please upgrade the firmware");
  }
#endif

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
  printPublicIP();
}
