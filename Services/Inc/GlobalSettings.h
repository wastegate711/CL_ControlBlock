#ifndef CONTROLBLOCK_GLOBALSETTINGS_H
#define CONTROLBLOCK_GLOBALSETTINGS_H

#include "stm32f4xx.h"

// Адреса.
#define MASTER_ADDRESS                  0x01 // Адрес ведущего.
#define CONTROL_BLOCK_ADDRESS           0x02 // Адрес блока управления.
#define PULT_BLOCK_ADDRESS              0x03 // Адрес пульта.
#define UID_BASE_ADDRESS                0x1FFF7A10 //Начальный адрес UID

// Команды запросов
#define GET_STATUS                      0x01 // запрос текущего состояния
#define GET_UID                         0x02 // запрос серийного номера устройства
#define SET_VALVE_COOL_WATER            0x03 // Установка состояния Клапана Холодная вода
#define SET_VALVE_HOT_WATER             0x04 // Установка состояния Клапана Горячая вода
#define SET_VALVE_OSMOS                 0x05 // Установка состояния Клапана Осмос
#define SET_VALVE_FOAM                  0x06 // Установка состояния Клапана Пена
#define SET_VALVE_AIR                   0x07 // Установка состояния Клапана Воздух
#define SET_VALVE_INSECT                0x08 // Установка состояния Клапана Средство от насекомых
#define SET_VALVE_Drop                  0x09 // Установка состояния Клапана Сброса
#define SET_DISPENSER_FOAM              0x0A // Установка состояния Дозатора Пена
#define SET_DISPENSER_VOSK              0x0B // Установка состояния Дозатора Воск
#define GET_SENSOR_STREAM               0x0C // Запрос состояния датчика потока
#define GET_VALVE_COOL_WATER            0x0D // Запрос состояния Клапана Холодная вода
#define GET_VALVE_HOT_WATER             0x0E // Запрос состояния Клапана Горячая вода
#define GET_VALVE_OSMOS                 0x0F // Запрос состояния Клапана Осмос
#define GET_VALVE_FOAM                  0x10 // Запрос состояния Клапана Пена
#define GET_VALVE_AIR                   0x11 // Запрос состояния Клапана Воздух
#define GET_VALVE_INSECT                0x12 // Запрос состояния Клапана Средство от насекомых
#define GET_VALVE_DROP                  0x13 // Запрос состояния Клапана Сброс
#define GET_DISPENSER_FOAM              0x14 // Запрос состояния Дозатора Пена
#define GET_DISPENSER_VOSK              0x15 // Запрос состояния Дозатора Воск
#define GET_SOFTWARE_VERSION            0x16 // Запрос версии программы

// Флаги и статусы состояния.

// Настройки.
#define RECEIV_LEN 255 //максимальная длина принимаемой посылки.

#endif //CONTROLBLOCK_GLOBALSETTINGS_H
