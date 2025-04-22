################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../API/src/API_debounce.c \
../API/src/API_delay.c \
../API/src/API_matrix_level.c \
../API/src/API_uart.c 

OBJS += \
./API/src/API_debounce.o \
./API/src/API_delay.o \
./API/src/API_matrix_level.o \
./API/src/API_uart.o 

C_DEPS += \
./API/src/API_debounce.d \
./API/src/API_delay.d \
./API/src/API_matrix_level.d \
./API/src/API_uart.d 


# Each subdirectory must supply rules for building sources it contributes
API/src/%.o API/src/%.su API/src/%.cyclo: ../API/src/%.c API/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/API/incl" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/myDrivers/LedMatrix/inc" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/myDrivers/mpu6050/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-API-2f-src

clean-API-2f-src:
	-$(RM) ./API/src/API_debounce.cyclo ./API/src/API_debounce.d ./API/src/API_debounce.o ./API/src/API_debounce.su ./API/src/API_delay.cyclo ./API/src/API_delay.d ./API/src/API_delay.o ./API/src/API_delay.su ./API/src/API_matrix_level.cyclo ./API/src/API_matrix_level.d ./API/src/API_matrix_level.o ./API/src/API_matrix_level.su ./API/src/API_uart.cyclo ./API/src/API_uart.d ./API/src/API_uart.o ./API/src/API_uart.su

.PHONY: clean-API-2f-src

