################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL_driver/LCD_driver/lcd.c 

OBJS += \
./HAL_driver/LCD_driver/lcd.o 

C_DEPS += \
./HAL_driver/LCD_driver/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
HAL_driver/LCD_driver/lcd.o: ../HAL_driver/LCD_driver/lcd.c
	arm-none-eabi-gcc -g -dwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/mastering embedded diploama/mcu/driver/Driver/HAL_driver/KEYPAD_DRIVER" -I"D:/mastering embedded diploama/mcu/driver/Driver/HAL_driver/LCD_driver" -I"D:/mastering embedded diploama/mcu/driver/Driver/stm32f103c6_drivers/inc" -I"D:/mastering embedded diploama/mcu/driver/Driver/stm32f103c6_drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"HAL_driver/LCD_driver/lcd.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

