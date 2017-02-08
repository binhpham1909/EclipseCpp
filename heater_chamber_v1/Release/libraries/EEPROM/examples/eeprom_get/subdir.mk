################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
INO_SRCS += \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\examples\eeprom_get\eeprom_get.ino 

INO_DEPS += \
.\libraries\EEPROM\examples\eeprom_get\eeprom_get.ino.d 


# Each subdirectory must supply rules for building sources it contributes
libraries\EEPROM\examples\eeprom_get/eeprom_get.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\examples\eeprom_get\eeprom_get.ino
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


