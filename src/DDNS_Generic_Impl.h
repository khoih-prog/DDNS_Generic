/****************************************************************************************************************************
   DDNS_Generic_Impl.h
   
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
               
      DDNS_LOGERROR1("Current Local IP =", new_ip);         
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
          
          DDNS_LOGERROR1("Current Public IP =", new_ip);
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
    }
#endif      
        
    // ######## GENERATE UPDATE URL ######## //
    
    String access_url;
    String access_path;
    bool needAuth = false;
        
    if (ddns_choice == "duckdns") 
    {
      access_url  = "www.duckdns.org";
      access_path = "/update?domains=" + ddns_d + "&token=" + ddns_u + "&ip=" + new_ip + "";
      
      update_url = "http://www.duckdns.org/update?domains=" + ddns_d + "&token=" + ddns_u + "&ip=" + new_ip + "";
    } 
    else if (ddns_choice == "noip") 
    {
      needAuth = true;
      
      access_url  = "dynupdate.no-ip.com";
      access_path = "/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@dynupdate.no-ip.com/nic/update?hostname=" + ddns_d + "&myip=" + new_ip + "";
    } 
    else if (ddns_choice == "dyndns") 
    {
      needAuth = true;
      
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
      needAuth = true;
      
      access_url  = "dyndns.kasserver.com";
      access_path = "/?myip=" + new_ip;
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@dyndns.kasserver.com/?myip=" + new_ip;
    } 
    else if (ddns_choice == "selfhost.de") 
    {
      needAuth = true;
      
      access_url  = "carol.selfhost.de";
      access_path = "/nic/update?";
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@carol.selfhost.de/nic/update?";
    } 
    else if (ddns_choice == "dyndns.it") 
    {
      needAuth = true;
      
      access_url  = "update.dyndns.it";
      access_path = "/nic/update?hostname=" + ddns_d;
      
      update_url = "http://" + ddns_u + ":" + ddns_p + "@update.dyndns.it/nic/update?hostname=" + ddns_d;
    } 
    else if (ddns_choice == "strato") 
    {
      needAuth = true;
      
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
    else 
    {
      DDNS_LOGERROR("## INPUT CORRECT DDNS SERVICE NAME ##");
      return;
    }

    // ######## CHECK & UPDATE ######### //
    if (old_ip != new_ip) 
    {
    
#if (ESP8266 || ESP32)    
      HTTPClient http;
      
      DDNS_LOGERROR1("Sending HTTP_GET to", ddns_choice);
      DDNS_LOGERROR1("HTTP_GET =",  update_url);
      
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
        
        DDNS_LOGERROR1("Updated IP =", old_ip);
      }
      else if (httpCode == -1)
      {
        DDNS_LOGERROR("Public IP not changed. Don't need to update");
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

      DDNS_LOGERROR1("Sending HTTP_GET to", ddns_choice);
      DDNS_LOGERROR1("HTTP_GET =",  update_url);
           
      // @return 200 when Content-Length is set by server
      int httpCode = http.responseStatusCode();
      
      DDNS_LOGERROR1("httpCode =", httpCode);  
      
      if (httpCode == 200 /*HTTP_CODE_OK*/) 
      {
        // Send a callback notification
        if (_ddnsUpdateFunc != nullptr) 
        {
          _ddnsUpdateFunc(old_ip.c_str(), new_ip.c_str());
        }
      
        // Replace Old IP with new one to detect further changes.
        old_ip = new_ip;
        
        DDNS_LOGERROR1("Updated IP =", old_ip); 
      }
      else if (httpCode == -1)
      {
        DDNS_LOGERROR("Public IP not changed. Don't need to update");
      }
      
      http.stop();
#endif      
    }
  }
}

DDNSGenericClass DDNSGeneric;

#endif    // DDNS_Generic_Impl_H
