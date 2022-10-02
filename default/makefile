################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
NOSTRIP += \
app.nostrip \


# All Target
all: BatteryBmsTest

# Tool invocations
BatteryBmsTest: $(NOSTRIP)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC Strip'
	"C:/prolin_sdk_win-2.9.1/sdk/toolchains/arm-4.6.3/bin/arm-none-linux-gnueabi-strip" -g $(NOSTRIP) -o"BatteryBmsTest"
	@echo 'Finished building target: $@'
	@echo ' '

app.nostrip: $(OBJS) $(USER_OBJS)
	@echo 'Invoking: GCC Linker'
	"C:/prolin_sdk_win-2.9.1/sdk/toolchains/arm-4.6.3/bin/arm-none-linux-gnueabi-gcc" -o"app.nostrip" $(OBJS) $(USER_OBJS) $(LIBS) -L"C:/prolin_sdk_win-2.9.1/sdk/platforms/prolin-dev-4.6.3/lib" -Wl,-rpath=//opt/lib -Wl,-rpath=./lib -Wl,-rpath-link,"C:/prolin_sdk_win-2.9.1/sdk/platforms/prolin-dev-4.6.3/lib" -losal -lcrypto -lfreetype -lpng -lpthread -lts -lxui -L"C:/Users/hemerson.santos/workspace/BatteryBmsTest/lib"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(NOSTRIP) BatteryBmsTest
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
