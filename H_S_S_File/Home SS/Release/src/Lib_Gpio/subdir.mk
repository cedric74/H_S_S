################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_Gpio/beh_BBB_gpio.c \
../src/Lib_Gpio/drv_BBB_gpio.c 

OBJS += \
./src/Lib_Gpio/beh_BBB_gpio.o \
./src/Lib_Gpio/drv_BBB_gpio.o 

C_DEPS += \
./src/Lib_Gpio/beh_BBB_gpio.d \
./src/Lib_Gpio/drv_BBB_gpio.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_Gpio/%.o: ../src/Lib_Gpio/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


