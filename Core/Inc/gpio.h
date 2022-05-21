/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

void MX_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */
void Cs_Rs485_Usart1(GPIO_PinState state);
void Cs_Rs485_Usart2(GPIO_PinState state);
void SetValveCoolWater(GPIO_PinState state);
void SetValveHotWater(GPIO_PinState state);
void SetValveAir(GPIO_PinState state);
void SetValveFoam(GPIO_PinState state);
void SetValveDrop(GPIO_PinState state);
void SetValveOsmos(GPIO_PinState state);
void SetValveInsect(GPIO_PinState state);
void SetDispenserVosk(GPIO_PinState state);
void SetDispenserFoam(GPIO_PinState state);
void SetMotorStart(GPIO_PinState state);
void SetMotorRevers(GPIO_PinState state);
GPIO_PinState GetMotorRevers();
GPIO_PinState GetMotorStart();
GPIO_PinState GetCdCardDetect();
GPIO_PinState GetDispenserFoam();
GPIO_PinState GetDispenserVosk();
GPIO_PinState GetValveInsect();
GPIO_PinState GetSensorStream();
GPIO_PinState GetValveFoam();
GPIO_PinState GetValveAir();
GPIO_PinState GetValveDrop();
GPIO_PinState GetValveOsmos();
GPIO_PinState GetValveCoolWaterState();
GPIO_PinState GetValveHotWater();
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

