################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LedMatrix/src/ledMatrix.c \
../LedMatrix/src/ledMatrix_port.c 

OBJS += \
./LedMatrix/src/ledMatrix.o \
./LedMatrix/src/ledMatrix_port.o 

C_DEPS += \
./LedMatrix/src/ledMatrix.d \
./LedMatrix/src/ledMatrix_port.d 


# Each subdirectory must supply rules for building sources it contributes
LedMatrix/src/%.o LedMatrix/src/%.su LedMatrix/src/%.cyclo: ../LedMatrix/src/%.c LedMatrix/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/API/incl" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/LedMatrix/inc" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/LedMatrix" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-LedMatrix-2f-src

clean-LedMatrix-2f-src:
	-$(RM) ./LedMatrix/src/ledMatrix.cyclo ./LedMatrix/src/ledMatrix.d ./LedMatrix/src/ledMatrix.o ./LedMatrix/src/ledMatrix.su ./LedMatrix/src/ledMatrix_port.cyclo ./LedMatrix/src/ledMatrix_port.d ./LedMatrix/src/ledMatrix_port.o ./LedMatrix/src/ledMatrix_port.su

.PHONY: clean-LedMatrix-2f-src

