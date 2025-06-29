################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Lib/Src/input.c \
../Lib/Src/output.c \
../Lib/Src/rc_servo.c 

OBJS += \
./Lib/Src/input.o \
./Lib/Src/output.o \
./Lib/Src/rc_servo.o 

C_DEPS += \
./Lib/Src/input.d \
./Lib/Src/output.d \
./Lib/Src/rc_servo.d 


# Each subdirectory must supply rules for building sources it contributes
Lib/Src/%.o Lib/Src/%.su Lib/Src/%.cyclo: ../Lib/Src/%.c Lib/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F407xx -c -I../Core/Inc -I../Lib/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Lib-2f-Src

clean-Lib-2f-Src:
	-$(RM) ./Lib/Src/input.cyclo ./Lib/Src/input.d ./Lib/Src/input.o ./Lib/Src/input.su ./Lib/Src/output.cyclo ./Lib/Src/output.d ./Lib/Src/output.o ./Lib/Src/output.su ./Lib/Src/rc_servo.cyclo ./Lib/Src/rc_servo.d ./Lib/Src/rc_servo.o ./Lib/Src/rc_servo.su

.PHONY: clean-Lib-2f-Src

