################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_Motor/Lib_Motor.c 

OBJS += \
./src/Lib_Motor/Lib_Motor.o 

C_DEPS += \
./src/Lib_Motor/Lib_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_Motor/%.o: ../src/Lib_Motor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


