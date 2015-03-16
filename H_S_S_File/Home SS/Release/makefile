################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Lib_socket/subdir.mk
-include src/Lib_Siren/subdir.mk
-include src/Lib_Sensor/subdir.mk
-include src/Lib_Motor/subdir.mk
-include src/Lib_Gpio/subdir.mk
-include src/Lib_Detect/subdir.mk
-include src/Lib_Camera/subdir.mk
-include src/Functions_WatchDog/subdir.mk
-include src/Functions_State_Machine/subdir.mk
-include src/Functions_Alerte/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Home\ SS

# Tool invocations
Home\ SS: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	arm-linux-gnueabihf-gcc-4.8  -o "Home SS" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) "Home SS"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
