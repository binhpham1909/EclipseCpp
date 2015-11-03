################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../esp8266_temp_humi_sensor.cpp 

CPP_DEPS += \
./esp8266_temp_humi_sensor.cpp.d 

LINK_OBJ += \
./esp8266_temp_humi_sensor.cpp.o 


# Each subdirectory must supply rules for building sources it contributes
esp8266_temp_humi_sensor.cpp.o: ../esp8266_temp_humi_sensor.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/xtensa-lx106-elf-g++" -D__ets__ -DICACHE_FLASH -U__STRICT_ANSI__ "-I/tools/sdk//include" -c -Os -g -mlongcalls -mtext-section-literals -fno-exceptions -fno-rtti -falign-functions=4 -std=c++11 -MMD -DF_CPU=80000000L -DARDUINO=165-r5 -DARDUINO_ESP8266_ESP01 -DARDUINO_ARCH_1.6.5-947-G39819F0  -DESP8266   -I"C:\Users\Administrator\AppData\Roaming\Arduino15\packages\esp8266\hardware\esp8266\1.6.5-947-g39819f0\cores\esp8266" -I"C:\Users\Administrator\AppData\Roaming\Arduino15\packages\esp8266\hardware\esp8266\1.6.5-947-g39819f0\variants\generic" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"
	@echo 'Finished building: $<'
	@echo ' '


