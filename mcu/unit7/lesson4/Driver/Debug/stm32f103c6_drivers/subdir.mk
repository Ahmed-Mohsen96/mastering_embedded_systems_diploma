################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../stm32f103c6_drivers/stm32f103c6_EXTI.c \
../stm32f103c6_drivers/stm32f103c6_gpio_driver.c 

OBJS += \
./stm32f103c6_drivers/stm32f103c6_EXTI.o \
./stm32f103c6_drivers/stm32f103c6_gpio_driver.o 

C_DEPS += \
./stm32f103c6_drivers/stm32f103c6_EXTI.d \
./stm32f103c6_drivers/stm32f103c6_gpio_driver.d 


# Each subdirectory must supply rules for building sources it contributes
stm32f103c6_drivers/stm32f103c6_EXTI.o: ../stm32f103c6_drivers/stm32f103c6_EXTI.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/mastering embedded diploama/mcu/driver/Driver/HAL_driver/KEYPAD_DRIVER" -I"D:/mastering embedded diploama/mcu/driver/Driver/HAL_driver/LCD_driver" -I"D:/mastering embedded diploama/mcu/driver/Driver/stm32f103c6_drivers/inc" -I"D:/mastering embedded diploama/mcu/driver/Driver/stm32f103c6_drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_EXTI.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
stm32f103c6_drivers/stm32f103c6_gpio_driver.o: ../stm32f103c6_drivers/stm32f103c6_gpio_driver.c
	arm-none-eabi-gcc  -gdwarf-2 "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32 -DSTM32F1 -DSTM32F103C6Tx -DDEBUG -c -I../Inc -I"D:/mastering embedded diploama/mcu/driver/Driver/HAL_driver/KEYPAD_DRIVER" -I"D:/mastering embedded diploama/mcu/driver/Driver/HAL_driver/LCD_driver" -I"D:/mastering embedded diploama/mcu/driver/Driver/stm32f103c6_drivers/inc" -I"D:/mastering embedded diploama/mcu/driver/Driver/stm32f103c6_drivers" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"stm32f103c6_drivers/stm32f103c6_gpio_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

