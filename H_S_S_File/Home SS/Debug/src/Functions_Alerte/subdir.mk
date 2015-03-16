################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Functions_Alerte/Functions_Alerte.c 

OBJS += \
./src/Functions_Alerte/Functions_Alerte.o 

C_DEPS += \
./src/Functions_Alerte/Functions_Alerte.d 


# Each subdirectory must supply rules for building sources it contributes
src/Functions_Alerte/%.o: ../src/Functions_Alerte/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


