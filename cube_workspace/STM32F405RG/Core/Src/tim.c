/**
  ******************************************************************************
  * @file    tim.c
  * @brief   This file provides code for the configuration
  *          of the TIM instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "tim.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* TIM3 init function */
void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM3);

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  /**TIM3 GPIO Configuration
  PB4   ------> TIM3_CH1
  PB5   ------> TIM3_CH2
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_4|LL_GPIO_PIN_5;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  LL_TIM_SetEncoderMode(TIM3, LL_TIM_ENCODERMODE_X2_TI1);
  LL_TIM_IC_SetActiveInput(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_ACTIVEINPUT_DIRECTTI);
  LL_TIM_IC_SetPrescaler(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
  LL_TIM_IC_SetFilter(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV1);
  LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);
  LL_TIM_IC_SetActiveInput(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_ACTIVEINPUT_DIRECTTI);
  LL_TIM_IC_SetPrescaler(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_ICPSC_DIV1);
  LL_TIM_IC_SetFilter(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_IC_FILTER_FDIV1);
  LL_TIM_IC_SetPolarity(TIM3, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_RISING);
  TIM_InitStruct.Prescaler = 1;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 65535;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM3, &TIM_InitStruct);
  LL_TIM_EnableARRPreload(TIM3);
  LL_TIM_SetTriggerOutput(TIM3, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM3);
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}
/* TIM4 init function */
void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  LL_TIM_InitTypeDef TIM_InitStruct = {0};

  LL_GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* Peripheral clock enable */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_TIM4);

  LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOB);
  /**TIM4 GPIO Configuration
  PB6   ------> TIM4_CH1
  PB7   ------> TIM4_CH2
  */
  GPIO_InitStruct.Pin = LL_GPIO_PIN_6|LL_GPIO_PIN_7;
  GPIO_InitStruct.Mode = LL_GPIO_MODE_ALTERNATE;
  GPIO_InitStruct.Speed = LL_GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.OutputType = LL_GPIO_OUTPUT_PUSHPULL;
  GPIO_InitStruct.Pull = LL_GPIO_PULL_NO;
  GPIO_InitStruct.Alternate = LL_GPIO_AF_2;
  LL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  LL_TIM_SetEncoderMode(TIM4, LL_TIM_ENCODERMODE_X2_TI1);
  LL_TIM_IC_SetActiveInput(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_ACTIVEINPUT_DIRECTTI);
  LL_TIM_IC_SetPrescaler(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_ICPSC_DIV1);
  LL_TIM_IC_SetFilter(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_IC_FILTER_FDIV1);
  LL_TIM_IC_SetPolarity(TIM4, LL_TIM_CHANNEL_CH1, LL_TIM_IC_POLARITY_RISING);
  LL_TIM_IC_SetActiveInput(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_ACTIVEINPUT_DIRECTTI);
  LL_TIM_IC_SetPrescaler(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_ICPSC_DIV1);
  LL_TIM_IC_SetFilter(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_IC_FILTER_FDIV1);
  LL_TIM_IC_SetPolarity(TIM4, LL_TIM_CHANNEL_CH2, LL_TIM_IC_POLARITY_RISING);
  TIM_InitStruct.Prescaler = 1;
  TIM_InitStruct.CounterMode = LL_TIM_COUNTERMODE_UP;
  TIM_InitStruct.Autoreload = 65535;
  TIM_InitStruct.ClockDivision = LL_TIM_CLOCKDIVISION_DIV1;
  LL_TIM_Init(TIM4, &TIM_InitStruct);
  LL_TIM_DisableARRPreload(TIM4);
  LL_TIM_SetTriggerOutput(TIM4, LL_TIM_TRGO_RESET);
  LL_TIM_DisableMasterSlaveMode(TIM4);
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
