################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := del 

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include libraries\EEPROM\examples\eeprom_write/subdir.mk
-include libraries\EEPROM\examples\eeprom_update/subdir.mk
-include libraries\EEPROM\examples\eeprom_read/subdir.mk
-include libraries\EEPROM\examples\eeprom_put/subdir.mk
-include libraries\EEPROM\examples\eeprom_iteration/subdir.mk
-include libraries\EEPROM\examples\eeprom_get/subdir.mk
-include libraries\EEPROM\examples\eeprom_crc/subdir.mk
-include libraries\EEPROM\examples\eeprom_clear/subdir.mk
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
heater_chamber_v1.elf \

HEX += \
heater_chamber_v1.hex \


# All Target
all: heater_chamber_v1

# Tool invocations
heater_chamber_v1: $(HEX)
	@echo 'Building target: $@'
	@echo 'Printing size:'
	"/bin/avr-size" -A "C:/eclipse/EclipseCpp/heater_chamber_v1/Release/heater_chamber_v1.elf"
	@echo 'Finished building target: $@'
	@echo ' '

arduino.ar: $(AR_OBJ)
	@echo 'Starting archiver'
	"/bin/avr-gcc-ar" rcs "C:/eclipse/EclipseCpp/heater_chamber_v1/Release/arduino.ar"  arduino.ar $(AR_OBJ)
	@echo 'Finished building: $@'
	@echo ' '

heater_chamber_v1.elf: $(LINK_OBJ) $(AR)
	@echo 'Starting combiner'
	"/bin/avr-gcc" -Os -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -o "C:/eclipse/EclipseCpp/heater_chamber_v1/Release/heater_chamber_v1.elf"  $(LINK_OBJ) $(AR)  "-LC:/eclipse/EclipseCpp/heater_chamber_v1/Release" -lm
	@echo 'Finished building: $@'
	@echo ' '

heater_chamber_v1.hex: $(ELF)
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
