/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
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
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <memory.h>
#include <GlobalSettings.h>
#include <Crc16.h>
#include "RequestsSorting.h"
#include "usart.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern uint8_t rx_usart_data[BUF_LEN];
uint8_t access = 0; //содержит результат проверки CRC входящих данных.
uint16_t result;
// Флаги и статусы состояния.
uint8_t statusState = 0x00; // текущий статус состояния.
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
        .name = "defaultTask",
        .stack_size = 128 * 4,
        .priority = (osPriority_t)osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void)
{
    /* USER CODE BEGIN Init */
    HAL_UART_Receive_IT(&huart2, rx_usart_data, RECEIV_LEN);
    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* creation of defaultTask */
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */
    /* USER CODE END RTOS_THREADS */

    /* USER CODE BEGIN RTOS_EVENTS */
    /* add events, ... */
    /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
    /* USER CODE BEGIN StartDefaultTask */
    /* Infinite loop */
    for(;;)
    {
//        if(RECEIV_LEN - huart2.RxXferCount >= 5)
//        {
//            HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_14);
//            memset(rx_usart_data, 0, sizeof(rx_usart_data));
//            HAL_UART_AbortReceive_IT(&huart2);
//            HAL_UART_Receive_IT(&huart2, rx_usart_data, RECEIV_LEN);
//        }
        if(RECEIV_LEN - huart2.RxXferCount != 0)
        {
            if(rx_usart_data[0] == COMP_ADDRESS &&
               rx_usart_data[1] == CONTROL_BLOCK_ADDRESS &&
               rx_usart_data[3] == RECEIV_LEN - huart2.RxXferCount)
            {
                if(access = CompareCrc16(rx_usart_data) == 1)
                {
                    IncomingRequest(rx_usart_data);
                    HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_15);
                }

                memset(rx_usart_data, 0, sizeof(rx_usart_data)); // очистка массива
                HAL_UART_AbortReceive(&huart2); //отключение прерываний для входящих данных
                HAL_UART_Receive_IT(&huart2, rx_usart_data, RECEIV_LEN); //включение прерываний для входящих данных
            } else
            {
                HAL_GPIO_TogglePin(GPIOD,GPIO_PIN_14);
                memset(rx_usart_data, 0, sizeof(rx_usart_data)); // очистка массива
                HAL_UART_AbortReceive(&huart2); //отключение прерываний для входящих данных
                HAL_UART_Receive_IT(&huart2, rx_usart_data, RECEIV_LEN); //включение прерываний для входящих данных
            }
        }
        osDelay(10);
    }
    /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

