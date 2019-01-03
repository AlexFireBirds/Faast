################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ActionControl/ActionControl.c 

OBJS += \
./src/ActionControl/ActionControl.o 

C_DEPS += \
./src/ActionControl/ActionControl.d 


# Each subdirectory must supply rules for building sources it contributes
src/ActionControl/%.o: ../src/ActionControl/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


