#ifndef CONTROLBLOCK_GLOBALSETTINGS_H
#define CONTROLBLOCK_GLOBALSETTINGS_H

#include "stm32f4xx.h"

// Адреса.
#define COMP_ADDRESS 0x01 // Адрес ведущего.
#define CONTROL_BLOCK_ADDRESS 0x02 // Адрес блока управления.
#define PULT_BLOCK_ADDRESS 0x03 // Адрес пульта.

// Команды запросов
#define GET_STATUS 0x01
#define GET_UID 0x02

// Флаги и статусы состояния.

// Настройки.
#define RECEIV_LEN 255 //максимальная длина принимаемой посылки.

#endif //CONTROLBLOCK_GLOBALSETTINGS_H
