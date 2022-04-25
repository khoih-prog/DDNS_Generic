# DDNS_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/DDNS_Generic.svg?)](https://www.ardu-badge.com/DDNS_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/DDNS_Generic.svg)](https://github.com/khoih-prog/DDNS_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/DDNS_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/DDNS_Generic.svg)](http://github.com/khoih-prog/DDNS_Generic/issues)

<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this DDNS_Generic library](#why-do-we-need-this-ddns_generic-library)
  * [Features](#features)
  * [Currently Supported Boards](#currently-supported-boards)
  * [Currently Supported WiFi Modules/Shields](#currently-supported-wifi-modulesshields)
  * [Currently Supported Ethernet Modules/Shields](#currently-supported-ethernet-modulesshields)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [Packages' Patches](#packages-patches)
  * [1. For Adafruit nRF52840 and nRF52832 boards](#1-for-adafruit-nRF52840-and-nRF52832-boards)
  * [2. For Teensy boards](#2-for-teensy-boards)
  * [3. For Arduino SAM DUE boards](#3-for-arduino-sam-due-boards)
  * [4. For Arduino SAMD boards](#4-for-arduino-samd-boards)
      * [For core version v1.8.10+](#for-core-version-v1810)
      * [For core version v1.8.9-](#for-core-version-v189-)
  * [5. For Adafruit SAMD boards](#5-for-adafruit-samd-boards)
  * [6. For Seeeduino SAMD boards](#6-for-seeeduino-samd-boards)
  * [7. For STM32 boards](#7-for-stm32-boards) 
    * [7.1. For STM32 boards to use LAN8720](#71-for-stm32-boards-to-use-lan8720)
    * [7.2. For STM32 boards to use Serial1](#72-for-stm32-boards-to-use-serial1)
  * [8. For RP2040-based boards using Earle Philhower arduino-pico core](#8-for-rp2040-based-boards-using-earle-philhower-arduino-pico-core)
    * [8.1. To use BOARD_NAME](#81-to-use-board_name)
    * [8.2. To avoid compile error relating to microsecondsToClockCycles](#82-to-avoid-compile-error-relating-to-microsecondstoclockcycles)
  * [9. For Portenta_H7 boards using Arduino IDE in Linux](#9-for-portenta_h7-boards-using-arduino-ide-in-linux)
  * [10. For RTL8720DN boards using AmebaD core](#10-for-rtl8720dn-boards-using-amebad-core)
  * [11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core](#11-For-SAMD21-and-SAMD51-boards-using-ArduinoCore-fab-sam-core)
  * [12. For Seeeduino RP2040 boards](#12-For-Seeeduino-RP2040-boards)
* [Libraries' Patches](#libraries-patches)
  * [1. For application requiring 2K+ HTML page](#1-for-application-requiring-2k-html-page)
  * [2. For Ethernet library](#2-for-ethernet-library)
  * [3. For EthernetLarge library](#3-for-ethernetlarge-library)
  * [4. For Etherne2 library](#4-for-ethernet2-library)
  * [5. For Ethernet3 library](#5-for-ethernet3-library)
  * [6. For UIPEthernet library](#6-for-uipethernet-library)
  * [7. For fixing ESP32 compile error](#7-for-fixing-esp32-compile-error)
  * [8. For STM32 core F3 and F4 using UIPEthernet library](#8-for-stm32-core-f3-and-f4-using-uipethernet-library)
* [HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)](#howto-use-analogread-with-esp32-running-wifi-andor-bluetooth-btble)
  * [1. ESP32 has 2 ADCs, named ADC1 and ADC2](#1--esp32-has-2-adcs-named-adc1-and-adc2)
  * [2. ESP32 ADCs functions](#2-esp32-adcs-functions)
  * [3. ESP32 WiFi uses ADC2 for WiFi functions](#3-esp32-wifi-uses-adc2-for-wifi-functions)
* [Configuration Notes](#configuration-notes)
  * [1. How to use built-in WiFi in ESP8266/ESP32](#1-how-to-use-built-in-wifi-in-esp8266esp32)
  * [2. How to select which built-in Ethernet or shield to use](#2-how-to-select-which-built-in-ethernet-or-shield-to-use)
  * [3. How to select which built-in WiFi or shield to use](#3-how-to-select-which-built-in-wifi-or-shield-to-use)
  * [Important](#important)
  * [4. How to select another CS/SS pin to use](#4-how-to-select-another-csss-pin-to-use)
  * [5. How to use W5x00 with ESP8266](#5-how-to-use-w5x00-with-esp8266)
  * [6. How to increase W5x00 TX/RX buffer](#6-how-to-increase-w5x00-txrx-buffer)
* [Examples](#examples)
  * [A. For Generic boards and shields](#a-for-generic-boards-and-shields)
    * [ 1. afraid-org_Client](examples/Generic/afraid-org_Client) 
    * [ 2. all-inkl_Client](examples/Generic/all-inkl_Client)
    * [ 3. DuckDNS_Client](examples/Generic/DuckDNS_Client)
    * [ 4. DynDNS_Client](examples/Generic/DynDNS_Client)
    * [ 5. dyndns-it_Client](examples/Generic/dyndns-it_Client)
    * [ 6. Dynu_Client](examples/Generic/Dynu_Client)
    * [ 7. enom_Client](examples/Generic/enom_Client)
    * [ 8. freemyip_Client](examples/Generic/freemyip_Client)
    * [ 9. No-ip_Client](examples/Generic/No-ip_Client)
    * [10. selfhost-de_Client](examples/Generic/selfhost-de_Client)
    * [11. strato_Client](examples/Generic/strato_Client)
    * [12. OVH_Client](examples/Generic/OVH_Client)
  * [B. For Ethernet shields](#b-for-ethernet-shields)
    * [ 1. nRF52_Ethernet_DuckDNS_Client](examples/Ethernet/nRF52/nRF52_Ethernet_DuckDNS_Client)
    * [ 2. SAMD_Ethernet_DuckDNS_Client](examples/Ethernet/SAMD/SAMD_Ethernet_DuckDNS_Client)
    * [ 3. SAM-DUE_Ethernet_DuckDNS_Client](examples/Ethernet/SAM-DUE/SAM-DUE_Ethernet_DuckDNS_Client)
    * [ 4. STM32_Ethernet_DuckDNS_Client](examples/Ethernet/STM32/STM32_Ethernet_DuckDNS_Client)
    * [ 5. AVR_Ethernet_DuckDNS_Client](examples/Ethernet/AVR/AVR_Ethernet_DuckDNS_Client)
    * [ 6. megaAVR_Ethernet_DuckDNS_Client](examples/Ethernet/megaAVR/megaAVR_Ethernet_DuckDNS_Client)
    * [ 7. Teensy_Ethernet_DuckDNS_Client](examples/Ethernet/Teensy/Teensy_Ethernet_DuckDNS_Client)
    * [ 8. RP2040_Ethernet_DuckDNS_Client](examples/Ethernet/RP2040/RP2040_Ethernet_DuckDNS_Client)
    * [ 9. WT32_ETH01_DuckDNS_Client](examples/Ethernet/WT32_ETH01/WT32_ETH01_DuckDNS_Client)
    * [10. Portenta_H7_Ethernet_DuckDNS_Client](examples/Ethernet/Portenta_H7/Portenta_H7_Ethernet_DuckDNS_Client). **New** 
  * [C. For WiFiNINA shields](#c-for-wifinina-shields)
    * [ 1. nRF52_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/nRF52/nRF52_WiFiNINA_DuckDNS_Client)
    * [ 2. SAMD_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/SAMD/SAMD_WiFiNINA_DuckDNS_Client)
    * [ 3. megaAVR_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/megaAVR/megaAVR_WiFiNINA_DuckDNS_Client)
  * [D. For ESP8266-AT/ESP32-AT shields](#d-for-esp8266-atesp32-at-shields)
    * [ 1. nRF52_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/nRF52/nRF52_ESP_AT_DuckDNS_Client)
    * [ 2. SAMD_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/SAMD/SAMD_ESP_AT_DuckDNS_Client)
    * [ 3. SAM-DUE_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/SAM-DUE/SAM-DUE_ESP_AT_DuckDNS_Client)
    * [ 4. STM32_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/STM32/STM32_ESP_AT_DuckDNS_Client)
    * [ 5. AVR_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/AVR/AVR_ESP_AT_DuckDNS_Client).
    * [ 6. megaAVR_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/megaAVR/megaAVR_ESP_AT_DuckDNS_Client)
    * [ 7. Teensy_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/Teensy/Teensy_ESP_AT_DuckDNS_Client)
    * [ 8. RP2040_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/RP2040/RP2040_ESP_AT_DuckDNS_Client)
  * [E. For Portenta_H7 WiFi shields](#e-For-Portenta_H7-WiFi-shields)
    * [ 1. Portenta_H7_DuckDNS_Client](examples/WiFi/Portenta_H7/Portenta_H7_DuckDNS_Client). **New**
* [Example DuckDNS_Client](#example-duckdns_client)
  * [ 1. File DuckDNS_Client.ino](#1-file-duckdns_clientino) 
  * [ 2. File defines.h](#2-file-definesh)
  * [ 3. File wifi_credentials.h](#3-file-wifi_credentialsh)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  *  [1. No-ip_Client on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library](#1-no-ip_client-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a-using-stm32ethernet-library)
  * [ 2. DuckDNS_Client on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library](#2-duckdns_client-on-stm32f7-nucleo-144-nucleo_f767zi-with-lan8742a-using-stm32ethernet-library)
  * [ 3. DuckDNS_Client on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library](#3-duckdns_client-on-adafruit-nrf52840_feather_express-with-w5500-using-Ethernet_Generic-library)
  * [ 4. No-ip_Client on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library](#4-no-ip_client-on-adafruit-nrf52840_feather_express-with-w5500-using-Ethernet_Generic-library)
  * [ 5. DuckDNS_Client on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using new EthernetENC Library](#5-duckdns_client-on-adafruit-nrf52840_feather_express-with-enc28j60-using-new-ethernetenc-library)
  * [ 6. DuckDNS_Client on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using UIPEthernet Library](#6-duckdns_client-on-adafruit-nrf52840_feather_express-with-enc28j60-using-uipethernet-library)
  * [ 7. DuckDNS_Client on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library](#7-duckdns_client-on-adafruit-samd21-samd_nano_33_iot-with-wifinina-using-wifinina_generic-library)
  * [ 8. No-ip_Client on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library](#8-no-ip_client-on-adafruit-samd21-samd_nano_33_iot-with-wifinina-using-wifinina_generic-library)
  * [ 9. DuckDNS_Client on Arduino SAM DUE with W5100 using Ethernet_Generic Library](#9-duckdns_client-on-arduino-sam-due-with-w5100-using-Ethernet_Generic-library)
  * [10. No-ip_Client on Arduino SAM DUE with W5100 using Ethernet_Generic Library](#10-no-ip_client-on-arduino-sam-due-with-w5100-using-Ethernet_Generic-library)
  * [11. DuckDNS_Client on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library](#11-duckdns_client-on-seeedstudio-seeed_xiao_m0-with-esp8266-at-using-esp8266_at_webserver-library)
  * [12. No-ip_Client on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library](#12-no-ip_client-on-seeedstudio-seeed_xiao_m0-with-esp8266-at-using-esp8266_at_webserver-library)
  * [13. AVR_Ethernet_DuckDNS_Client on AVR_MEGA2560 with W5x00 using Ethernet_Generic Library](#13-avr_ethernet_duckdns_client-on-avr_mega2560-with-w5x00-using-Ethernet_Generic-library)
  * [14. Teensy_Ethernet_DuckDNS_Client on TEENSY 4.1 with Custom Ethernet using Teensy 4.1 NativeEthernet Library](#14-teensy_ethernet_duckdns_client-on-teensy-41-with-custom-ethernet-using-teensy-41-nativeethernet-library)
  * [15. RP2040_ESP_AT_DuckDNS_Client on RASPBERRY_PI_PICO with ESP8266-AT using ESP8266_AT_WebServer Library](#15-rp2040_esp_at_duckdns_client-on-raspberry_pi_pico-with-esp8266-at-using-esp8266_at_webserver-library)
  * [16. RP2040_Ethernet_DuckDNS_Client on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library](#16-rp2040_ethernet_duckdns_client-on-mbed-raspberry_pi_pico-with-w5x00-using-Ethernet_Generic-library)
  * [17. DuckDNS_Client on RASPBERRY_PI_PICO with ESP8266-AT using ESP8266_AT_WebServer Library](#17-duckdns_client-on-raspberry_pi_pico-with-esp8266-at-using-esp8266_at_webserver-library)
  * [18. WT32_ETH01_DuckDNS_Client on WT32-ETH01 with ETH_PHY_LAN8720](#18-wt32_eth01_duckdns_client-on-wt32-eth01-with-eth_phy_lan8720)
  * [19. Portenta_H7_Ethernet_DuckDNS_Client on PORTENTA_H7_M7 with Ethernet](#19-Portenta_H7_Ethernet_DuckDNS_Client-on-PORTENTA_H7_M7-with-Ethernet)
  * [20. Portenta_H7_DuckDNS_Client on PORTENTA_H7_M7 with Portenta_H7 WiFi](#20-portenta_h7_duckdns_client-on-portenta_h7_m7-with-portenta_h7-wifi)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [DDNS_Generic library](https://github.com/khoih-prog/DDNS_Generic)

### Features

  Many of us are using [**Dynamic DNS (DDNS) service**](https://en.wikipedia.org/wiki/Dynamic_DNS) because Dynamic IP addresses is much cheaper than the expensive static IP address. 
  
  **Dynamic IP addresses** present a problem if we wants to provide a service to other users on the Internet, such as a web service, **Blynk Local Server**, etc. As the IP address may change frequently (due to power outtage/surge, power on/off, DSL/Fiber issues, etc.), **the corresponding domain names must be quickly re-mapped in the DNS**, to maintain accessibility using a well-known URL.
  
  Many providers offer commercial or **free Dynamic DNS service** for this scenario. The automatic reconfiguration is generally implemented in the user's router or computer, which runs software to update the DDNS service. The communication between the user's equipment and the provider is not standardized, although a few standard web-based methods of updating have emerged over time.
  
  This Library is created to automatically **update your DDNS Domains with the latest dynamic IP address**, using one of the many available boards / shields. See [Currently Supported Boards](https://github.com/khoih-prog/DDNS_Generic#currently-supported-boards).
  
  The time between checks to update the DDNS Service is **configurable** to match your use case, and is set in the examples at 10 minutes.
  
  The [**DDNS_Generic**](https://github.com/khoih-prog/DDNS_Generic) code is very short, can be immersed in your Projects and to be called in the loop() code.
  
  It currently supports **DuckDNS, No-ip, DynDNS, Dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org, OVH.com**. Expansion to support more DDNS sevice providers is very easy and can be done by yourself.
  
  This [**DDNS_Generic library**](https://github.com/khoih-prog/DDNS_Generic) is based on and modified from [**Ayush Sharma's EasyDDNS Library**](https://github.com/ayushsharma82/EasyDDNS) to add support to many boards and shields besides **ESP32 and ESP8266**.

The **RP2040-based boards, such as RASPBERRY_PI_PICO**, are currently supported using :

1. [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico) with ESP8266-AT/ESP32-AT WiFi shields. Ethernet libraries using SPI are not currently supported now on this core.
2. [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) with W5x00, ENC28J60 Ethernet shields. ESP8266-AT/ESP32-AT WiFi shields, using [ESP8266_AT_WebServer library](https://github.com/khoih-prog/ESP8266_AT_WebServer), are not currently supported now on this core.

---

#### Currently Supported Boards

  - **ESP8266**
  - **ESP32**
  - **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox etc.**.
  - **Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)**.
  - **Adafruit SAM21 (Itsy-Bitsy M0, Metro M0, Feather M0, Gemma M0, etc.)**.
  - **Adafruit SAM51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.)**.
  - **Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)**
  - **STM32 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32F1, STM32F3, STM32F4, STM32H7, STM32L0, etc.)**.
  - **SAM DUE**
  - **STM32F/L/H/G/WB/MP1 (Nucleo-64 L053R8,Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 64K+ Flash program memory.**
  - **Arduino ATmega4809-based boards** such as **UNO WiFi Rev2, AVR_NANO_EVERY, etc.**
  - **Arduino AVR ATmega2560** such as **Mega, Mega2560, Mega ADK, etc.**
  - **Teensy LC, 3.0, 3.1, 3.2, 3.5, 3.6, 4.0, 4.1**
  - **RP2040-based boards, such as RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [Earle Philhower's arduino-pico core](https://github.com/earlephilhower/arduino-pico) for ESP8266-AT/ESP32-AT WiFi shields or [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) using W5x00 and ENC28J60 Ethernet shields
  - **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
  - **Portenta_H7** using either `Murata WiFi` or `Vision-shield Ethernet`
    
#### Currently Supported WiFi Modules/Shields

  - **ESP8266 built-in WiFi**
  - **ESP32 built-in WiFi**
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or ESP8266_AT_WebServer library**.
  - **Portenta_H7 built-in Murata WiFi**
  
#### Currently Supported Ethernet Modules/Shields

  - **W5x00 using [Ethernet_Generic](https://github.com/khoih-prog/Ethernet_Generic) library**
  - **W5100S shield /module**, using [`Ethernet_Generic`](https://github.com/khoih-prog/Ethernet_Generic) library, such as [**WIZnet Ethernet HAT**](https://docs.wiznet.io/Product/Open-Source-Hardware/wiznet_ethernet_hat) and [**W5100S-EVB-Pico**](https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico)
  - **ENC28J60 using EthernetENC or UIPEthernet library**
  - **LAN8742A using STM32duino LwIP,STM32duino STM32Ethernet libraries**
  - **NativeEthernet for Teensy 4.1**
  - **LAN8720A in WT32-ETH01** using [`WebServer_WT32_ETH01`](https://github.com/khoih-prog/WebServer_WT32_ETH01).
  - **Portenta_H7** using Ethernet from [Portenta Vision shields](https://store-usa.arduino.cc/products/arduino-portenta-vision-shield-ethernet)

<p align="center">
    <img src="https://github.com/khoih-prog/DDNS_Generic/blob/master/pics/Portenta_Vision.jpg">
</p>

---
---


## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AVR core 1.8.5+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) for AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest). **New**
 3. [`ESP32 Core 2.0.2+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
 4. [`ESP8266 Core 3.0.2+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS.
 5. [`Teensy core 1.56+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0, LC) boards. **New**
 6. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 7. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 8. [`Adafruit SAMD core 1.7.10+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 9. [`Seeeduino SAMD core 1.8.2+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
10. [`Adafruit nRF52 v1.3.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
11. [`Arduino Core for STM32 v2.2.0+`](https://github.com/stm32duino/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. [![GitHub release](https://img.shields.io/github/release/stm32duino/Arduino_Core_STM32.svg)](https://github.com/stm32duino/Arduino_Core_STM32/releases/latest)
12. [`Arduino megaAVR core 1.8.7+`](https://github.com/arduino/ArduinoCore-megaavr/releases) for Arduino megaAVR boards. Use Arduino Board Manager to install.
13. [`Earle Philhower's arduino-pico core v1.13.3+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
14. [`ArduinoCore-mbed mbed_rp2040, mbed_nano, mbed_portenta core 3.0.1+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) **Portenta_H7, RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)

15. [`ArduinoHttpClient v0.4.0+`](https://github.com/arduino-libraries/ArduinoHttpClient).
16. [`Functional-Vlpp library v1.0.2+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
17. Depending on which Ethernet card you're using:
   - [`Ethernet_Generic library v2.1.0+`](https://github.com/khoih-prog/Ethernet_Generic) for W5100, W5200 and W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.  [![GitHub release](https://img.shields.io/github/release/khoih-prog/Ethernet_Generic.svg)](https://github.com/khoih-prog/Ethernet_Generic/releases/latest)
   - [`EthernetENC library v2.0.2+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/jandrassy/EthernetENC.svg)](https://github.com/jandrassy/EthernetENC/releases/latest). **New and Better**
   - [`UIPEthernet library v2.0.11+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60. [![GitHub release](https://img.shields.io/github/release/UIPEthernet/UIPEthernet.svg)](https://github.com/UIPEthernet/UIPEthernet/releases/latest)
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/STM32Ethernet.svg)](https://github.com/stm32duino/STM32Ethernet/releases/latest). To be used with [`LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP) for built-in LAN8742A Ethernet on (Nucleo-144, Discovery). [![GitHub release](https://img.shields.io/github/release/stm32duino/LwIP.svg)](https://github.com/stm32duino/LwIP/releases/latest)
   - [`NativeEthernet Library version stable111+`](https://github.com/vjmuzik/NativeEthernet) for Teensy 4.1 built-in NativeEthernet. **New**
18. [`WiFiNINA_Generic library v1.8.14-3+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc.
19. [`WiFiWebServer library v1.7.0+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
20. [`EthernetWebServer library v2.1.2+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
21. [`EthernetWebServer_STM32 library v1.4.0+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32).
22. [`ESP8266_AT_WebServer library v1.5.3+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer). Using [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer) is mandatory to avoid error while using ESP8266/ESP32-AT shields.
23. [`WebServer_WT32_ETH01 library v1.4.1+`](https://github.com/khoih-prog/WebServer_WT32_ETH01) to use WT32_ETH01 (ESP32 + LAN8720). To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WebServer_WT32_ETH01.svg?)](https://www.ardu-badge.com/WebServer_WT32_ETH01).


---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for `DDNS_Generic`, then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/DDNS_Generic.svg?)](https://www.ardu-badge.com/DDNS_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [DDNS_Generic](https://github.com/khoih-prog/DDNS_Generic) page.
2. Download the latest release `DDNS_Generic-master.zip`.
3. Extract the zip file to `DDNS_Generic-master` directory 
4. Copy whole `DDNS_Generic-master/src` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**DDNS_Generic** library](https://registry.platformio.org/libraries/khoih-prog/DDNS_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/DDNS_Generic/installation). Search for **DDNS_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Packages' Patches

#### 1. For Adafruit nRF52840 and nRF52832 boards

**To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards**, you have to copy the whole [nRF52 Packages_Patches](Packages_Patches/adafruit/hardware/nrf52/1.3.0) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0). 

Supposing the Adafruit nRF52 version is 1.3.0. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/1.3.0/cores/nRF5/Udp.h`**

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Print.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- **`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`**

#### 2. For Teensy boards
 
 **To be able to compile and run on Teensy boards**, you have to copy the files in [**Packages_Patches for Teensy directory**](Packages_Patches/hardware/teensy/avr) into Teensy hardware directory (./arduino-1.8.19/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.19. These files must be copied into the directory:

- `./arduino-1.8.19/hardware/teensy/avr/boards.txt`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-1.8.19/hardware/teensy/avr/cores/teensy4/Stream.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
These files must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy3/Stream.h`
- `./arduino-x.yy.zz/hardware/teensy/avr/cores/teensy4/Stream.h`

#### 3. For Arduino SAM DUE boards
 
 **To be able to compile and run on SAM DUE boards**, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

#### 4. For Arduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD Packages_Patches](Packages_Patches/arduino/hardware/samd/1.8.13) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.13).
 
#### For core version v1.8.10+

Supposing the Arduino SAMD version is 1.8.13. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.13/platform.txt`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.zz/platform.txt`
 
#### For core version v1.8.9-

Supposing the Arduino SAMD version is 1.8.9. These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/1.8.9/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.9/cores/arduino/Arduino.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z

These files must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/samd/x.yy.z/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/x.yy.z/cores/arduino/Arduino.h`***
 
 This is mandatory to fix the ***notorious Arduino SAMD compiler error***. See [Improve Arduino compatibility with the STL (min and max macro)](https://github.com/arduino/ArduinoCore-samd/pull/399)
 
```
 ...\arm-none-eabi\include\c++\7.2.1\bits\stl_algobase.h:243:56: error: macro "min" passed 3 arguments, but takes just 2
     min(const _Tp& __a, const _Tp& __b, _Compare __comp)
```

Whenever the above-mentioned compiler error issue is fixed with the new Arduino SAMD release, you don't need to copy the `Arduino.h` file anymore.

#### 5. For Adafruit SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the whole [Adafruit SAMD Packages_Patches](Packages_Patches/adafruit/hardware/samd/1.7.10) directory into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.7.10). 

Supposing the Adafruit SAMD core version is 1.7.10. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/1.7.10/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 6. For Seeeduino SAMD boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the whole [Seeeduino SAMD Packages_Patches](Packages_Patches/Seeeduino/hardware/samd/1.8.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2). 

Supposing the Seeeduino SAMD core version is 1.8.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/1.8.2/cores/arduino/Print.cpp`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Arduino.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.h`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/cores/arduino/Print.cpp`

#### 7. For STM32 boards

#### 7.1 For STM32 boards to use LAN8720

To use LAN8720 on some STM32 boards 

- **Nucleo-144 (F429ZI, NUCLEO_F746NG, NUCLEO_F746ZG, NUCLEO_F756ZG)**
- **Discovery (DISCO_F746NG)**
- **STM32F4 boards (BLACK_F407VE, BLACK_F407VG, BLACK_F407ZE, BLACK_F407ZG, BLACK_F407VE_Mini, DIYMORE_F407VGT, FK407M1)**

you have to copy the files [stm32f4xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F4xx) and [stm32f7xx_hal_conf_default.h](Packages_Patches/STM32/hardware/stm32/2.2.0/system/STM32F7xx) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system) to overwrite the old files.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F4xx/stm32f4xx_hal_conf_default.h` for STM32F4.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/system/STM32F7xx/stm32f7xx_hal_conf_default.h` for Nucleo-144 STM32F7.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F4xx/stm32f4xx_hal_conf_default.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/system/STM32F7xx/stm32f7xx_hal_conf_default.h


#### 7.2 For STM32 boards to use Serial1

**To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards**, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/2.2.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/2.2.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 2.2.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/2.2.0/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32F7xx/F765Z(G-I)T_F767Z(G-I)T_F777ZIT/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/STM32L0xx/L052R(6-8)T_L053R(6-8)T_L063R8T/NUCLEO_L053R8/variant.h`

#### 8. For RP2040-based boards using [Earle Philhower arduino-pico core](https://github.com/earlephilhower/arduino-pico)

#### 8.1 To use BOARD_NAME

 **To be able to automatically detect and display BOARD_NAME on RP2040-based boards (RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040, GENERIC_RP2040, etc) boards**, you have to copy the file [RP2040 platform.txt](Packages_Patches/rp2040/hardware/rp2040/1.4.0) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0). 

Supposing the rp2040 core version is 1.4.0. This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/platform.txt`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add -DBOARD_NAME="{build.board}" #136](https://github.com/earlephilhower/arduino-pico/pull/136).

#### 8.2 To avoid compile error relating to microsecondsToClockCycles

Some libraries, such as [Adafruit DHT-sensor-library](https://github.com/adafruit/DHT-sensor-library), require the definition of microsecondsToClockCycles(). **To be able to compile and run on RP2040-based boards**, you have to copy the files in [**RP2040 Arduino.h**](Packages_Patches/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h) into rp2040 directory (~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0).

Supposing the rp2040 core version is 1.4.0. This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/1.4.0/cores/rp2040/Arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied to replace:

- `~/.arduino15/packages/rp2040/hardware/rp2040/x.yy.zz/cores/rp2040/Arduino.h`

With core after v1.5.0, this step is not necessary anymore thanks to the PR [Add defs for compatibility #142](https://github.com/earlephilhower/arduino-pico/pull/142).


#### 9. For Portenta_H7 boards using Arduino IDE in Linux

  **To be able to upload firmware to Portenta_H7 using Arduino IDE in Linux (Ubuntu, etc.)**, you have to copy the file [portenta_post_install.sh](Packages_Patches/arduino/hardware/mbed_portenta/3.0.1/portenta_post_install.sh) into mbed_portenta directory (~/.arduino15/packages/arduino/hardware/mbed_portenta/3.0.1/portenta_post_install.sh). 
  
  Then run the following command using `sudo`
  
```
$ cd ~/.arduino15/packages/arduino/hardware/mbed_portenta/3.0.1
$ chmod 755 portenta_post_install.sh
$ sudo ./portenta_post_install.sh
```

This will create the file `/etc/udev/rules.d/49-portenta_h7.rules` as follows:

```
# Portenta H7 bootloader mode UDEV rules

SUBSYSTEMS=="usb", ATTRS{idVendor}=="2341", ATTRS{idProduct}=="035b", GROUP="plugdev", MODE="0666"
```

Supposing the ArduinoCore-mbed core version is 3.0.1. Now only one file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/3.0.1/portenta_post_install.sh`

Whenever a new version is installed, remember to copy this files into the new version directory. For example, new version is x.yy.zz

This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/mbed_portenta/x.yy.zz/portenta_post_install.sh`


#### 10. For RTL8720DN boards using AmebaD core
 
 To avoid compile error relating to PROGMEM, you have to copy the file [Realtek AmebaD core pgmspace.h](Packages_Patches/realtek/hardware/AmebaD/3.1.2/cores/arduino/avr/pgmspace.h) into Realtek AmebaD directory (~/.arduino15/packages/realtek/hardware/AmebaD/3.1.2/cores/arduino/avr/pgmspace.h). 

Supposing the Realtek AmebaD core version is 3.1.2. This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/3.1.2/cores/arduino/avr/pgmspace.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/realtek/hardware/AmebaD/x.yy.zz/cores/arduino/avr/pgmspace.h`


#### 11. For SAMD21 and SAMD51 boards using ArduinoCore-fab-sam core
 
 To avoid compile error relating to SAMD21/SAMD51, you have to copy the file [ArduinoCore-fab-sam core pgmspace.h](Packages_Patches/Fab_SAM_Arduino/hardware/samd/1.6.18-alpha2/boards.txt) into `ArduinoCore-fab-sam` samd directory (~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.6.18-alpha2/boards.txt). 

Supposing the `ArduinoCore-fab-sam` samd core version is 1.6.18-alpha2. This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/1.6.18-alpha2/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Fab_SAM_Arduino/hardware/samd/x.yy.zz/boards.txt`


#### 12. For Seeeduino RP2040 boards
 
 ***To be able to compile, run and automatically detect and display BOARD_NAME on Seeeduino RP2040 (XIAO RP2040, Wio RP2040 Mini) boards***, you have to copy the whole [Seeeduino RP2040 Packages_Patches](Packages_Patches/Seeeduino/hardware/rp2040/2.7.2) directory into Seeeduino samd directory (~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2). 

Supposing the Seeeduino SAMD core version is 2.7.2. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/rp2040/2.7.2/variants/Seeed_XIAO_RP2040/pins_arduino.h`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/boards.txt`
- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/variants/Seeed_XIAO_RP2040/pins_arduino.h`


---
---

### Libraries' Patches

#### Notes: These patches are totally optional and necessary only when you use the related Ethernet library and get certain error or issues.

#### 1. For application requiring 2K+ HTML page

If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

#### 2. For Ethernet library

To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

#### 3. For EthernetLarge library

To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)


#### 4. For Ethernet2 library

To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:

- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

To add UDP Multicast support, necessary for the [**UPnP_Generic library**](https://github.com/khoih-prog/UPnP_Generic):

- [EthernetUdp2.h](LibraryPatches/Ethernet2/src/EthernetUdp2.h)
- [EthernetUdp2.cpp](LibraryPatches/Ethernet2/src/EthernetUdp2.cpp)

#### 5. For Ethernet3 library

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

#### 6. For UIPEthernet library

***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- For [UIPEthernet v2.0.8](https://github.com/UIPEthernet/UIPEthernet)

  - [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
  - [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
  - [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

- For [UIPEthernet v2.0.9](https://github.com/UIPEthernet/UIPEthernet)

  - [UIPEthernet.h](LibraryPatches/UIPEthernet-2.0.9/UIPEthernet.h)
  - [UIPEthernet.cpp](LibraryPatches/UIPEthernet-2.0.9/UIPEthernet.cpp)
  - [Enc28J60Network.h](LibraryPatches/UIPEthernet-2.0.9/utility/Enc28J60Network.h)
  - [Enc28J60Network.cpp](LibraryPatches/UIPEthernet-2.0.9/utility/Enc28J60Network.cpp)

#### 7. For fixing ESP32 compile error

To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

#### 8. For STM32 core F3 and F4 using UIPEthernet library

Check if you need to install the UIPEthernet patch [new STM32 core F3/F4 compatibility](https://github.com/UIPEthernet/UIPEthernet/commit/c6d6519a260166b722b9cee5dd1f0fb2682e6782) to avoid errors `#include HardwareSPI.h` on some STM32 boards (Nucleo-32 F303K8, etc.)

---
---

### HOWTO Use analogRead() with ESP32 running WiFi and/or BlueTooth (BT/BLE)

Please have a look at [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to have more detailed description and solution of the issue.

#### 1.  ESP32 has 2 ADCs, named ADC1 and ADC2

#### 2. ESP32 ADCs functions

- ADC1 controls ADC function for pins **GPIO32-GPIO39**
- ADC2 controls ADC function for pins **GPIO0, 2, 4, 12-15, 25-27**

#### 3.. ESP32 WiFi uses ADC2 for WiFi functions

Look in file [**adc_common.c**](https://github.com/espressif/esp-idf/blob/master/components/driver/adc_common.c#L61)

> In ADC2, there're two locks used for different cases:
> 1. lock shared with app and Wi-Fi:
>    ESP32:
>         When Wi-Fi using the ADC2, we assume it will never stop, so app checks the lock and returns immediately if failed.
>    ESP32S2:
>         The controller's control over the ADC is determined by the arbiter. There is no need to control by lock.
> 
> 2. lock shared between tasks:
>    when several tasks sharing the ADC2, we want to guarantee
>    all the requests will be handled.
>    Since conversions are short (about 31us), app returns the lock very soon,
>    we use a spinlock to stand there waiting to do conversions one by one.
> 
> adc2_spinlock should be acquired first, then adc2_wifi_lock or rtc_spinlock.


- In order to use ADC2 for other functions, we have to **acquire complicated firmware locks and very difficult to do**
- So, it's not advisable to use ADC2 with WiFi/BlueTooth (BT/BLE).
- Use ADC1, and pins GPIO32-GPIO39
- If somehow it's a must to use those pins serviced by ADC2 (**GPIO0, 2, 4, 12, 13, 14, 15, 25, 26 and 27**), use the **fix mentioned at the end** of [**ESP_WiFiManager Issue 39: Not able to read analog port when using the autoconnect example**](https://github.com/khoih-prog/ESP_WiFiManager/issues/39) to work with ESP32 WiFi/BlueTooth (BT/BLE).

---
---

### Configuration Notes

#### 1. How to use built-in WiFi in ESP8266/ESP32

It's taken care automatically.

#### 2. How to select which built-in Ethernet or shield to use

In examples' **defines.h**

1) Define DDNS_USING_ETHERNET == true and DDNS_USING_WIFI == false

```cpp
// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             false
#define DDNS_USING_ETHERNET         true
```

2) To use W5x00 Ethernet, for example using Ethernet_Generic library

```cpp
// This must be true if using LAN8742A for STM32F, such as Nucleo-144 F767ZI
  #define USE_BUILTIN_ETHERNET    false
  //////////
  
  #define USE_UIP_ETHERNET        false
  #define USE_CUSTOM_ETHERNET     false

  // Only one if the following to be true
  #define USE_ETHERNET_GENERIC    true
  #define USE_ETHERNET_ESP8266    false
  #define USE_ETHERNET_ENC        false
```

3) To use ENC28J60 Ethernet, using EthernetENC library (**NEW**)

```cpp
// This must be true if using LAN8742A for STM32F, such as Nucleo-144 F767ZI
  #define USE_BUILTIN_ETHERNET    false
  //////////
  
  #define USE_UIP_ETHERNET        false
  #define USE_CUSTOM_ETHERNET     false

  // Only one if the following to be true
  #define USE_ETHERNET_GENERIC    false
  #define USE_ETHERNET_ESP8266    false
  #define USE_ETHERNET_ENC        true
```

4) To use ENC28J60 Ethernet, using UIPEthernet library

```cpp
// This must be true if using LAN8742A for STM32F, such as Nucleo-144 F767ZI
  #define USE_BUILTIN_ETHERNET    false
  //////////
  
  #define USE_UIP_ETHERNET        true
  #define USE_CUSTOM_ETHERNET     false

  // Only one if the following to be true
  #define USE_ETHERNET_GENERIC    false
  #define USE_ETHERNET_ESP8266    false
  #define USE_ETHERNET_ENC        false
```

5) To use LAN8742A Ethernet, using STM32Ethernet library

```cpp
// This must be true if using LAN8742A for STM32F, such as Nucleo-144 F767ZI
  #define USE_BUILTIN_ETHERNET    true
  //////////
  
  #define USE_UIP_ETHERNET        false
  #define USE_CUSTOM_ETHERNET     false

  // Only one if the following to be true
  #define USE_ETHERNET_GENERIC    false
  #define USE_ETHERNET_ESP8266    false
  #define USE_ETHERNET_ENC        false
```

#### 3. How to select which built-in WiFi or shield to use

In examples' **defines.h**

1) Define DDNS_USING_WIFI == true and DDNS_USING_ETHERNET == false

```cpp
// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             true
#define DDNS_USING_ETHERNET         false
```

2) To use WiFiNINA, with [**WiFiNINA_Generic library**](https://github.com/khoih-prog/WiFiNINA_Generic) => Define USE_WIFI_NINA == true

```cpp
// Select one to be true: USE_WIFI_NINA, DDNS_USING_WIFI_AT or USE_WIFI_CUSTOM
#define USE_WIFI_NINA         true

#define DDNS_USING_WIFI_AT    false

// If not USE_WIFI_NINA, you can USE_WIFI_CUSTOM, then include the custom WiFi library here 
#define USE_WIFI_CUSTOM       false
```

2) To use ESP8266-AT/ESP32-AT WiFi, with [**ESP8266_AT_WebServer library**](https://github.com/khoih-prog/ESP8266_AT_WebServer) => Define USE_WIFI_NINA and USE_WIFI_CUSTOM == false and USE_WIFI_CUSTOM == true

```cpp
// Select one to be true: USE_WIFI_NINA, DDNS_USING_WIFI_AT or USE_WIFI_CUSTOM
#define USE_WIFI_NINA         false

#define DDNS_USING_WIFI_AT    true

// If not USE_WIFI_NINA, you can USE_WIFI_CUSTOM, then include the custom WiFi library here 
#define USE_WIFI_CUSTOM       false
```

3) To use ESP8266-AT/ESP32-AT WiFi, with WiFiEspAT library => Define USE_WIFI_NINA and DDNS_USING_WIFI_AT == false and USE_WIFI_CUSTOM == true

```cpp
// Select one to be true: USE_WIFI_NINA, DDNS_USING_WIFI_AT or USE_WIFI_CUSTOM
#define USE_WIFI_NINA         false

#define DDNS_USING_WIFI_AT    false

// If not USE_WIFI_NINA, you can USE_WIFI_CUSTOM, then include the custom WiFi library here 
#define USE_WIFI_CUSTOM       true

#if USE_WIFI_NINA
  #warning Using WiFiNINA and WiFiNINA_Generic Library
  #define SHIELD_TYPE                 "WiFiNINA using WiFiNINA_Generic Library"
#elif USE_WIFI_CUSTOM
  #warning Using Custom WiFi
  #define SHIELD_TYPE                 "Custom WiFi"
  //#include "WiFi_XYZ.h"
  #include "WiFiEspAT.h"
#endif
```

4) To use some new custom WiFi, with custom WiFi_XYZ library => Define USE_WIFI_NINA == false, DDNS_USING_WIFI_AT == false and USE_WIFI_CUSTOM == true. Then uncomment #include "WiFi_XYZ.h" and comment out #include "WiFiEspAT.h"

```cpp
//#define USE_WIFI_NINA         true
#define USE_WIFI_NINA         false

// If not USE_WIFI_NINA, you can USE_WIFI_CUSTOM, then include the custom WiFi library here 
#define USE_WIFI_CUSTOM       true

#if USE_WIFI_NINA
  #warning Using WiFiNINA and WiFiNINA_Generic Library
  #define SHIELD_TYPE                 "WiFiNINA using WiFiNINA_Generic Library"
#elif USE_WIFI_CUSTOM
  #warning Using Custom WiFi
  #define SHIELD_TYPE                 "Custom WiFi"
  #include "WiFi_XYZ.h"
  //#include "WiFiEspAT.h"
#endif
```

5) To use WiFi101, with custom WiFi101 library on ARDUINO_SAMD_MKR1000 boards

It's taken care automatically with defining DDNS_USING_WIFI == true and DDNS_USING_ETHERNET == false

---

#### Important:

- The ***Ethernet_Shield_W5200, EtherCard, EtherSia  libraries are not supported***. Don't use unless you know how to modify those libraries.
- Requests to support for any future custom Ethernet library will be ignored. ***Use at your own risk***.

---

#### 4. How to select another CS/SS pin to use

The default CS/SS pin is GPIO4(D2) for ESP8266, GPIO22 for ESP32, 10 for all other boards.

If the default pin is not corect, the easiest way is to change is to use 

```cpp
#define USE_ETHERNET_WRAPPER    true
```

then select the CS/SS pin (e.g. 22) to use as follows:

```cpp
// To override the default CS/SS pin. Don't use unless you know exactly which pin to use
#define USE_THIS_SS_PIN   22
```

#### 5. How to use W5x00 with ESP8266

To avoid using the default but not-working Ethernet library of ESP8266, rename the Ethernet.h/cpp to Ethernet_ESP8266.h/cpp to avoid library conflict if you're using the Arduino Ethernet library. The Ethernet2, Ethernet3, EthernetLarge library can be used without conflict.

These pins are tested OK with ESP8266 and W5x00

```cpp
  // For ESP8266
  // Pin                D0(GPIO16)    D1(GPIO5)    D2(GPIO4)    D3(GPIO0)    D4(GPIO2)    D8
  // Ethernet           0                 X            X            X            X        0
  // Ethernet2          X                 X            X            X            X        0
  // Ethernet3          X                 X            X            X            X        0
  // EthernetLarge      X                 X            X            X            X        0
  // Ethernet_ESP8266   0                 0            0            0            0        0
  // D2 is safe to used for Ethernet, Ethernet2, Ethernet3, EthernetLarge libs
  // Must use library patch for Ethernet, EthernetLarge libraries
  //Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (USE_THIS_SS_PIN);

```

#### 6. How to increase W5x00 TX/RX buffer

- For ***Ethernet3*** library only,  use as follows

```cpp
  // Use  MAX_SOCK_NUM = 4 for 4K, 2 for 8K, 1 for 16K RX/TX buffer
  #ifndef ETHERNET3_MAX_SOCK_NUM
    #define ETHERNET3_MAX_SOCK_NUM      4
  #endif
  
  Ethernet.setCsPin (USE_THIS_SS_PIN);
  Ethernet.init (ETHERNET3_MAX_SOCK_NUM);
```

---

### Examples:

#### A. For Generic boards and shields

 1. [afraid-org_Client](examples/Generic/afraid-org_Client)
 2. [all-inkl_Client](examples/Generic/all-inkl_Client)
 3. [DuckDNS_Client](examples/Generic/DuckDNS_Client)
 4. [DynDNS_Client](examples/Generic/DynDNS_Client)
 5. [dyndns-it_Client](examples/Generic/dyndns-it_Client)
 6. [Dynu_Client](examples/Generic/Dynu_Client)
 7. [enom_Client](examples/Generic/enom_Client)
 8. [freemyip_Client](examples/Generic/freemyip_Client)
 9. [No-ip_Client](examples/Generic/No-ip_Client)
10. [selfhost-de_Client](examples/Generic/selfhost-de_Client)
11. [strato_Client](examples/Generic/strato_Client)
12. [OVH_Client](examples/Generic/OVH_Client). **New**

#### B. For Ethernet shields

 1. [nRF52_Ethernet_DuckDNS_Client](examples/Ethernet/nRF52/nRF52_Ethernet_DuckDNS_Client)
 2. [SAMD_Ethernet_DuckDNS_Client](examples/Ethernet/SAMD/SAMD_Ethernet_DuckDNS_Client)
 3. [SAM-DUE_Ethernet_DuckDNS_Client](examples/Ethernet/SAM-DUE/SAM-DUE_Ethernet_DuckDNS_Client)
 4. [STM32_Ethernet_DuckDNS_Client](examples/Ethernet/STM32/STM32_Ethernet_DuckDNS_Client)
 5. [AVR_Ethernet_DuckDNS_Client](examples/Ethernet/AVR/AVR_Ethernet_DuckDNS_Client).
 6. [megaAVR_Ethernet_DuckDNS_Client](examples/Ethernet/megaAVR/megaAVR_Ethernet_DuckDNS_Client).
 7. [Teensy_Ethernet_DuckDNS_Client](examples/Ethernet/Teensy/Teensy_Ethernet_DuckDNS_Client).
 8. [RP2040_Ethernet_DuckDNS_Client](examples/Ethernet/RP2040/RP2040_Ethernet_DuckDNS_Client).
 9. [WT32_ETH01_DuckDNS_Client](examples/Ethernet/WT32_ETH01/WT32_ETH01_DuckDNS_Client).
10. [Portenta_H7_Ethernet_DuckDNS_Client](examples/Ethernet/Portenta_H7/Portenta_H7_Ethernet_DuckDNS_Client). **New** 

#### C. For WiFiNINA shields

 1. [nRF52_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/nRF52/nRF52_WiFiNINA_DuckDNS_Client)
 2. [SAMD_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/SAMD/SAMD_WiFiNINA_DuckDNS_Client)
 3. [megaAVR_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/megaAVR/megaAVR_WiFiNINA_DuckDNS_Client).

#### D. For ESP8266-AT/ESP32-AT shields

 1. [nRF52_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/nRF52/nRF52_ESP_AT_DuckDNS_Client)
 2. [SAMD_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/SAMD/SAMD_ESP_AT_DuckDNS_Client)
 3. [SAM-DUE_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/SAM-DUE/SAM-DUE_ESP_AT_DuckDNS_Client)
 4. [STM32_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/STM32/STM32_ESP_AT_DuckDNS_Client)
 5. [AVR_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/AVR/AVR_ESP_AT_DuckDNS_Client)
 6. [megaAVR_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/megaAVR/megaAVR_ESP_AT_DuckDNS_Client)
 7. [Teensy_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/Teensy/Teensy_ESP_AT_DuckDNS_Client)
 8. [RP2040_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/RP2040/RP2040_ESP_AT_DuckDNS_Client)

#### E. For Portenta_H7 WiFi shields

 1. [Portenta_H7_DuckDNS_Client](examples/WiFi/Portenta_H7/Portenta_H7_DuckDNS_Client). **New**
 
---
---

### Example [DuckDNS_Client](examples/Generic/DuckDNS_Client)

#### 1. File [DuckDNS_Client.ino](examples/Generic/DuckDNS_Client/DuckDNS_Client.ino)

https://github.com/khoih-prog/DDNS_Generic/blob/47e6ea1036bf88fdc3f5b55c5e112b1b729545d0/examples/Generic/DuckDNS_Client/DuckDNS_Client.ino#L19-L141


#### 2. File [defines.h](examples/Generic/DuckDNS_Client/defines.h)

https://github.com/khoih-prog/DDNS_Generic/blob/47e6ea1036bf88fdc3f5b55c5e112b1b729545d0/examples/Generic/DuckDNS_Client/defines.h#L19-L778


#### 3. File [wifi_credentials.h](examples/Generic/DuckDNS_Client/wifi_credentials.h)

https://github.com/khoih-prog/DDNS_Generic/blob/47e6ea1036bf88fdc3f5b55c5e112b1b729545d0/examples/Generic/DuckDNS_Client/wifi_credentials.h#L1-L2

---
---

### Debug Terminal Output Samples

#### 1. [No-ip_Client](examples/Generic/No-ip_Client) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start No-ip_Client on NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library
DDNS_Generic v1.7.0
HTTP WebServer is @ IP : 192.168.2.84
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to noip
[DDNS] HTTP_GET = http://account:password@dynupdate.no-ip.com/nic/update?hostname=hostname.ddns.net&myip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
```

---

#### 2. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start DuckDNS_Client on NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library
DDNS_Generic v1.7.0
HTTP WebServer is @ IP : 192.168.2.84
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 3. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library

```
Start DuckDNS_Client on NRF52840_FEATHER with W5x00 using Ethernet_Generic Library
DDNS_Generic v1.7.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192

HTTP WebServer is @ IP : 192.168.2.97
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 4. [No-ip_Client](examples/Generic/No-ip_Client) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library

Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using Ethernet_Generic Library

```
Start No-ip_Client on NRF52840_FEATHER with W5x00 using Ethernet_Generic Library
DDNS_Generic v1.7.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192

HTTP WebServer is @ IP : 192.168.2.98
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to noip
[DDNS] HTTP_GET = http://account:password@dynupdate.no-ip.com/nic/update?hostname=hostname.ddns.net&myip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 5. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using new EthernetENC Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using new EthernetENC Library

```
Start nRF52_Ethernet_DuckDNS_Client on NRF52840_FEATHER with ENC28J60 using EthernetENC Library
DDNS_Generic v1.7.0
HTTP WebServer is @ IP : 192.168.2.83
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 6. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using UIPEthernet Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using UIPEthernet Library

```
Start DuckDNS_Client on NRF52840_FEATHER with ENC28J60 using UIPEthernet Library
DDNS_Generic v1.7.0
ENC28J60_CONTROL_CS =10
SS =5
SPI_MOSI =25
SPI_MISO =24
SPI_SCK =26

HTTP WebServer is @ IP : 192.168.2.99
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 7. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Start DuckDNS_Client on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
DDNS_Generic v1.7.0
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.83
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 8. [No-ip_Client](examples/Generic/No-ip_Client) on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Start No-ip_Client on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
DDNS_Generic v1.7.0
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.83
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to noip
[DDNS] HTTP_GET = http://account:password@dynupdate.no-ip.com/nic/update?hostname=hostname.ddns.net&myip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 9. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Arduino SAM DUE with W5100 using Ethernet_Generic Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Arduino SAM DUE with W5100 using Ethernet_Generic Library

```
Start DuckDNS_Client on SAM DUE with W5x00 using Ethernet_Generic Library
DDNS_Generic v1.7.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096

HTTP WebServer is @ IP : 192.168.2.94
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 10. [No-ip_Client](examples/Generic/No-ip_Client) on Arduino SAM DUE with W5100 using Ethernet_Generic Library

Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on Arduino SAM DUE with W5100 using Ethernet_Generic Library

```
Start No-ip_Client on SAM DUE with W5x00 using Ethernet_Generic Library
DDNS_Generic v1.7.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096

HTTP WebServer is @ IP : 192.168.2.94
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to noip
[DDNS] HTTP_GET = http://account:password@dynupdate.no-ip.com/nic/update?hostname=hostname.ddns.net&myip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 11. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library

```
Start DuckDNS_Client on SEEED_XIAO_M0 with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library
DDNS_Generic v1.7.0
[ESP_AT] Use ES8266-AT Command
WiFi shield init done
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.101
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=hostname.duckdns.org&token=token&ip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 12. [No-ip_Client](examples/Generic/No-ip_Client) on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library

Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library

```
Start No-ip_Client on SEEED_XIAO_M0 with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library
DDNS_Generic v1.7.0
[ESP_AT] Use ES8266-AT Command
WiFi shield init done
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.101
[DDNS] Access ifconfig.me
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to noip
[DDNS] HTTP_GET = http://account:password@dynupdate.no-ip.com/nic/update?hostname=hostname.ddns.net&myip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 13. [AVR_Ethernet_DuckDNS_Client](examples/Ethernet/AVR/AVR_Ethernet_DuckDNS_Client) on AVR_MEGA2560 with W5x00 using Ethernet_Generic Library

Debug terminal output when running example [AVR_Ethernet_DuckDNS_Client](examples/Ethernet/AVR/AVR_Ethernet_DuckDNS_Client) on AVR_MEGA2560 with W5x00 using Ethernet_Generic Library

```
Start AVR_Ethernet_DuckDNS_Client on AVR_MEGA2560 with W5x00 using Ethernet_Generic Library
DDNS_Generic v1.7.0

HTTP WebServer is @ IP : 192.168.2.99
[DDNS] Access ifconfig.me
Connected
[DDNS] httpCode = 200
HttpClient::responseBody => bodyLength =13
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 14. [Teensy_Ethernet_DuckDNS_Client](examples/Ethernet/Teensy/Teensy_Ethernet_DuckDNS_Client) on TEENSY 4.1 with Custom Ethernet using Teensy 4.1 NativeEthernet Library

Debug terminal output when running example [Teensy_Ethernet_DuckDNS_Client](examples/Ethernet/Teensy/Teensy_Ethernet_DuckDNS_Client) on TEENSY 4.1 with Custom Ethernet using Teensy 4.1 NativeEthernet Library


```
Start Teensy_Ethernet_DuckDNS_Client on TEENSY 4.1 with Custom Ethernet using Teensy 4.1 NativeEthernet Library
DDNS_Generic v1.7.0

HTTP WebServer is @ IP : 192.168.2.102
[DDNS] Access ifconfig.me
Connected
[DDNS] httpCode = 200
HttpClient::responseBody => bodyLength =13
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
DDNSGeneric - IP Change Detected: oldIP = , newIP = aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 15. [RP2040_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/RP2040/RP2040_ESP_AT_DuckDNS_Client) on RASPBERRY_PI_PICO with ESP8266-AT using ESP8266_AT_WebServer Library

Debug terminal output when running example [RP2040_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/RP2040/RP2040_ESP_AT_DuckDNS_Client) on RASPBERRY_PI_PICO with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library

```
Start RP2040_ESP_AT_DuckDNS_Client on RASPBERRY_PI_PICO with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library
DDNS_Generic v1.7.0
[ESP_AT] Use ES8266-AT Command
WiFi shield init done
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.76
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
```

---

#### 16. [RP2040_Ethernet_DuckDNS_Client](examples/Ethernet/RP2040/RP2040_Ethernet_DuckDNS_Client) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

Debug terminal output when running example [RP2040_Ethernet_DuckDNS_Client](examples/Ethernet/RP2040/RP2040_Ethernet_DuckDNS_Client) on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library

```
Start RP2040_Ethernet_DuckDNS_Client on MBED RASPBERRY_PI_PICO with W5x00 using Ethernet_Generic Library
DDNS_Generic v1.7.0
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 5, new ss_pin = 10, W5100Class::ss_pin = 5
W5100::init: W5500, SSIZE =8192

HTTP WebServer is @ IP : 192.168.2.115
[DDNS] Access ifconfig.me
Connected
[DDNS] httpCode = 200
HttpClient::responseBody => bodyLength =14
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 17. [DuckDNS_Client](examples/Generic/DuckDNS_Client) on RASPBERRY_PI_PICO with ESP8266-AT using ESP8266_AT_WebServer Library

Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on RASPBERRY_PI_PICO with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library

```
Start DuckDNS_Client on RASPBERRY_PI_PICO with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library
DDNS_Generic v1.7.0
[ESP_AT] Use ES8266-AT Command
WiFi shield init done
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.76
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
```

---

#### 18. [WT32_ETH01_DuckDNS_Client](examples/Ethernet/WT32_ETH01/WT32_ETH01_DuckDNS_Client) on WT32-ETH01 with ETH_PHY_LAN8720

Debug terminal output when running example [WT32_ETH01_DuckDNS_Client](examples/Ethernet/WT32_ETH01/WT32_ETH01_DuckDNS_Client) on WT32-ETH01 with ETH_PHY_LAN8720

```
Start WT32_ETH01_DuckDNS_Client on WT32-ETH01 with ETH_PHY_LAN8720
WebServer_WT32_ETH01 v1.4.1
DDNS_Generic v1.7.0
ETH MAC: A8:03:2A:A1:61:73, IPv4: 192.168.2.232
FULL_DUPLEX, 100Mbps

HTTP WebServer started @ IP : 192.168.2.232
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 19. [Portenta_H7_Ethernet_DuckDNS_Client](examples/Ethernet/Portenta_H7/Portenta_H7_Ethernet_DuckDNS_Client) on PORTENTA_H7_M7 with Ethernet

Debug terminal output when running example [Portenta_H7_Ethernet_DuckDNS_Client](examples/Ethernet/Portenta_H7/Portenta_H7_Ethernet_DuckDNS_Client) on PORTENTA_H7_M7 with Ethernet using Portenta_Ethernet Library

```
Start Portenta_H7_Ethernet_DuckDNS_Client on PORTENTA_H7_M7 with Ethernet using Portenta_Ethernet Library
DDNS_Generic v1.7.0

HTTP WebServer is @ IP : 192.168.2.132
[DDNS] Access ifconfig.me
Connected
[DDNS] httpCode = 200
HttpClient::responseBody => bodyLength =15
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
```

---

#### 20. [Portenta_H7_DuckDNS_Client](examples/WiFi/Portenta_H7/Portenta_H7_DuckDNS_Client) on PORTENTA_H7_M7 with Portenta_H7 WiFi

Debug terminal output when running example [WT32_ETH01_DuckDNS_Client](examples/Ethernet/WT32_ETH01/WT32_ETH01_DuckDNS_Client) on PORTENTA_H7_M7 with Portenta_H7 WiFi

```
Start Portenta_H7_DuckDNS_Client on PORTENTA_H7_M7 with Portenta_H7 WiFi
DDNS_Generic v1.7.0
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.130
[DDNS] Access ifconfig.me
Connected
[DDNS] httpCode = 200
HttpClient::responseBody => bodyLength =15
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
Connected
[DDNS] Sending HTTP_GET to duckdns
[DDNS] HTTP_GET = http://www.duckdns.org/update?domains=account.duckdns.org&token=12345678-1234-1234-1234-123456789012&ip=aaa.bbb.ccc.ddd
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
==========================================
DDNSGeneric - Public IP : aaa.bbb.ccc.ddd
==========================================
```


---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level (_WIFI_LOGLEVEL_, _WIFININA_LOGLEVEL_ and _DDNS_GENERIC_LOGLEVEL_) from 0 to 4

```cpp
#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             4
#define _WIFININA_LOGLEVEL_         4
#define _DDNS_GENERIC_LOGLEVEL_     2
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---

### Issues

Submit issues to: [DDNS_Generic issues](https://github.com/khoih-prog/DDNS_Generic/issues)


---
---

### TO DO

1. Bug Searching and Killing
2. Support more types of boards using WiFi/Ethernet shields (Teensy, etc.)
3. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia
4. Add support to **RP2040-based boards, such as RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [Earle Philhower's arduino-pico core](https://github.com/earlephilhower/arduino-pico) using W5x00 and ENC28J60 Ethernet shields

---

### DONE

 1. Add support to Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)
 2. Add support to Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.).
 3. Add support to Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.).
 4. Add support to Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.
 5. Add support to SAM DUE.
 6. Add support to Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)
 7. Add support to STM32F/L/H/G/WB/MP1 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 32K+ Flash program memory.
 8. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/khoih-prog/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 9. Add support to LAN8742A using STM32duino LwIP, STM32duino STM32Ethernet libraries
10. Add support to Ethernet ENC28J60, using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) or [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
11. Add support to WiFiNINA using WiFiNINA or [**WiFiNINA_Generic**](https://github.com/khoih-prog/WiFiNINA_Generic) library.
12. Add support to ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or [**ESP8266_AT_WebServer**](https://github.com/khoih-prog/ESP8266_AT_WebServer) library.
13. Add support to Arduino ATmega4809-based boards such as UNO WiFi Rev2, AVR_NANO_EVERY, etc.
14. Add support to Arduino AVR ATmega2560 such as Mega, Mega2560, Mega ADK, etc.
15. Add Version String
16. Add Table-of-Contents
17. Add support to **Teensy boards** such as **Teensy LC, 3.0, 3.1, 3.2, 3.5, 3.6, 4.0, 4.1** using ESP-AT, WiFiNINA, W5x00 / ENC28J60 Ethernet
18. Add support to **Teensy 4.1 boards** using NativeEthernet
19. Add support to **RP2040-based boards, such as RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [Earle Philhower's arduino-pico core](https://github.com/earlephilhower/arduino-pico) for ESP8266-AT/ESP32-AT WiFi shields or [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) for W5x00 and ENC28J60 Ethernet shields
20. Add support to **WT32_ETH01 boards** using ESP32-based boards and LAN8720 Ethernet
21. Add support to **Portenta_H7**, using either `Murata WiFi` or `Vision-shield Ethernet`
22. Replace deprecated `ipv4bot.whatismyipaddress.com` with `ifconfig.me`
23. Use new [Ethernet_Generic library](https://github.com/khoih-prog/Ethernet_Generic) as default for W5x00.
24. Add support to `RP2040` using [`Earle Philhower's arduino-pico` core](https://github.com/earlephilhower/arduino-pico) with either `SPI0` or `SPI1`
25. Add support to WIZNet W5100S, such as  [**WIZnet Ethernet HAT**](https://docs.wiznet.io/Product/Open-Source-Hardware/wiznet_ethernet_hat) and [**W5100S-EVB-Pico**](https://docs.wiznet.io/Product/iEthernet/W5100S/w5100s-evb-pico)



---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [EasyDDNS Library](https://github.com/ayushsharma82/EasyDDNS) originally written for ESP8266/ESP32.
2. Thanks to good work of [Miguel Wisintainer](https://github.com/tcpipchip) for working with, developing, debugging and testing.
3. Thanks to [KKE](https://github.com/kkeonline) to report the issue [IP lookup fail, due to ipv4bot no longer exist #3](https://github.com/khoih-prog/DDNS_Generic/issues/3), leading to new release v1.6.0 to replace deprecated `ipv4bot.whatismyipaddress.com` with `ifconfig.me` 

<table>
  <tr>
    <td align="center"><a href="https://github.com/ayushsharma82"><img src="https://github.com/ayushsharma82.png" width="100px;" alt="ayushsharma82"/><br /><sub><b>⭐️ Ayush Sharma</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>Miguel Wisintainer</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/kkeonline"><img src="https://github.com/kkeonline.png" width="100px;" alt="kkeonline"/><br /><sub><b>KKE</b></sub></a><br /></td>
  </tr> 
</table>

---

### Contributing

If you want to contribute to this project:

- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/DDNS_Generic/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang




