/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /* GPIO Ports Clock Enable */
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOE, Valve_Cool_Water_Pin | Valve_Hot_Water_Pin | Valve_Foam_Pin | Valve_Air_Pin
                             | Valve_Powdr_Pin | Valve_Osmos_Pin | Valve_Sbros_Pin | Dozator_Vosk_Pin
                             | Dozator_Pena_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(GPIOD, Motor_Start_Pin | Motor_Revers_Pin | PWM_Inventor_Pin | CS_rs485_USART2_Pin,
                      GPIO_PIN_RESET);

    /*Configure GPIO pin Output Level */
    HAL_GPIO_WritePin(CS_rs485_USART1_GPIO_Port, CS_rs485_USART1_Pin, GPIO_PIN_RESET);

    /*Configure GPIO pin : PA0 */
    GPIO_InitStruct.Pin = GPIO_PIN_0;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    /*Configure GPIO pins : PEPin PEPin PEPin PEPin
                             PEPin PEPin PEPin PEPin
                             PEPin */
    GPIO_InitStruct.Pin = Valve_Cool_Water_Pin | Valve_Hot_Water_Pin | Valve_Foam_Pin | Valve_Air_Pin
                          | Valve_Powdr_Pin | Valve_Osmos_Pin | Valve_Sbros_Pin | Dozator_Vosk_Pin
                          | Dozator_Pena_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = DatchikPotoka_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(DatchikPotoka_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pins : PDPin PDPin PDPin PDPin */
    GPIO_InitStruct.Pin = Motor_Start_Pin | Motor_Revers_Pin | PWM_Inventor_Pin | CS_rs485_USART2_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = CD_card_detect_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(CD_card_detect_GPIO_Port, &GPIO_InitStruct);

    /*Configure GPIO pin : PtPin */
    GPIO_InitStruct.Pin = CS_rs485_USART1_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(CS_rs485_USART1_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
/**
 * Управление выводом управляющим режимом работы микросхемы RS-485
 * @param state Статус SET-передача RESET-прием
 */
void Cs_Rs485_Usart1(GPIO_PinState state)
{
    HAL_GPIO_WritePin(CS_rs485_USART1_GPIO_Port, CS_rs485_USART1_Pin, state);
}
/**
 * Управление выводом управляющим режимом работы микросхемы RS-485
 * @param state Статус SET-передача RESET-прием
 */
void Cs_Rs485_Usart2(GPIO_PinState state)
{
    HAL_GPIO_WritePin(CS_rs485_USART2_GPIO_Port, CS_rs485_USART2_Pin, state);
}
/* USER CODE END 2 */
