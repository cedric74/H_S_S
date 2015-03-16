################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_Camera/Lib_Camera.c 

OBJS += \
./src/Lib_Camera/Lib_Camera.o 

C_DEPS += \
./src/Lib_Camera/Lib_Camera.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_Camera/%.o: ../src/Lib_Camera/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


