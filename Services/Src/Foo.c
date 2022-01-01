//
// Created by wastegate on 08.09.2021.
//

#include "Foo.h"

/**
  * @brief  Переключает состояние вывода SET/RESER
  * @param port порт.
  * @param GPIO_Pin вывод порта.
  * @retval None
  */
void Foo(GPIO_TypeDef* port, uint16_t GPIO_Pin)
{
    HAL_GPIO_TogglePin(port, GPIO_Pin);
}
