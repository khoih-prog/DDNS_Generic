/****************************************************************************************************************************
  Portenta_H7_Ethernet_DuckDNS_Client.ino
   
  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, AVR, megaAVR, Teensy
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A, WT32_ETH01

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, ovh.com

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
 *****************************************************************************************************************************/

#include "defines.h"

void onUpdateCallback(const char* oldIP, const char* newIP)
{
  Serial.print("DDNSGeneric - IP Change Detected: ");
  Serial.println(newIP);
}

void setup()
{
  Serial.begin(115200);
  while (!Serial);

  Serial.print("\nStart Portenta_H7_Ethernet_DuckDNS_Client on " + String(BOARD_NAME));
  Serial.println(" with " + String(SHIELD_TYPE));
  Serial.println(DDNS_GENERIC_VERSION);
 
  // start the ethernet connection and the server:
  // Use DHCP dynamic IP and random mac
  uint16_t index = millis() % NUMBER_OF_MAC;
  // Use Static IP
  //Ethernet.begin(mac[index], ip);
  Ethernet.begin(mac[index]);

  Serial.print(F("\nHTTP WebServer is @ IP : "));
  Serial.println(Ethernet.localIP());

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
