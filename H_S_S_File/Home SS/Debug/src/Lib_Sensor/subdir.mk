################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_Sensor/Lib_Sensor.c \
../src/Lib_Sensor/Lib_Sensor_DHT22.c \
../src/Lib_Sensor/bbb_mmio.c 

OBJS += \
./src/Lib_Sensor/Lib_Sensor.o \
./src/Lib_Sensor/Lib_Sensor_DHT22.o \
./src/Lib_Sensor/bbb_mmio.o 

C_DEPS += \
./src/Lib_Sensor/Lib_Sensor.d \
./src/Lib_Sensor/Lib_Sensor_DHT22.d \
./src/Lib_Sensor/bbb_mmio.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_Sensor/%.o: ../src/Lib_Sensor/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


