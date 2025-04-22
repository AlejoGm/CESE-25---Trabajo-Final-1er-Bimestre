################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDrivers/LedMatrix/src/ledMatrix.c \
../myDrivers/LedMatrix/src/ledMatrix_port.c 

OBJS += \
./myDrivers/LedMatrix/src/ledMatrix.o \
./myDrivers/LedMatrix/src/ledMatrix_port.o 

C_DEPS += \
./myDrivers/LedMatrix/src/ledMatrix.d \
./myDrivers/LedMatrix/src/ledMatrix_port.d 


# Each subdirectory must supply rules for building sources it contributes
myDrivers/LedMatrix/src/%.o myDrivers/LedMatrix/src/%.su myDrivers/LedMatrix/src/%.cyclo: ../myDrivers/LedMatrix/src/%.c myDrivers/LedMatrix/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/API/incl" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/myDrivers/LedMatrix/inc" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/myDrivers/mpu6050/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-myDrivers-2f-LedMatrix-2f-src

clean-myDrivers-2f-LedMatrix-2f-src:
	-$(RM) ./myDrivers/LedMatrix/src/ledMatrix.cyclo ./myDrivers/LedMatrix/src/ledMatrix.d ./myDrivers/LedMatrix/src/ledMatrix.o ./myDrivers/LedMatrix/src/ledMatrix.su ./myDrivers/LedMatrix/src/ledMatrix_port.cyclo ./myDrivers/LedMatrix/src/ledMatrix_port.d ./myDrivers/LedMatrix/src/ledMatrix_port.o ./myDrivers/LedMatrix/src/ledMatrix_port.su

.PHONY: clean-myDrivers-2f-LedMatrix-2f-src

