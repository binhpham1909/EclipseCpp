################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := del 

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries\pubsubclient-master\src/subdir.mk
-include libraries\ESP8266WiFi\src/subdir.mk
-include libraries\ESP8266WebServer\src/subdir.mk
-include libraries\EEPROM/subdir.mk
-include libraries\DNSServer\src/subdir.mk
-include core\core\umm_malloc/subdir.mk
-include core\core\spiffs/subdir.mk
-include core\core\libb64/subdir.mk
-include core\core/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
AR += \
arduino.ar \

ELF += \
SwitchControler_v1.elf \

HEX += \
SwitchControler_v1.hex \


# All Target
all: SwitchControler_v1

# Tool invocations
SwitchControler_v1: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-size" -A "C:/eclipse/EclipseCpp/SwitchControler_v1/Release/SwitchControler_v1.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-ar" cru "C:/eclipse/EclipseCpp/SwitchControler_v1/Release/arduino.ar"  arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

SwitchControler_v1.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/xtensa-lx106-elf/bin/xtensa-lx106-elf-gcc" -g -Os -nostdlib -Wl,--no-check-sections -u call_user_start -u _printf_float -u _scanf_float -Wl,-static "-LC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/lib" "-LC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/ld" "-LC:/eclipse/arduino-1.6.12/hardware/esp8266com/esp8266/tools/sdk/libc/xtensa-lx106-elf/lib" "-Teagle.flash.1m64.ld" -Wl,--gc-sections -Wl,-wrap,system_restart_local -Wl,-wrap,register_chipv6_phy -o "C:/eclipse/EclipseCpp/SwitchControler_v1/Release/SwitchControler_v1.elf" -Wl,--start-group  $(LINK_OBJ) $(AR) "C:/eclipse/EclipseCpp/SwitchControler_v1/Release/arduino.ar" -lhal -lphy -lpp -lnet80211 -llwip_gcc -lwpa -lcrypto -lmain -lwps -laxtls -lespnow -lsmartconfig -lmesh -lwpa2 -lstdc++ -lm -lc -lgcc -Wl,--end-group "-LC:/eclipse/EclipseCpp/SwitchControler_v1/Release"
	@echo 'Finished building: $@'
	@echo ' '

SwitchControler_v1.hex: $(ELF)
	@echo 'Create eeprom image'
	${A.RECIPE.OBJCOPY.HEX.PATTERN}
	${A.RECIPE.OBJCOPY.EEP.PATTERN}
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(PDE_DEPS)$(C_DEPS)$(AR)$(CC_DEPS)$(AR_OBJ)$(C++_DEPS)$(LINK_OBJ)$(CXX_DEPS)$(ASM_DEPS)$(HEX)$(INO_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(ELF)$(CPP_DEPS)
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
