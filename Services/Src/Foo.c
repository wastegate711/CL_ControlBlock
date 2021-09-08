//
// Created by wastegate on 08.09.2021.
//

#include "Foo.h"

void Foo(GPIO_TypeDef* port, uint16_t GPIO_Pin)
{
    HAL_GPIO_TogglePin(port, GPIO_Pin);
}