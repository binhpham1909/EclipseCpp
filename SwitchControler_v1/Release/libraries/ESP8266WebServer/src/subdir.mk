################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src\ESP8266WebServer.cpp \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src\Parsing.cpp 

LINK_OBJ += \
.\libraries\ESP8266WebServer\src\ESP8266WebServer.cpp.o \
.\libraries\ESP8266WebServer\src\Parsing.cpp.o 

CPP_DEPS += \
.\libraries\ESP8266WebServer\src\ESP8266WebServer.cpp.d \
.\libraries\ESP8266WebServer\src\Parsing.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\ESP8266WebServer\src\ESP8266WebServer.cpp.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src\ESP8266WebServer.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

libraries\ESP8266WebServer\src\Parsing.cpp.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src\Parsing.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


