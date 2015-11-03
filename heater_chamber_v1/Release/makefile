################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include arduino/core/subdir.mk
-include Libraries/Wire/utility/subdir.mk
-include Libraries/Wire/subdir.mk
-include Libraries/PID/subdir.mk
-include Libraries/OneWire-master/subdir.mk
-include Libraries/LCD5110_Graph/subdir.mk
-include Libraries/Arduino-DHT22-master/subdir.mk
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
C:/eclipse/workspace/heater_chamber_v1/Release/arduino.ar \

ELF += \
heater_chamber_v1.elf \

EEP += \
heater_chamber_v1.eep \

FLASH_IMAGE += \
heater_chamber_v1.hex \


# All Target
all: heater_chamber_v1

# Tool invocations
heater_chamber_v1: $(FLASH_IMAGE)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-size" -A "C:/eclipse/workspace/heater_chamber_v1/Release/heater_chamber_v1.elf"
	@echo 'Finished building target: $@'
	@echo ' '

C:/eclipse/workspace/heater_chamber_v1/Release/arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-ar" rcs  "C:/eclipse/workspace/heater_chamber_v1/Release/arduino.ar"   $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

heater_chamber_v1.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-gcc" -w -Os -Wl,--gc-sections -mmcu=atmega328p  -o "C:/eclipse/workspace/heater_chamber_v1/Release/heater_chamber_v1.elf"   $(LINK_OBJ) $(AR)  "C:/eclipse/workspace/heater_chamber_v1/Release/arduino.ar" "-LC:/eclipse/workspace/heater_chamber_v1/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

heater_chamber_v1.eep: $(ELF)
	@echo 'Create eeprom image'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "C:/eclipse/workspace/heater_chamber_v1/Release/heater_chamber_v1.elf" "C:/eclipse/workspace/heater_chamber_v1/Release/heater_chamber_v1.eep"
	@echo 'Finished building: $@'
	@echo ' '

heater_chamber_v1.hex: $(EEP)
	@echo 'Create Flash image (ihex format)'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-objcopy" -O ihex -R .eeprom  "C:/eclipse/workspace/heater_chamber_v1/Release/heater_chamber_v1.elf" "C:/eclipse/workspace/heater_chamber_v1/Release/heater_chamber_v1.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELF)$(C++_DEPS)$(AR)$(C_DEPS)$(CC_DEPS)$(FLASH_IMAGE)$(AR_OBJ)$(CPP_DEPS)$(LINK_OBJ)$(EEP)$(CXX_DEPS)$(C_UPPER_DEPS)$(SIZEDUMMY) heater_chamber_v1
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
