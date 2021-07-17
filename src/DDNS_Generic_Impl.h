/****************************************************************************************************************************
  DDNS_Generic_Impl.h
   
  For all Generic boards such as ESP8266, ESP32, SAM DUE, SAMD21/SAMD51, nRF52, STM32F/L/H/G/WB/MP1, AVR, megaAVR, Teensy
  with WiFiNINA, ESP8266/ESP32 WiFi, ESP8266-AT, W5x00, ENC28J60, built-in Ethernet LAN8742A, WT32_ETH01

  DDNS_Generic is a library to update DDNS IP address for DDNS services such as 
  duckdns, noip, dyndns, dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, ovh.com

  Based on and modified from 
  1) EasyDDNS            (https://github.com/ayushsharma82/EasyDDNS)
  2) ArduinoHttpClient   (https://github.com/arduino-libraries/ArduinoHttpClient)

  Built by Khoi Hoang https://github.com/khoih-prog/DDNS_Generic

  Licensed under MIT license
  Version: 1.4.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K Hoang      11/09/2020 Initial coding for Generic boards using many WiFi/Ethernet modules/shields.
  1.0.1   K Hoang      28/09/2020 Fix issue with nRF52 and STM32F/L/H/G/WB/MP1 using ESP8266/ESP32-AT
  1.1.0   K Hoang      03/04/2021 Add OVH.com support. Remove dependency on <functional>. Add support to AVR Mega and megaAVR.
  1.2.0   K Hoang      04/04/2021 Add support to Teensy LC, 3.x, 4.0 and 4.1 using Ethernet, NativeEthernet, WiFi or ESP-AT
  1.3.0   K Hoang      15/05/2021 Add support to RP2040 using Ethernet or ESP-AT
  1.4.0   K Hoang      16/07/2021 Add support to WT32_ETH01 (ESP32 + LAN8720)
 *****************************************************************************************************************************/

#ifndef DDNS_Generic_Impl_H
#define DDNS_Generic_Impl_H

void DDNSGenericClass::service(String ddns_service)
{
  ddns_choice = ddns_service;
}

void DDNSGenericClass::client(String ddns_domain, String ddns_username, String ddns_password)
{
  ddns_d = ddns_domain;
  ddns_u = ddns_username;
  ddns_p = ddns_password;
}

#if ( (WIFI_USE_STM32 || WIFI_USE_NRF528XX || WIFI_USE_AVR || WIFI_USE_MEGA_AVR || WIFI_USE_TEENSY || WIFI_USE_RP2040) && DDNS_USING_WIFI_AT )
// this method makes a HTTP connection to the server
String DDNSGenericClass::publicIPRequest(Client& client)
{
  // close any connection before send a new request
  // this will free the socket on the WiFi shield
  client.stop();

  // if there's a successful connection
  if (client.connect(server.c_str(), 80))
  {
    DDNS_LOGINFO1(F("Connecting to "), server);

    client.println("GET / HTTP/1.1");
    client.println("Host: " + server);
    client.println("Connection: close");
    client.println();
  }
  else
  {
    // if you couldn't make a connection
    DDNS_LOGERROR(F("Connection failed"));
  }
  
  String response = "";
  String currentIP;
  
  while ( response.length() == 0 )
  {
    response = "";
    
    // if there are incoming bytes available
    // from the server, read them and print them
    while (client.available())
    {
      char c = client.read();
      response += c;
    }

    if (response.length() > 0)
    {
      HTTP_ResponseParser http = HTTP_ResponseParser();

      int httpCode = http.responseStatusCode(response);

      if (httpCode > 0)
      {
        if (httpCode == 200 /*HTTP_CODE_OK*/)
        {
          currentIP = http.responseBody(response);

          DDNS_LOGDEBUG1(F("Current Public IP = "), currentIP);
        }
      }
    }
  }
  
  client.stop();
  
  return currentIP;
}
#endif

