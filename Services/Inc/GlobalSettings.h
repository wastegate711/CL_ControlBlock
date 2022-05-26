#ifndef CONTROLBLOCK_GLOBALSETTINGS_H
#define CONTROLBLOCK_GLOBALSETTINGS_H

#include "stm32f4xx.h"

// Адреса.
#define MASTER_ADDRESS 0x01 // Адрес ведущего.
#define CONTROL_BLOCK_ADDRESS 0x02 // Адрес блока управления.
#define PULT_BLOCK_ADDRESS 0x03 // Адрес пульта.

// Команды запросов
#define GET_STATUS 0x01
#define GET_UID 0x02
#define SET_VALVE_COOL_WATER 0x03
#define SET_VALVE_HOT_WATER 0x04
#define SET_VALVE_OSMOS 0x05
#define SET_VALVE_FOAM  0x06
#define SET_VALVE_AIR   0x07
#define SET_VALVE_INSECT 0x08
#define SET_VALVE_Drop  0x09
#define SET_DISPENSER_FOAM   0x0A
#define SET_DISPENSER_VOSK  0x0B
#define GET_SENSOR_STREAM   0x0C

// Флаги и статусы состояния.

// Настройки.
#define RECEIV_LEN 255 //максимальная длина принимаемой посылки.

#endif //CONTROLBLOCK_GLOBALSETTINGS_H
