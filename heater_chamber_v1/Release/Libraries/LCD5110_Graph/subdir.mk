################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Users/Administrator/OneDrive/Documents/Arduino/libraries/LCD5110_Graph/LCD5110_Graph.cpp 

C_SRCS += \
C:/Users/Administrator/OneDrive/Documents/Arduino/libraries/LCD5110_Graph/DefaultFonts.c \
C:/Users/Administrator/OneDrive/Documents/Arduino/libraries/LCD5110_Graph/arduino_logo.c 

C_DEPS += \
./Libraries/LCD5110_Graph/DefaultFonts.c.d \
./Libraries/LCD5110_Graph/arduino_logo.c.d 

CPP_DEPS += \
./Libraries/LCD5110_Graph/LCD5110_Graph.cpp.d 

LINK_OBJ += \
./Libraries/LCD5110_Graph/DefaultFonts.c.o \
./Libraries/LCD5110_Graph/LCD5110_Graph.cpp.o \
./Libraries/LCD5110_Graph/arduino_logo.c.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/LCD5110_Graph/DefaultFonts.c.o: C:/Users/Administrator/OneDrive/Documents/Arduino/libraries/LCD5110_Graph/DefaultFonts.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-gcc" -c -g -Os -w -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=165-r5 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"C:\Program Files\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files\Arduino\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\PID" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\EEPROM" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\Wire" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\Wire\utility" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\OneWire-master" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\Arduino-DHT22-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/LCD5110_Graph/LCD5110_Graph.cpp.o: C:/Users/Administrator/OneDrive/Documents/Arduino/libraries/LCD5110_Graph/LCD5110_Graph.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-g++" -c -g -Os -w -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=165-r5 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"C:\Program Files\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files\Arduino\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\PID" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\EEPROM" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\Wire" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\Wire\utility" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\OneWire-master" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\Arduino-DHT22-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '

Libraries/LCD5110_Graph/arduino_logo.c.o: C:/Users/Administrator/OneDrive/Documents/Arduino/libraries/LCD5110_Graph/arduino_logo.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"C:/Program Files/Arduino/hardware/tools/avr/bin/avr-gcc" -c -g -Os -w -ffunction-sections -fdata-sections -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=165-r5 -DARDUINO_AVR_PRO -DARDUINO_ARCH_AVR     -I"C:\Program Files\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files\Arduino\hardware\arduino\avr\variants\eightanaloginputs" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\PID" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\EEPROM" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\Wire" -I"C:\Program Files\Arduino\hardware\arduino\avr\libraries\Wire\utility" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\OneWire-master" -I"C:\Users\Administrator\OneDrive\Documents\Arduino\libraries\Arduino-DHT22-master" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -D__IN_ECLIPSE__=1 "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


