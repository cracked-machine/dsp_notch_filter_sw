// MIT License

// Copyright (c) 2022 Chris Sutton

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.


#include "mainapp.hpp"

#include <I2SManager.hpp>

#include <gpio.h>
#include <i2s.h>
#include <tim.h>

#include <SEGGER_RTT.h>

#ifdef __cplusplus
extern "C"
{
#endif

void mainapp()
{	
	SEGGER_RTT_ConfigUpBuffer(0, NULL, NULL, 0, SEGGER_RTT_MODE_BLOCK_IF_FIFO_FULL);

	HAL_Delay(1000);
	I2SManager i2s_manager(hi2s2);	
	i2s_manager.start_i2s_dma();
	// HAL_TIM_Base_Start_IT(&htim14);
	
	while(true)
	{
		
		HAL_GPIO_TogglePin(LEDA_Red_GPIO_Port, LEDA_Red_Pin);
		HAL_Delay(5000);
	}

}

void error_handler()
{
	while(true)
	{

	}
}

#ifdef __cplusplus
}
#endif
