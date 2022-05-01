# build STM32 LL as static lib. 
# includes must be PUBLIC because they are used when building dependents
   
    add_library(STM32CubeHAL STATIC "")
    target_sources(STM32CubeHAL PUBLIC
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s.c
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2s_ex.c
            
    )
    target_include_directories(STM32CubeHAL PUBLIC 
    
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Inc
        STM32F405RG/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy
        STM32F405RG/Drivers/CMSIS/Include
        STM32F405RG/Drivers/CMSIS/Device/ST/STM32F4xx/Include
        STM32F405RG/Core/Inc)       

    # link Core files with ${BUILD_NAME} target executable
    target_sources(${BUILD_NAME} PUBLIC 
        STM32F405RG/Core/Startup/startup_stm32f405rgtx.s
        STM32F405RG/Core/Src/system_stm32f4xx.c
        STM32F405RG/Core/Src/main.c
        STM32F405RG/Core/Src/gpio.c
        STM32F405RG/Core/Src/adc.c
        STM32F405RG/Core/Src/i2s.c
        STM32F405RG/Core/Src//tim.c
        STM32F405RG/Core/Src/stm32f4xx_it.c
        
    )
    target_include_directories(${BUILD_NAME} PUBLIC 
        STM32F405RG/Core/Inc
    )


