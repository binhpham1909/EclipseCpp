################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\CDC.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial0.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial1.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial2.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial3.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\IPAddress.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\PluggableUSB.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\Print.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\Stream.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\Tone.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\USBCore.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\WMath.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\WString.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\abi.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\main.cpp \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\new.cpp 

S_UPPER_SRCS += \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_pulse.S 

C_SRCS += \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\WInterrupts.c \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\hooks.c \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring.c \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_analog.c \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_digital.c \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_pulse.c \
C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_shift.c 

C_DEPS += \
.\core\WInterrupts.c.d \
.\core\hooks.c.d \
.\core\wiring.c.d \
.\core\wiring_analog.c.d \
.\core\wiring_digital.c.d \
.\core\wiring_pulse.c.d \
.\core\wiring_shift.c.d 

AR_OBJ += \
.\core\CDC.cpp.o \
.\core\HardwareSerial.cpp.o \
.\core\HardwareSerial0.cpp.o \
.\core\HardwareSerial1.cpp.o \
.\core\HardwareSerial2.cpp.o \
.\core\HardwareSerial3.cpp.o \
.\core\IPAddress.cpp.o \
.\core\PluggableUSB.cpp.o \
.\core\Print.cpp.o \
.\core\Stream.cpp.o \
.\core\Tone.cpp.o \
.\core\USBCore.cpp.o \
.\core\WInterrupts.c.o \
.\core\WMath.cpp.o \
.\core\WString.cpp.o \
.\core\abi.cpp.o \
.\core\hooks.c.o \
.\core\main.cpp.o \
.\core\new.cpp.o \
.\core\wiring.c.o \
.\core\wiring_analog.c.o \
.\core\wiring_digital.c.o \
.\core\wiring_pulse.S.o \
.\core\wiring_pulse.c.o \
.\core\wiring_shift.c.o 

S_UPPER_DEPS += \
.\core\wiring_pulse.S.d 

CPP_DEPS += \
.\core\CDC.cpp.d \
.\core\HardwareSerial.cpp.d \
.\core\HardwareSerial0.cpp.d \
.\core\HardwareSerial1.cpp.d \
.\core\HardwareSerial2.cpp.d \
.\core\HardwareSerial3.cpp.d \
.\core\IPAddress.cpp.d \
.\core\PluggableUSB.cpp.d \
.\core\Print.cpp.d \
.\core\Stream.cpp.d \
.\core\Tone.cpp.d \
.\core\USBCore.cpp.d \
.\core\WMath.cpp.d \
.\core\WString.cpp.d \
.\core\abi.cpp.d \
.\core\main.cpp.d \
.\core\new.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
core\CDC.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\CDC.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\HardwareSerial.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\HardwareSerial0.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial0.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\HardwareSerial1.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial1.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\HardwareSerial2.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial2.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\HardwareSerial3.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\HardwareSerial3.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\IPAddress.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\IPAddress.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\PluggableUSB.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\PluggableUSB.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\Print.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\Print.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\Stream.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\Stream.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\Tone.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\Tone.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\USBCore.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\USBCore.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\WInterrupts.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\WInterrupts.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\WMath.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\WMath.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\WString.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\WString.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\abi.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\abi.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\hooks.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\hooks.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\main.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\main.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\new.cpp.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\new.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"/bin/avr-g++" -c -g -Os -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\wiring.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\wiring_analog.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_analog.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\wiring_digital.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_digital.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\wiring_pulse.S.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_pulse.S
	@echo 'Building file: $<'
	@echo 'Starting S compile'
	"/bin/avr-gcc" -c -g -x assembler-with-cpp -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\wiring_pulse.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_pulse.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '

core\wiring_shift.c.o: C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino\wiring_shift.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/bin/avr-gcc" -c -g -Os -std=gnu11 -ffunction-sections -fdata-sections -MMD -flto -fno-fat-lto-objects -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10609 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR   -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\cores\arduino" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM" -I"C:\eclipse\arduino-1.6.12\hardware\arduino\avr\libraries\EEPROM\src" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<" -o "$@"  -Wall
	@echo 'Finished building: $<'
	@echo ' '


