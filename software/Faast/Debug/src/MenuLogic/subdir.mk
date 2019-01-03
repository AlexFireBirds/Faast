################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/MenuLogic/MenuLogic.c 

OBJS += \
./src/MenuLogic/MenuLogic.o 

C_DEPS += \
./src/MenuLogic/MenuLogic.d 


# Each subdirectory must supply rules for building sources it contributes
src/MenuLogic/%.o: ../src/MenuLogic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -I/usr/include/wiringpi.h -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


