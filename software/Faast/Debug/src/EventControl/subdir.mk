################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/EventControl/EventControl.c 

OBJS += \
./src/EventControl/EventControl.o 

C_DEPS += \
./src/EventControl/EventControl.d 


# Each subdirectory must supply rules for building sources it contributes
src/EventControl/%.o: ../src/EventControl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/usr/include/wiringpi.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


