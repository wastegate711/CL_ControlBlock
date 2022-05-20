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

/**
 * Управление клапаном холодной воды.
 * @param state Состояние включен/выключен.
 */
void SetValveCoolWater(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Cool_Water_GPIO_Port, Valve_Cool_Water_Pin, state);
}

/**
 * Проверяет состояние клапана холодной воды.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveCoolWaterState()
{
    return HAL_GPIO_ReadPin(Valve_Cool_Water_GPIO_Port, Valve_Cool_Water_Pin);
}

/**
 * Управление клапаном воздуха.
 * @param state Состояние Включен/Выключен.
 */
void SetValveAir(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Air_GPIO_Port, Valve_Air_Pin, state);
}

/**
 * Проверяет состояние клапана воздух.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveAir()
{
    return HAL_GPIO_ReadPin(Valve_Air_GPIO_Port, Valve_Air_Pin);
}

/**
 * Управление клапаном средства от насекомых.
 * @param state Состояние Включен/Выключен.
 */
void SetValveInsect(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Powdr_GPIO_Port, Valve_Powdr_Pin, state);
}

/**
 * Проверяет состояние клапана средсво от насекомых.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveInsect()
{
    return HAL_GPIO_ReadPin(Valve_Powdr_GPIO_Port, Valve_Powdr_Pin);
}

/**
 * Управление клапаном пена.
 * @param state Состояние Включен/Выключен.
 */
void SetValveFoam(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Foam_GPIO_Port, Valve_Foam_Pin, state);
}

/**
 * Управление дозатором воск.
 * @param state Состояние Включен/Выключен.
 */
void SetDispenserVosk(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Dozator_Vosk_GPIO_Port, Dozator_Vosk_Pin, state);
}

/**
 * Проверяет состояние дозатора воск.
 * @return Вернет состояние дозатора SET-включен, RESET-выключен.
 */
GPIO_PinState GetDispenserVosk()
{
    return HAL_GPIO_ReadPin(Dozator_Vosk_GPIO_Port, Dozator_Vosk_Pin);
}

/**
 * Считывает наличие карты памяти в слоте.
 * @return Вернет SET-карта вставлена, RESET-карты нет.
 */
GPIO_PinState GetCdCardDetect()
{
    return HAL_GPIO_ReadPin(CD_card_detect_GPIO_Port, CD_card_detect_Pin);
}

/**
 * Управление частотником, включает частотник вращение вперед.
 * @param state Состояние Включен/Выключен.
 */
void SetMotorStart(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Motor_Start_GPIO_Port, Motor_Start_Pin, state);
}

/**
 * Считывает состояние вывода управления частотником вращения вперед.
 * @return Вернет SET-включено, RESET-выключено.
 */
GPIO_PinState GetMotorStart()
{
    return HAL_GPIO_ReadPin(Motor_Start_GPIO_Port, Motor_Start_Pin);
}

/**
 * Управление частотником, включает частотник вращение назад.
 * @param state Состояние Включен/Выключен.
 */
void SetMotorRevers(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Motor_Revers_GPIO_Port, Motor_Revers_Pin, state);
}

/**
 * Считывает состояние вывода управления частотником вращения назад.
 * @return Вернет SET-включено, RESET-выключено.
 */
GPIO_PinState GetMotorRevers()
{
    return HAL_GPIO_ReadPin(Motor_Revers_GPIO_Port, Motor_Revers_Pin);
}

/**
 * Управление дозатором пена.
 * @param state Состояние Включен/Выключен.
 */
void SetDispenserFoam(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Dozator_Pena_GPIO_Port, Dozator_Pena_Pin, state);
}

/**
 * Проверяет состояние дозатора пена.
 * @return Вернет состояние дозатора SET-включен, RESET-выключен.
 */
GPIO_PinState GetDispenserFoam()
{
    return HAL_GPIO_ReadPin(Dozator_Pena_GPIO_Port, Dozator_Pena_Pin);
}

/**
 * Считывает состояние датчика потока.
 * @return //TODO Добавить состояние датчика.
 */
GPIO_PinState GetSensorStream()
{
    return HAL_GPIO_ReadPin(DatchikPotoka_GPIO_Port, DatchikPotoka_Pin);
}

/**
 * Проверяет состояние клапана пена.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveFoam()
{
    return HAL_GPIO_ReadPin(Valve_Foam_GPIO_Port, Valve_Foam_Pin);
}

/**
 * Управление клапаном осмос.
 * @param state Состояние Включен/Выключен.
 */
void SetValveOsmos(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Osmos_GPIO_Port, Valve_Osmos_Pin, state);
}

/**
 * Проверяет состояние клапана осмос.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveOsmos()
{
    return HAL_GPIO_ReadPin(Valve_Osmos_GPIO_Port, Valve_Osmos_Pin);
}

/**
 * Управление клапаном сброса.
 * @param state Состояние Включен/Выключен.
 */
void SetValveDrop(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Sbros_GPIO_Port, Valve_Sbros_Pin, state);
}

/**
 * Проверяет состояние клапана сброс.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveDrop()
{
    return HAL_GPIO_ReadPin(Valve_Sbros_GPIO_Port, Valve_Sbros_Pin);
}

/**
 * Управление клапаном горячей воды.
 * @param state Состояние Включен/Выключен.
 */
void SetValveHotWater(GPIO_PinState state)
{
    HAL_GPIO_WritePin(Valve_Hot_Water_GPIO_Port, Valve_Hot_Water_Pin, state);
}

/**
 * Проверяет состояние клапана горячей воды.
 * @return Вернет состояние клапана SET-клапан включен, RESET-выключен.
 */
GPIO_PinState GetValveHotWater()
{
    return HAL_GPIO_ReadPin(Valve_Hot_Water_GPIO_Port, Valve_Hot_Water_Pin);
}
/* USER CODE END 2 */
