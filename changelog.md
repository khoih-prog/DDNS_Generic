# DDNS_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/DDNS_Generic.svg?)](https://www.ardu-badge.com/DDNS_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/DDNS_Generic.svg)](https://github.com/khoih-prog/DDNS_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/DDNS_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/DDNS_Generic.svg)](http://github.com/khoih-prog/DDNS_Generic/issues)

---
---

## Table of Contents

* [Changelog](#changelog)
  * [Releases v1.6.1](#releases-v161)
  * [Releases v1.6.0](#releases-v160)
  * [Releases v1.5.1](#releases-v151)
  * [Releases v1.5.0](#releases-v150)
  * [Releases v1.4.0](#releases-v140)
  * [Releases v1.3.0](#releases-v130)
  * [Releases v1.2.0](#releases-v120)
  * [Releases v1.1.0](#releases-v110)
  * [Releases v1.0.1](#releases-v101)
  * [Releases v1.0.0](#releases-v100)

---
---

## Changelog

### Releases v1.6.1

1. Auto detect ESP32 core version. Fix bug in examples for WT32_ETH01

### Releases v1.6.0

1. Replace deprecated `ipv4bot.whatismyipaddress.com` with `ifconfig.me`

### Releases v1.5.1

1. Update `platform.ini` and `library.json` to use original `khoih-prog` instead of `khoih.prog` after PIO fix
2. Update `Packages' Patches`

### Releases v1.5.0

1. Add support to **Portenta_H7**, using either WiFi or Vision-shield Ethernet
2. Add examples with new features

### Releases v1.4.0

1. Add support to **WT32_ETH01 (ESP32 + LAN8720)** boards
2. Add examples with new features

### Releases v1.3.0

1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [Earle Philhower's arduino-pico core](https://github.com/earlephilhower/arduino-pico) and ESP8266/ESP32-AT WiFi
1. Add support to RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) and Ethernet W5x00, ENC28J60.
3. Update examples with new features

### Releases v1.2.0

1. Add support to **Teensy boards** such as **Teensy LC, 3.0, 3.1, 3.2, 3.5, 3.6, 4.0, 4.1** using ESP-AT, WiFiNINA, W5x00 / ENC28J60 Ethernet
2. Add support to **Teensy 4.1 boards** using NativeEthernet


### Releases v1.1.0

1. Add support to **Arduino AVR ATmega2560** such as **Mega, Mega2560, Mega ADK, etc.**
2. Add support to **Arduino ATmega4809** such as **UNO WiFi Rev2, AVR_NANO_EVERY, etc.**
3. Remove dependency on <functional>.
4. Add OVH.com support.
5. Update and add examples for AVR and megaAVR
6. Add Version string
7. Add Table-of-Contents


### Releases v1.0.1

1. Add HTTP_ResponseParser class to fix issue with **nRF52 and STM32F/L/H/G/WB/MP1 using ESP8266/ESP32-AT**.
2. Add support to **Ethernet2, Ethernet3 and EthernetLarge libraries for STM32 using W5x00**.
3. Update Platform.ini to support PlatformIO 5.x owner-based dependency declaration.
4. Add more debug features.

#### Releases v1.0.0

1. Initial coding for Generic boards using many different WiFi/Ethernet modules/shields.
2. Add more examples


