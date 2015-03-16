################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_Siren/Lib_Siren.c 

OBJS += \
./src/Lib_Siren/Lib_Siren.o 

C_DEPS += \
./src/Lib_Siren/Lib_Siren.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_Siren/%.o: ../src/Lib_Siren/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


