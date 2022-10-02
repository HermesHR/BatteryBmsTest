################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Compiler'
	"C:/prolin_sdk_win-2.9.1/sdk/toolchains/arm-4.6.3/bin/arm-none-linux-gnueabi-gcc" -O0 -g2 -Wall -funwind-tables -I"C:/Users/hemerson.santos/workspace/BatteryBmsTest/inc" -I"C:/Users/hemerson.santos/workspace/BatteryBmsTest/src" -I"C:/prolin_sdk_win-2.9.1/sdk/platforms/prolin-dev-4.6.3/include" -I"C:/prolin_sdk_win-2.9.1/sdk/platforms/prolin-dev-4.6.3/include/freetype2" -I"C:/prolin_sdk_win-2.9.1/sdk/toolchains/arm-4.6.3/arm-none-linux-gnueabi/libc/usr/include" -I"C:/prolin_sdk_win-2.9.1/sdk/toolchains/arm-4.6.3/lib/gcc/arm-none-linux-gnueabi/4.6.3/include" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


