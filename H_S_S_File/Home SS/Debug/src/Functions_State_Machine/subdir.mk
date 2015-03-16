################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Functions_State_Machine/Functions_State_Machine.c 

OBJS += \
./src/Functions_State_Machine/Functions_State_Machine.o 

C_DEPS += \
./src/Functions_State_Machine/Functions_State_Machine.d 


# Each subdirectory must supply rules for building sources it contributes
src/Functions_State_Machine/%.o: ../src/Functions_State_Machine/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


