# DDNS_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/DDNS_Generic.svg?)](https://www.ardu-badge.com/DDNS_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/DDNS_Generic.svg)](https://github.com/khoih-prog/DDNS_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/DDNS_Generic/blob/master/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/DDNS_Generic.svg)](http://github.com/khoih-prog/DDNS_Generic/issues)

---
---

### Why do we need this [DDNS_Generic library](https://github.com/khoih-prog/DDNS_Generic)

  Many of us are using [Dynamic DNS service](https://en.wikipedia.org/wiki/Dynamic_DNS) because Dynamic IP addresses is much cheaper than the expensive static IP address. 
  
  **Dynamic IP addresses** present a problem if we wants to provide a service to other users on the Internet, such as a web service, **Blynk Local Server**, etc. As the IP address may change frequently (due to power outtage/surge, power on/off, DSL/Fiber issues, etc.), **the corresponding domain names must be quickly re-mapped in the DNS**, to maintain accessibility using a well-known URL.
  
  Many providers offer commercial or **free Dynamic DNS service** for this scenario. The automatic reconfiguration is generally implemented in the user's router or computer, which runs software to update the DDNS service. The communication between the user's equipment and the provider is not standardized, although a few standard web-based methods of updating have emerged over time.
  
  This Library is created to automatically **update your DDNS Domains with the latest dynamic IP address**, using one of the many available boards / shields. See [Currently Supported Boards](https://github.com/khoih-prog/DDNS_Generic#currently-supported-boards).
  
  The time between checks to update the DDNS Service is **configurable** to match your use case, and is set in the examples at 10 minutes.
  
  The DDNS_Generic code is very short, can be immersed in your Projects and to be called in the loop() code.
  
  It currently supports **DuckDNS, No-ip, DynDNS, Dynu, enom, all-inkl, selfhost.de, dyndns.it, strato, freemyip, afraid.org**. Expansion to support more DDNS sevice providers is very easy and can be done by yourself.
  
  This [**DDNS_Generic library**](https://github.com/khoih-prog/DDNS_Generic) is based on and modified from [**Ayush Sharma's EasyDDNS Library**](https://github.com/ayushsharma82/EasyDDNS) to add support to many boards and shields besides **ESP32 and ESP8266**.

---

### Releases v1.0.0

1. Initial coding for Generic boards using many different WiFi/Ethernet modules/shields.
2. Add more examples

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
  
#### Currently Supported WiFi Modules/Shields

  - **ESP8266 built-in WiFi**
  - **ESP32 built-in WiFi**
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or ESP8266_AT_WebServer library**.
  
#### Currently Supported Ethernet Modules/Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC or UIPEthernet library**
  - **LAN8742A using STM32duino LwIP,STM32duino STM32Ethernet libraries**
  
---
---

## Prerequisite

 1. [`Arduino IDE 1.8.12+` for Arduino](https://www.arduino.cc/en/Main/Software)
 2. [`Arduino AVR core 1.8.3+`](https://github.com/arduino/ArduinoCore-avr) for Arduino AVR boards. Use Arduino Board Manager to install.
 3. [`ESP32 core 1.0.4+`](https://github.com/espressif/arduino-esp32/releases) for ESP32 boards
 4. [`ESP8266 core 2.7.3+` for Arduino](https://github.com/esp8266/Arduino#installing-with-boards-manager) for ESP8266 boards. To use ESP8266 core 2.7.1+ for LittleFS.
 5. [`Teensy core 1.53+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. **Not ready in v1.0.0.**
 6. [`Arduino SAM DUE core 1.6.12+`](https://www.arduino.cc/en/Guide/ArduinoDue) for SAM DUE ARM Cortex-M3 boards
 7. [`Arduino SAMD core 1.8.8+`](https://www.arduino.cc/en/Guide/ArduinoM0) for SAMD ARM Cortex-M0+ boards (Nano 33 IoT, etc.).
 8. [`Adafruit SAMD core 1.6.0+`](https://www.adafruit.com/) for SAMD ARM Cortex-M0+ and M4 boards (Itsy-Bitsy M4, etc.)
 9. [`Adafruit nRF52 v0.20.5+`](https://www.adafruit.com/) for nRF52 boards such as AdaFruit Feather nRF52840 Express, NINA_B302_ublox, etc.
10. [`Arduino Core for STM32 v1.9.0+`](https://github.com/khoih-prog/Arduino_Core_STM32) for STM32F/L/H/G/WB/MP1 boards. To install go to Arduino IDE, select Boards Manager, search for **`STM32`**
11. [`Seeeduino SAMD core 1.7.8+`](https://www.seeedstudio.com/) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.)
12. [`ArduinoHttpClient v0.4.0+`](https://github.com/arduino-libraries/ArduinoHttpClient).
13. [`Functional-VLPP library v1.0.1+`](https://github.com/khoih-prog/functional-vlpp) to use server's lambda function. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Functional-Vlpp.svg?)](https://www.ardu-badge.com/Functional-Vlpp)
14. Depending on which Ethernet card you're using:
   - [`Ethernet library v2.0.0+`](https://www.arduino.cc/en/Reference/Ethernet) for W5100, W5200 and W5500.
   - [`Ethernet2 library v1.0.4+`](https://github.com/khoih-prog/Ethernet2) for W5500 (Deprecated, use Arduino Ethernet library).
   - [`Ethernet3 library v1.5.3+`](https://github.com/sstaub/Ethernet3) for W5500/WIZ550io/WIZ850io/USR-ES1 with Wiznet W5500 chip.
   - [`EthernetLarge library v2.0.0+`](https://github.com/OPEnSLab-OSU/EthernetLarge) for W5100, W5200 and W5500.
   - [`EthernetENC library v2.0.0+`](https://github.com/jandrassy/EthernetENC) for ENC28J60. **New**
   - [`UIPEthernet library v2.0.8+`](https://github.com/UIPEthernet/UIPEthernet) for ENC28J60.
   - [`STM32Ethernet library v1.2.0+`](https://github.com/stm32duino/STM32Ethernet) for built-in Ethernet LAN8742A on (Nucleo-144, Discovery). To be used with [`STM32duino_LwIP library v2.1.2+`](https://github.com/stm32duino/LwIP).
15. [`WiFiNINA_Generic library v1.7.1+`](https://github.com/khoih-prog/WiFiNINA_Generic) to use WiFiNINA modules/shields. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiNINA_Generic.svg?)](https://www.ardu-badge.com/WiFiNINA_Generic) if using WiFiNINA for boards such as Nano 33 IoT, nRF52, Teensy, etc.
16. [`WiFiWebServer library v1.0.6+`](https://github.com/khoih-prog/WiFiWebServer) to use WiFi/WiFiNINA modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/WiFiWebServer.svg?)](https://www.ardu-badge.com/WiFiWebServer)
17. [`EthernetWebServer library v1.0.11+`](https://github.com/khoih-prog/EthernetWebServer) to use Ethernet modules/shields on boards other than STM32F/L/H/G/WB/MP1. To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer.svg?)](https://www.ardu-badge.com/EthernetWebServer).
18. [`EthernetWebServer_STM32 library v1.0.4+`](https://github.com/khoih-prog/EthernetWebServer_STM32) to use Ethernet modules/shields on STM32F/L/H/G/WB/MP1 boards. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/EthernetWebServer_STM32.svg?)](https://www.ardu-badge.com/EthernetWebServer_STM32).
19. [`ESP8266_AT_WebServer library v1.0.12+`](https://github.com/khoih-prog/ESP8266_AT_WebServer) to use ESP8266-AT/ESP32-AT WiFi modules/shields. To install, check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP8266_AT_WebServer.svg?)](https://www.ardu-badge.com/ESP8266_AT_WebServer)

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

### VS Code & PlatformIO:
1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install **DDNS_Generic** library by using [Library Manager](https://docs.platformio.org/en/latest/librarymanager/). Search for DDNS_Generic in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)


---

### Packages' Patches

 1. ***To be able to compile, run and automatically detect and display BOARD_NAME on nRF52840/nRF52832 boards***, you have to copy the whole [nRF52 0.20.5](Packages_Patches/adafruit/hardware/nrf52/0.20.5) directory into Adafruit nRF52 directory (~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5). 

Supposing the Adafruit nRF52 version is 0.20.5. These files must be copied into the directory:
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/variants/NINA_B112_ublox/variant.cpp`
- ***`~/.arduino15/packages/adafruit/hardware/nrf52/0.20.5/cores/nRF5/Udp.h`***

Whenever a new version is installed, remember to copy these files into the new version directory. For example, new version is x.yy.z
These files must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/platform.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/boards.txt`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B302_ublox/variant.cpp`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.h`
- `~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/variants/NINA_B112_ublox/variant.cpp`
- ***`~/.arduino15/packages/adafruit/hardware/nrf52/x.yy.z/cores/nRF5/Udp.h`***

 2. ***To be able to compile and run on Teensy boards***, you have to copy the file [Teensy boards.txt](Packages_Patches/hardware/teensy/avr/boards.txt) into Teensy hardware directory (./arduino-1.8.12/hardware/teensy/avr/boards.txt). 

Supposing the Arduino version is 1.8.12. This file must be copied into the directory:

- `./arduino-1.8.12/hardware/teensy/avr/boards.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `./arduino-x.yy.zz/hardware/teensy/avr/boards.txt`

 3. ***To be able to compile and run on SAM DUE boards***, you have to copy the whole [SAM DUE](Packages_Patches/arduino/hardware/sam/1.6.12) directory into Arduino sam directory (~/.arduino15/packages/arduino/hardware/sam/1.6.12). 

Supposing the Arduino SAM core version is 1.6.12. This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/1.6.12/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/arduino/hardware/sam/x.yy.zz/platform.txt`

 4. ***To be able to compile without error and automatically detect and display BOARD_NAME on Arduino SAMD (Nano-33-IoT, etc) boards***, you have to copy the whole [Arduino SAMD cores 1.8.8](Packages_Patches/arduino/hardware/samd/1.8.8) directory into Arduino SAMD directory (~/.arduino15/packages/arduino/hardware/samd/1.8.8).
 
Supposing the Arduino SAMD version is 1.8.8. These files must be copied into the directory:
- `~/.arduino15/packages/arduino/hardware/samd/1.8.8/platform.txt`
- ***`~/.arduino15/packages/arduino/hardware/samd/1.8.8/cores/arduino/Arduino.h`***

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

 5. ***To be able to automatically detect and display BOARD_NAME on Adafruit SAMD (Itsy-Bitsy M4, etc) boards***, you have to copy the file [Adafruit SAMD platform.txt](Packages_Patches/adafruit/hardware/samd/1.6.0) into Adafruit samd directory (~/.arduino15/packages/adafruit/hardware/samd/1.6.0). 

Supposing the Adafruit SAMD core version is 1.6.0. This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/1.6.0/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/adafruit/hardware/samd/x.yy.zz/platform.txt`

 6. ***To be able to automatically detect and display BOARD_NAME on Seeeduino SAMD (XIAO M0, Wio Terminal, etc) boards***, you have to copy the file [Seeeduino SAMD platform.txt](Packages_Patches/Seeeduino/hardware/samd/1.7.8) into Adafruit samd directory (~/.arduino15/packages/Seeeduino/hardware/samd/1.7.8). 

Supposing the Seeeduino SAMD core version is 1.7.8. This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/1.7.8/platform.txt`

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz
This file must be copied into the directory:

- `~/.arduino15/packages/Seeeduino/hardware/samd/x.yy.zz/platform.txt`

7. ***To use Serial1 on some STM32 boards without Serial1 definition (Nucleo-144 NUCLEO_F767ZI, Nucleo-64 NUCLEO_L053R8, etc.) boards***, you have to copy the files [STM32 variant.h](Packages_Patches/STM32/hardware/stm32/1.9.0) into STM32 stm32 directory (~/.arduino15/packages/STM32/hardware/stm32/1.9.0). You have to modify the files corresponding to your boards, this is just an illustration how to do.

Supposing the STM32 stm32 core version is 1.9.0. These files must be copied into the directory:

- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_F767ZI/variant.h` for Nucleo-144 NUCLEO_F767ZI.
- `~/.arduino15/packages/STM32/hardware/stm32/1.9.0/variants/NUCLEO_L053R8/variant.h` for Nucleo-64 NUCLEO_L053R8.

Whenever a new version is installed, remember to copy this file into the new version directory. For example, new version is x.yy.zz,
theses files must be copied into the corresponding directory:

- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_F767ZI/variant.h`
- `~/.arduino15/packages/STM32/hardware/stm32/x.yy.zz/variants/NUCLEO_L053R8/variant.h`

---

### Libraries' Patches

1. If your application requires 2K+ HTML page, the current [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) must be modified if you are using W5200/W5500 Ethernet shields. W5100 is not supported for 2K+ buffer. If you use boards requiring different CS/SS pin for W5x00 Ethernet shield, for example ESP32, ESP8266, nRF52, etc., you also have to modify the following libraries to be able to specify the CS/SS pin correctly.

2. To fix [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet), just copy these following files into the [`Ethernet library`](https://www.arduino.cc/en/Reference/Ethernet) directory to overwrite the old files:
- [Ethernet.h](LibraryPatches/Ethernet/src/Ethernet.h)
- [Ethernet.cpp](LibraryPatches/Ethernet/src/Ethernet.cpp)
- [EthernetServer.cpp](LibraryPatches/Ethernet/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/Ethernet/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/Ethernet/src/utility/w5100.cpp)

3. To fix [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge), just copy these following files into the [`EthernetLarge library`](https://github.com/OPEnSLab-OSU/EthernetLarge) directory to overwrite the old files:
- [EthernetLarge.h](LibraryPatches/EthernetLarge/src/EthernetLarge.h)
- [EthernetLarge.cpp](LibraryPatches/EthernetLarge/src/EthernetLarge.cpp)
- [EthernetServer.cpp](LibraryPatches/EthernetLarge/src/EthernetServer.cpp)
- [w5100.h](LibraryPatches/EthernetLarge/src/utility/w5100.h)
- [w5100.cpp](LibraryPatches/EthernetLarge/src/utility/w5100.cpp)

4. To fix [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2), just copy these following files into the [`Ethernet2 library`](https://github.com/khoih-prog/Ethernet2) directory to overwrite the old files:
- [Ethernet2.h](LibraryPatches/Ethernet2/src/Ethernet2.h)
- [Ethernet2.cpp](LibraryPatches/Ethernet2/src/Ethernet2.cpp)

5. To fix [`Ethernet3 library`](https://github.com/sstaub/Ethernet3), just copy these following files into the [`Ethernet3 library`](https://github.com/sstaub/Ethernet3) directory to overwrite the old files:
- [Ethernet3.h](LibraryPatches/Ethernet3/src/Ethernet3.h)
- [Ethernet3.cpp](LibraryPatches/Ethernet3/src/Ethernet3.cpp)

6. ***To be able to compile and run on nRF52 boards with ENC28J60 using UIPEthernet library***, you have to copy these following files into the UIPEthernet `utility` directory to overwrite the old files:

- [UIPEthernet.h](LibraryPatches/UIPEthernet/UIPEthernet.h)
- [UIPEthernet.cpp](LibraryPatches/UIPEthernet/UIPEthernet.cpp)
- [Enc28J60Network.h](LibraryPatches/UIPEthernet/utility/Enc28J60Network.h)
- [Enc28J60Network.cpp](LibraryPatches/UIPEthernet/utility/Enc28J60Network.cpp)

7. To fix [`ESP32 compile error`](https://github.com/espressif/arduino-esp32), just copy the following file into the [`ESP32`](https://github.com/espressif/arduino-esp32) cores/esp32 directory (e.g. ./arduino-1.8.12/hardware/espressif/cores/esp32) to overwrite the old file:
- [Server.h](LibraryPatches/esp32/cores/esp32/Server.h)

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
#define DDNS_USING_WIFI             false    //true
#define DDNS_USING_ETHERNET         true   //true
```

2) To use W5x00 Ethernet, for example using EthernetLarge library

```cpp
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
```

3) To use ENC28J60 Ethernet, using EthernetENC library (**NEW**)

```cpp
// This must be true if using LAN8742A for STM32F, such as Nucleo-144 F767ZI
  #define USE_BUILTIN_ETHERNET    false
  //////////
  
  #define USE_UIP_ETHERNET        false
  #define USE_CUSTOM_ETHERNET     false

  // Only one if the following to be true
  #define USE_ETHERNET            false
  #define USE_ETHERNET2           false //true
  #define USE_ETHERNET3           false //true
  #define USE_ETHERNET_LARGE      false
  #define USE_ETHERNET_ESP8266    false //true
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
  #define USE_ETHERNET            false
  #define USE_ETHERNET2           false //true
  #define USE_ETHERNET3           false //true
  #define USE_ETHERNET_LARGE      false
  #define USE_ETHERNET_ESP8266    false //true
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
  #define USE_ETHERNET            false
  #define USE_ETHERNET2           false //true
  #define USE_ETHERNET3           false //true
  #define USE_ETHERNET_LARGE      false
  #define USE_ETHERNET_ESP8266    false //true
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

2) To use WiFiNINA, with WiFiNINA_Generic library => Define USE_WIFI_NINA == true

```cpp
// Select one to be true: USE_WIFI_NINA, DDNS_USING_WIFI_AT or USE_WIFI_CUSTOM
#define USE_WIFI_NINA         true

#define DDNS_USING_WIFI_AT    false

// If not USE_WIFI_NINA, you can USE_WIFI_CUSTOM, then include the custom WiFi library here 
#define USE_WIFI_CUSTOM       false
```

2) To use ESP8266-AT/ESP32-AT WiFi, with ESP8266_ATWebServer library => Define USE_WIFI_NINA and USE_WIFI_CUSTOM == false and USE_WIFI_CUSTOM == true

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

#### B. For Ethernet shields

12. [nRF52_Ethernet_DuckDNS_Client](examples/Ethernet/nRF52/nRF52_Ethernet_DuckDNS_Client)
13. [SAMD_Ethernet_DuckDNS_Client](examples/Ethernet/SAMD/SAMD_Ethernet_DuckDNS_Client)
14. [SAM-DUE_Ethernet_DuckDNS_Client](examples/Ethernet/SAM-DUE/SAM-DUE_Ethernet_DuckDNS_Client)
15. [STM32_Ethernet_DuckDNS_Client](examples/Ethernet/STM32/STM32_Ethernet_DuckDNS_Client)

#### C. For WiFiNINA shields

16. [nRF52_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/nRF52/nRF52_WiFiNINA_DuckDNS_Client)
17. [SAMD_WiFiNINA_DuckDNS_Client](examples/WiFiNINA/SAMD/SAMD_WiFiNINA_DuckDNS_Client)

#### D. For ESP8266-AT/ESP32-AT shields

18. [nRF52_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/nRF52/nRF52_ESP_AT_DuckDNS_Client)
19. [SAMD_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/SAMD/SAMD_ESP_AT_DuckDNS_Client)
20. [SAM-DUE_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/SAM-DUE/SAM-DUE_ESP_AT_DuckDNS_Client)
21. [STM32_ESP_AT_DuckDNS_Client](examples/ESP_AT_WiFi/STM32/STM32_ESP_AT_DuckDNS_Client)

---
---

### Example [DuckDNS_Client](examples/Generic/DuckDNS_Client)

#### 1. File [DuckDNS_Client.ino](examples/Generic/DuckDNS_Client/DuckDNS_Client.ino)


```cpp
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

  Serial.print("\nStart DuckDNS_Client on " + String(BOARD_NAME));
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

#endif  //#if ( USE_ETHERNET || USE_ETHERNET_LARGE || USE_ETHERNET2 || USE_ETHERNET_ENC )

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
```

#### 2. File [defines.h](examples/Generic/DuckDNS_Client/defines.h)


```cpp
#ifndef defines_h
#define defines_h

#define DEBUG_WIFI_WEBSERVER_PORT   Serial

// Debug Level from 0 to 4
#define _WIFI_LOGLEVEL_             4
#define _WIFININA_LOGLEVEL_         4
#define _DDNS_GENERIC_LOGLEVEL_     2

// Select DDNS_USING_WIFI for boards using built-in WiFi, such as Nano-33-IoT
#define DDNS_USING_WIFI             true    //true
#define DDNS_USING_ETHERNET         false   //true

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
  #define USE_ETHERNET_LARGE      false
  #define USE_ETHERNET_ESP8266    false //true
  #define USE_ETHERNET_ENC        true

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
```

#### 3. File [wifi_credentials.h](examples/Generic/DuckDNS_Client/wifi_credentials.h)


```cpp
#define SECRET_SSID     "your_ssid"
#define SECRET_PASS     "your_pass"
```

---
---

### Debug Termimal Output Samples

#### 1. Debug terminal output when running example [No-ip_Client](examples/No-ip_Client) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start No-ip_Client on NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

HTTP WebServer is @ IP : 192.168.2.84
[DDNS] Access whatismyipaddress
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
[DDNS] Sending HTTP_GET to noip
[DDNS] HTTP_GET = http://account:password@dynupdate.no-ip.com/nic/update?hostname=hostname.ddns.net&myip=aaa.bbb.ccc.ddd
[DDNS] httpCode = 200
DDNSGeneric - IP Change Detected: aaa.bbb.ccc.ddd
[DDNS] Updated IP = aaa.bbb.ccc.ddd
[DDNS] Access whatismyipaddress
[DDNS] httpCode = 200
[DDNS] Current Public IP = aaa.bbb.ccc.ddd
[DDNS] response = aaa.bbb.ccc.ddd
```

---

#### 2. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on STM32F7 Nucleo-144 NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

```
Start DuckDNS_Client on NUCLEO_F767ZI with LAN8742A using STM32Ethernet Library

HTTP WebServer is @ IP : 192.168.2.84
[DDNS] Access whatismyipaddress
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

#### 3. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using EthernetLarge Library

```
Start DuckDNS_Client on NRF52840_FEATHER with W5x00 using EthernetLarge Library
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192

HTTP WebServer is @ IP : 192.168.2.97
[DDNS] Access whatismyipaddress
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

#### 4. Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on Adafruit NRF52840_FEATHER_EXPRESS with W5500 using EthernetLarge Library

```
Start No-ip_Client on NRF52840_FEATHER with W5x00 using EthernetLarge Library
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5500, SSIZE =8192

HTTP WebServer is @ IP : 192.168.2.98
[DDNS] Access whatismyipaddress
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

#### 5. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using new EthernetENC Library

```
Start nRF52_Ethernet_DuckDNS_Client on NRF52840_FEATHER with ENC28J60 using EthernetENC Library

HTTP WebServer is @ IP : 192.168.2.83
[DDNS] Access whatismyipaddress
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

#### 6. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit NRF52840_FEATHER_EXPRESS with ENC28J60 using UIPEthernet Library

```
Start DuckDNS_Client on NRF52840_FEATHER with ENC28J60 using UIPEthernet Library
ENC28J60_CONTROL_CS =10
SS =5
SPI_MOSI =25
SPI_MISO =24
SPI_SCK =26

HTTP WebServer is @ IP : 192.168.2.99
[DDNS] Access whatismyipaddress
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

#### 7. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Start DuckDNS_Client on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.83
[DDNS] Access whatismyipaddress
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

#### 8. Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on Adafruit SAMD21 SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library

```
Start No-ip_Client on SAMD_NANO_33_IOT with WiFiNINA using WiFiNINA_Generic Library
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.83
[DDNS] Access whatismyipaddress
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

#### 9. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on Arduino SAM DUE with W5100 using Ethernet Library

```
Start DuckDNS_Client on SAM DUE with W5x00 using Ethernet Library
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096

HTTP WebServer is @ IP : 192.168.2.94
[DDNS] Access whatismyipaddress
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

#### 10. Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on Arduino SAM DUE with W5100 using EthernetLarge Library

```
Start No-ip_Client on SAM DUE with W5x00 using EthernetLarge Library
_pinCS = 0
W5100 init, using SS_PIN_DEFAULT = 10, new ss_pin = 10, W5100Class::ss_pin = 10
W5100::init: W5100, SSIZE =4096

HTTP WebServer is @ IP : 192.168.2.94
[DDNS] Access whatismyipaddress
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

#### 11. Debug terminal output when running example [DuckDNS_Client](examples/Generic/DuckDNS_Client) on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library

```
Start DuckDNS_Client on SEEED_XIAO_M0 with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library
[ESP_AT] Use ES8266-AT Command
WiFi shield init done
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.101
[DDNS] Access whatismyipaddress
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

#### 12. Debug terminal output when running example [No-ip_Client](examples/Generic/No-ip_Client) on SeeedStudio SEEED_XIAO_M0 with ESP8266-AT using ESP8266_AT_WebServer Library

```
Start No-ip_Client on SEEED_XIAO_M0 with ESP8266-AT/ESP32-AT using ESP8266_AT_WebServer Library
[ESP_AT] Use ES8266-AT Command
WiFi shield init done
Connecting to WiFi SSID: HueNet1

HTTP WebServer is @ IP : 192.168.2.101
[DDNS] Access whatismyipaddress
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
---

## Releases

### Releases v1.0.0

1. Initial coding for Generic boards using many different WiFi/Ethernet modules/shields.

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
  
#### Currently Supported WiFi Modules/Shields

  - **ESP8266 built-in WiFi**
  - **ESP32 built-in WiFi**
  - **WiFiNINA using WiFiNINA or WiFiNINA_Generic library**.
  - **ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or ESP8266_AT_WebServer library**.
  
#### Currently Supported Ethernet Modules/Shields

  - **W5x00's using Ethernet, EthernetLarge, Ethernet2 or Ethernet3 Library.**
  - **ENC28J60 using EthernetENC, UIPEthernet library**
  - **LAN8742A using STM32duino LwIP,STM32duino STM32Ethernet libraries**

---

### TO DO

1. Bug Searching and Killing
2. Support more types of boards using WiFi/Ethernet shields (Teensy, AVR Nano/UNO/Mega, etc.)
3. Support more non-compatible Ethernet Libraries such as Ethernet_Shield_W5200, EtherCard, EtherSia


### DONE

 1. Add support to Arduino SAMD21 (ZERO, MKR, NANO_33_IOT, etc.)
 2. Add support to Adafruit SAMD21 (Itsy-Bitsy M0, Metro M0, Feather M0 Express, etc.).
 3. Add support to Adafruit SAMD51 (Itsy-Bitsy M4, Metro M4, Grand Central M4, Feather M4 Express, etc.).
 4. Add support to Adafruit nRF52 ( Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.
 5. Add support to SAM DUE.
 6. Add support to Seeeduino SAMD21/SAMD51 boards (SEEED_WIO_TERMINAL, SEEED_FEMTO_M0, SEEED_XIAO_M0, Wio_Lite_MG126, WIO_GPS_BOARD, SEEEDUINO_ZERO, SEEEDUINO_LORAWAN, SEEED_GROVE_UI_WIRELESS, etc.)
 7. Add support to STM32F/L/H/G/WB/MP1 (Nucleo-144, Nucleo-64, Nucleo-32, Discovery, STM32Fx, STM32H7, STM32Lx, STM32Gx, STM32WB, STM32MP1, etc.) having 32K+ Flash program memory.
 8. Add support to Ethernet W5x00, using either [`Ethernet`](https://www.arduino.cc/en/Reference/Ethernet), [`Ethernet2`](https://github.com/khoih-prog/Ethernet2), [`Ethernet3`](https://github.com/sstaub/Ethernet3) or [`EthernetLarge`](https://github.com/OPEnSLab-OSU/EthernetLarge) library
 9. Add support to LAN8742A using STM32duino LwIP,STM32duino STM32Ethernet libraries
10. Add support to Ethernet ENC28J60, using [`EthernetENC`](https://github.com/jandrassy/EthernetENC) [`UIPEthernet`](https://github.com/UIPEthernet/UIPEthernet) library
11. Add support to WiFiNINA using WiFiNINA or WiFiNINA_Generic library.
12. Add support to ESP8266-AT, ESP32-AT WiFi shields using WiFiEspAT or ESP8266_AT_WebServer library.
13. Add support to Seeeduino SAMD21/SAMD51: LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, Wio Terminal, Grove UI Wireless

 
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Based on and modified from the [EasyDDNS Library](https://github.com/ayushsharma82/EasyDDNS) originally written for ESP8266/ESP32.
2. Thanks to good work of [Miguel Wisintainer](https://github.com/tcpipchip) for working with, developing, debugging and testing.

<table>
  <tr>
    <td align="center"><a href="https://github.com/ayushsharma82"><img src="https://github.com/ayushsharma82.png" width="100px;" alt="ayushsharma82"/><br /><sub><b>⭐️ Ayush Sharma</b></sub></a><br /></td>
    <td align="center"><a href="https://github.com/tcpipchip"><img src="https://github.com/tcpipchip.png" width="100px;" alt="tcpipchip"/><br /><sub><b>tcpipchip</b></sub></a><br /></td>
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

- The library is licensed under [MIT](https://github.com/khoih-prog/EthernetWebServer/blob/master/LICENSE)

---

## Copyright

Copyright 2020- Khoi Hoang




