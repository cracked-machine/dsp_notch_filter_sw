
    # link Core files with ${BUILD_NAME} target executable
    target_sources(${BUILD_NAME} PUBLIC 
        STM32F405RG/Core/Startup/startup_stm32f405rgtx.s
        STM32F405RG/Core/Src/system_stm32f4xx.c

        STM32F405RG/Core/Src/adc.c
        STM32F405RG/Core/Src/dma.c
        STM32F405RG/Core/Src/gpio.c
        STM32F405RG/Core/Src/i2s.c
        STM32F405RG/Core/Src/main.c
        STM32F405RG/Core/Src/stm32f4xx_it.c
        STM32F405RG/Core/Src/tim.c
        
    )
    target_include_directories(${BUILD_NAME} PUBLIC 
        STM32F405RG/Core/Inc
    )


