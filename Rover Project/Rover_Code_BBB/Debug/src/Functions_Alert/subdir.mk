################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Functions_Alert/Functions_Alert.c 

OBJS += \
./src/Functions_Alert/Functions_Alert.o 

C_DEPS += \
./src/Functions_Alert/Functions_Alert.d 


# Each subdirectory must supply rules for building sources it contributes
src/Functions_Alert/%.o: ../src/Functions_Alert/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


