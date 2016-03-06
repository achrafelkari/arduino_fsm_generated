################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
C:/Program\ Files\ (x86)/Arduino/libraries/PS2Keyboard/PS2Keyboard.cpp 

LINK_OBJ += \
./Libraries/PS2Keyboard/PS2Keyboard.cpp.o 

CPP_DEPS += \
./Libraries/PS2Keyboard/PS2Keyboard.cpp.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/PS2Keyboard/PS2Keyboard.cpp.o: C:/Program\ Files\ (x86)/Arduino/libraries/PS2Keyboard/PS2Keyboard.cpp
	@echo 'Building file: $<'
	@echo 'Starting C++ compile'
	"C:\Program Files (x86)\Arduino\hardware\tools\avr/bin/avr-g++" -c -g -Os -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -MMD -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10605 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR     -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\cores\arduino" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\variants\standard" -I"C:\Program Files (x86)\Arduino\libraries\PS2Keyboard" -I"C:\Program Files (x86)\Arduino\libraries\PS2Keyboard\utility" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire" -I"C:\Program Files (x86)\Arduino\hardware\arduino\avr\libraries\Wire\utility" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 -x c++ "$<"  -o  "$@"   -Wall
	@echo 'Finished building: $<'
	@echo ' '


