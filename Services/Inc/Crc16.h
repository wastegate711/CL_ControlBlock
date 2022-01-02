#ifndef CONTROLBLOCK_CRC16_H
#define CONTROLBLOCK_CRC16_H

#include "stm32f4xx.h"

uint16_t GetCrc16(uint8_t *data, int length);
uint8_t CompareCrc16(uint8_t *Buf);//функция сравнения CRC

#endif //CONTROLBLOCK_CRC16_H
