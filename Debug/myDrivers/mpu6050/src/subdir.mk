################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDrivers/mpu6050/src/mpu6050.c \
../myDrivers/mpu6050/src/mpu6050_port.c 

OBJS += \
./myDrivers/mpu6050/src/mpu6050.o \
./myDrivers/mpu6050/src/mpu6050_port.o 

C_DEPS += \
./myDrivers/mpu6050/src/mpu6050.d \
./myDrivers/mpu6050/src/mpu6050_port.d 


# Each subdirectory must supply rules for building sources it contributes
myDrivers/mpu6050/src/%.o myDrivers/mpu6050/src/%.su myDrivers/mpu6050/src/%.cyclo: ../myDrivers/mpu6050/src/%.c myDrivers/mpu6050/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/API/incl" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/myDrivers/LedMatrix/inc" -I"D:/User/Documentos/GitHub/CESE/PdM_workspace_/TP-final/myDrivers/mpu6050/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-myDrivers-2f-mpu6050-2f-src

clean-myDrivers-2f-mpu6050-2f-src:
	-$(RM) ./myDrivers/mpu6050/src/mpu6050.cyclo ./myDrivers/mpu6050/src/mpu6050.d ./myDrivers/mpu6050/src/mpu6050.o ./myDrivers/mpu6050/src/mpu6050.su ./myDrivers/mpu6050/src/mpu6050_port.cyclo ./myDrivers/mpu6050/src/mpu6050_port.d ./myDrivers/mpu6050/src/mpu6050_port.o ./myDrivers/mpu6050/src/mpu6050_port.su

.PHONY: clean-myDrivers-2f-mpu6050-2f-src

