################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_cache.c \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_check.c \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_gc.c \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_hydrogen.c \
C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_nucleus.c 

C_DEPS += \
.\core\spiffs_cache.c.d \
.\core\spiffs_check.c.d \
.\core\spiffs_gc.c.d \
.\core\spiffs_hydrogen.c.d \
.\core\spiffs_nucleus.c.d 

AR_OBJ += \
.\core\spiffs_cache.c.o \
.\core\spiffs_check.c.o \
.\core\spiffs_gc.c.o \
.\core\spiffs_hydrogen.c.o \
.\core\spiffs_nucleus.c.o 


# Each subdirectory must supply rules for building sources it contributes
core\spiffs_cache.c.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_cache.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\Time" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\spiffs_check.c.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_check.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\Time" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\spiffs_gc.c.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_gc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\Time" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\spiffs_hydrogen.c.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_hydrogen.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\Time" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\spiffs_nucleus.c.o: C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266\spiffs\spiffs_nucleus.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lwip/include" "-IC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/include" "-IC:/eclipse/EclipseCpp/SwitchControler_v1/Release/core" -c -Os -g -Wpointer-arith -Wno-implicit-function-declaration -Wl,-EL -fno-inline-functions -nostdlib -mlongcalls -mtext-section-literals -falign-functions=4 -MMD -std=gnu99 -ffunction-sections -fdata-sections -DF_CPU=160000000L -DLWIP_OPEN_SRC -DDEBUG_ESP_PORT=Serial -DDEBUG_ESP_CORE -DDEBUG_ESP_SSL -DDEBUG_ESP_WIFI -DDEBUG_ESP_HTTP_CLIENT -DDEBUG_ESP_HTTP_UPDATE -DDEBUG_ESP_HTTP_SERVER -DDEBUG_ESP_UPDATER -DDEBUG_ESP_OTA -DDEBUG_TLS_MEM -DARDUINO=10609 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_ESP8266 "-DARDUINO_BOARD=\"ESP8266_ESP01\"" -DESP8266  -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\cores\esp8266" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\variants\generic" -I"C:\eclipse\EclipseCpp\zzzlibraries\ArduinoJson" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WebServer\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\ESP8266WiFi\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\EEPROM" -I"C:\eclipse\EclipseCpp\zzzlibraries\Time" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master" -I"C:\eclipse\EclipseCpp\zzzlibraries\pubsubclient-master\src" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer" -I"C:\eclipse\arduino-1.6.12\hardware\esp8266com\esp8266\libraries\DNSServer\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


