################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_Sonar/Lib_Sonar.c 

OBJS += \
./src/Lib_Sonar/Lib_Sonar.o 

C_DEPS += \
./src/Lib_Sonar/Lib_Sonar.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_Sonar/%.o: ../src/Lib_Sonar/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	arm-linux-gnueabihf-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