void DDNSGenericClass::update(unsigned long ddns_update_interval, bool use_local_ip)
{
  interval = ddns_update_interval;

  unsigned long currentMillis = millis(); // Calculate Elapsed Time & Trigger

  if (( previousMillis == 0 ) || (currentMillis - previousMillis >= interval))
  {
#if (ESP8266 || ESP32 || DDNS_USING_WIFI)   
   #if DDNS_USING_WIFI_AT
      ESP8266_AT_Client client;
   #else   
      WiFiClient client;
   #endif   
#elif DDNS_USING_ETHERNET
      EthernetClient client;
#else
      WiFiClient client;   
#endif  

    previousMillis = currentMillis;

    if (use_local_ip)
    {
    
#if (ESP8266 || ESP32 || DDNS_USING_WIFI)    
      IPAddress ipAddress = WiFi.localIP();
#elif DDNS_USING_ETHERNET
      IPAddress ipAddress = Ethernet.localIP();
#else
      IPAddress ipAddress = WiFi.localIP();      
#endif

      new_ip = String(ipAddress[0]) + String(".") +
               String(ipAddress[1]) + String(".") +
               String(ipAddress[2]) + String(".") +
               String(ipAddress[3]);
               
      DDNS_LOGINFO1(F("Current Local IP ="), new_ip);         
    } 
    
      
#if (ESP8266 || ESP32)
    else 
    {
      // ######## GET PUBLIC IP ######## //
      
      HTTPClient http;
      http.begin(client, "http://ipv4bot.whatismyipaddress.com/");
      
      // @return -1 if no info or > 0 when Content-Length is set by server
      int httpCode = http.GET();
      
      if (httpCode > 0) 
      {
        if (httpCode == HTTP_CODE_OK) 
        {
          new_ip = http.getString();
          
          DDNS_LOGINFO1(F("Current Public IP ="), new_ip);
        }
      } 
      else 
      {
        http.end();
        
        return;
      }
      
      http.end();
    }
#else

    else 
    {
#if ( (WIFI_USE_STM32 || WIFI_USE_NRF528XX || WIFI_USE_AVR || WIFI_USE_MEGA_AVR || WIFI_USE_TEENSY || WIFI_USE_RP2040) && DDNS_USING_WIFI_AT )
      // To fix issue on nRF52 and STM32 using ESP8266/ESP32-AT
      // ######## GET PUBLIC IP ######## //
      DDNS_LOGDEBUG(F("Calling publicIPRequest"));
       
      new_ip = publicIPRequest(client);
      
      if (new_ip.length() > 0)
        DDNS_LOGERROR1(F("Current Public IP ="), new_ip);
#else

      // ######## GET PUBLIC IP ######## //
      HttpClient http(client, "ipv4bot.whatismyipaddress.com");
      
      DDNS_LOGERROR("Access whatismyipaddress");  
      
      // @return HTTP_CODE_OK (200) if OK and when responseBody is responded by server
      http.get("/");
      
      int httpCode = http.responseStatusCode();
      
      DDNS_LOGERROR1("httpCode =", httpCode);  
      
      if (httpCode > 0)
      {
        if (httpCode == 200 /*HTTP_CODE_OK*/) 
        {     
          String response = http.responseBody();
          new_ip = response;
          
          DDNS_LOGERROR1("Current Public IP =", new_ip);
          DDNS_LOGERROR1("response =", response);      
        }
      } 
      else 
      {
        DDNS_LOGERROR("http.stop");
        
        http.stop();
        
        return;
      }
      
      http.stop();      
      
      
#endif
      
    } 
        
#endif      
        
    // ######## GENERATE UPDATE URL ######## //
    
    String access_url;
    String access_path;
    
#if !(ESP8266 || ESP32)
    bool needAuth;
    
    if ( (ddns_choice == "noip") || (ddns_choice == "dyndns") || (ddns_choice == "all-inkl") || (ddns_choice == "selfhost.de") || 
         (ddns_choice == "dyndns.it") || (ddns_choice == "strato") || (ddns_choice == "ovh") || (ddns_choice == "dyndns.it") )
      needAuth = true;
    else
      needAuth = false;
#endif
        
    if (ddns_choice == "duckdns") 
    {
      access_url  = "www.duckdns.org";
      access_path = "/update?domains=" + ddns_d + "&token=" + ddns_u + "&ip=" + new_ip + "";
      
      update_url = "http://www.duckdns.org/update?domains=" + ddns_d + "&token=" + ddns_u + "&ip=" + new_ip + "";
    } 
    else if (ddns_choice == "noip") 
    {     
      access_url  = "dynupdate.no-ip.com";
      access_path = "/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@dynupdate.no-ip.com/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
    } 
    else if (ddns_choice == "dyndns") 
    {
      access_url  = "members.dyndns.org";
      access_path = "/v3/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@members.dyndns.org/v3/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
    } 
    else if (ddns_choice == "dynu") 
    {
      access_url  = "api.dynu.com";
      access_path = "/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "&username=" + ddns_u + "&password=" + ddns_p + "";
      
      update_url = "http://api.dynu.com/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "&username=" + ddns_u + "&password=" + ddns_p + "";
    } 
    else if (ddns_choice == "enom") 
    {
      access_url  = "dynamic.name-services.com";
      access_path = "/interface.asp?command=SetDnsHost&HostName=" + ddns_d + "&Zone=" + ddns_u + "&DomainPassword=" + ddns_p + "&Address=" + new_ip + "";
      
      update_url = "http://dynamic.name-services.com/interface.asp?command=SetDnsHost&HostName=" + ddns_d + "&Zone=" + ddns_u + "&DomainPassword=" + ddns_p + "&Address=" + new_ip + "";
    } 
    else if (ddns_choice == "all-inkl") 
    {      
      access_url  = "dyndns.kasserver.com";
      access_path = "/?myip=" + new_ip;
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@dyndns.kasserver.com/?myip=" + new_ip;
    } 
    else if (ddns_choice == "selfhost.de") 
    {     
      access_url  = "carol.selfhost.de";
      access_path = "/nic/update?";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@carol.selfhost.de/nic/update?";
    } 
    else if (ddns_choice == "dyndns.it") 
    {     
      access_url  = "update.dyndns.it";
      access_path = "/nic/update?hostname=" + ddns_d;
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@update.dyndns.it/nic/update?hostname=" + ddns_d;
    } 
    else if (ddns_choice == "strato") 
    {      
      access_url  = "dyndns.strato.com";
      access_path = "/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@dyndns.strato.com/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
    } 
    else if (ddns_choice == "freemyip") 
    {
      access_url  = "freemyip.com";
      access_path = "/update?domain=" + ddns_d + "&token=" + ddns_u + "&myip=" + new_ip + "";
      
      update_url = "http://freemyip.com/update?domain=" + ddns_d + "&token=" + ddns_u + "&myip=" + new_ip + "";
    } 
    else if (ddns_choice == "afraid.org") 
    {
      access_url  = "sync.afraid.org";
      access_path = "/u/" + ddns_u + "/";
      
      update_url = "http://sync.afraid.org/u/" + ddns_u + "/";
    }
    else if (ddns_choice == "ovh") 
    {      
      access_url  = "www.ovh.com";
      access_path = "/nic/update?system=dyndns&hostname=" + ddns_d + "&myip=" + new_ip + "";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@www.ovh.com/nic/update?system=dyndns&hostname=" + ddns_d + "&myip=" + new_ip + "";
    }
    else 
    {
      DDNS_LOGERROR(F("## INPUT CORRECT DDNS SERVICE NAME ##"));
      return;
    }

    // ######## CHECK & UPDATE ######### //
    if ( (new_ip.length() > 0) && (old_ip != new_ip) )
    {
    
#if (ESP8266 || ESP32)
      HTTPClient http;
      
      DDNS_LOGWARN1(F("Sending HTTP_GET to"), ddns_choice);
      DDNS_LOGWARN1(F("HTTP_GET ="),  update_url);
      
      http.begin(client, update_url);
      
      // @return HTTP_CODE_OK (200) if OK and when responseBody is responded by server
      int httpCode = http.GET();    
      
      if (httpCode == HTTP_CODE_OK) 
      {
        // Send a callback notification
        if (_ddnsUpdateFunc != nullptr) 
        {
          _ddnsUpdateFunc(old_ip.c_str(), new_ip.c_str());
        }
        
        // Replace Old IP with new one to detect further changes.
        old_ip = new_ip;
        
        DDNS_LOGERROR1(F("Updated IP ="), old_ip);
      }
      else if (httpCode == -1)
      {
        DDNS_LOGERROR(F("Public IP not changed. Don't need to update"));
      }
      
      http.end();
#else
     
      HttpClient http(client, access_url);
      
      if (needAuth)
      {
        http.beginRequest();
        http.get(access_path);
        http.sendBasicAuth(ddns_u, ddns_p); // send the username and password for authentication
        http.endRequest();
      }
      else
      { 
        // @return -1 if no info or > 0 when Content-Length is set by server
        http.get(access_path);
      }

      DDNS_LOGWARN1(F("Sending HTTP_GET to"), ddns_choice);
      DDNS_LOGWARN1(F("HTTP_GET ="),  update_url);
           
      // @return 200 when Content-Length is set by server
      int httpCode = http.responseStatusCode();
      
      DDNS_LOGINFO1(F("httpCode ="), httpCode);  
      
      if (httpCode == 200 /*HTTP_CODE_OK*/) 
      {
        // Send a callback notification
        if (_ddnsUpdateFunc != nullptr) 
        {
          _ddnsUpdateFunc(old_ip.c_str(), new_ip.c_str());
        }
      
        // Replace Old IP with new one to detect further changes.
        old_ip = new_ip;
        
        DDNS_LOGERROR1(F("Updated IP ="), old_ip); 
      }
      else if (httpCode == -1)
      {
        DDNS_LOGERROR(F("Public IP not changed. Don't need to update"));
      }
      
      http.stop();
#endif      
    }
  }
}

DDNSGenericClass DDNSGeneric;

#endif    // DDNS_Generic_Impl_H
