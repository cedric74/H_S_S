################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Functions_WatchDog/Functions_WatchDog.c 

OBJS += \
./src/Functions_WatchDog/Functions_WatchDog.o 

C_DEPS += \
./src/Functions_WatchDog/Functions_WatchDog.d 


# Each subdirectory must supply rules for building sources it contributes
src/Functions_WatchDog/%.o: ../src/Functions_WatchDog/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


