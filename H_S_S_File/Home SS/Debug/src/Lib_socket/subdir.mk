################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Lib_socket/Lib_socket.c 

OBJS += \
./src/Lib_socket/Lib_socket.o 

C_DEPS += \
./src/Lib_socket/Lib_socket.d 


# Each subdirectory must supply rules for building sources it contributes
src/Lib_socket/%.o: ../src/Lib_socket/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	arm-linux-gnueabihf-gcc-4.8 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


