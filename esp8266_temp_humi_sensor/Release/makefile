################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/spiffs/subdir.mk
-include arduino/core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/arduino.ar \

ELF += \
esp8266_temp_humi_sensor.elf \

EEP += \
esp8266_temp_humi_sensor.eep \

FLASH_IMAGE += \
esp8266_temp_humi_sensor.bin \


# All Target
all: esp8266_temp_humi_sensor

# Tool invocations
esp8266_temp_humi_sensor: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/bin/xtensa-lx106-elf-size" -A "C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/esp8266_temp_humi_sensor.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/bin/xtensa-lx106-elf-ar" cru  "C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

esp8266_temp_humi_sensor.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/bin/xtensa-lx106-elf-gcc" -g -Os -nostdlib -Wl,--no-check-sections -u call_user_start -Wl,-static "-L/tools/sdk//lib" "-L/tools/sdk//ld" "-Teagle.flash.512k.ld" -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy  -o "C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/esp8266_temp_humi_sensor.elf" -Wl,--start-group   $(LINK_OBJ) $(AR)  "C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/arduino.ar" -lm -lgcc -lhal -lphy -lnet80211 -llwip -lwpa -lmain -lpp -lsmartconfig -lwps -lcrypto -Wl,--end-group  "-LC:/eclipse/workspace/esp8266_temp_humi_sensor/Release"
	@echo 'Finished building: $@'
	@echo ' '

esp8266_temp_humi_sensor.eep: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

esp8266_temp_humi_sensor.bin: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"/esptool.exe" -eo "/bootloaders/eboot/eboot.elf" -bo "C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/esp8266_temp_humi_sensor.bin" -bm qio -bf 40 -bz 512K -bs .text -bp 4096 -ec -eo "C:/eclipse/workspace/esp8266_temp_humi_sensor/Release/esp8266_temp_humi_sensor.elf" -bs .irom0.text -bs .text -bs .data -bs .rodata -bc -ec
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELF)$(C++_DEPS)$(AR)$(C_DEPS)$(CC_DEPS)$(FLASH_IMAGE)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(EEP)$(CXX_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) esp8266_temp_humi_sensor
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
