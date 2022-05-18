#ifndef CONTROLBLOCK_REQUESTSSORTING_H
#define CONTROLBLOCK_REQUESTSSORTING_H

#include "stm32f4xx.h"

// Команды запросов
//#define GET_STATUS 0x01

/**
 * Функция производит сортировку входящих запросов.
 * @param data Массив который нужно сортировать.
 */
void IncomingRequest(const uint8_t *data);

#endif //CONTROLBLOCK_REQUESTSSORTING_H
