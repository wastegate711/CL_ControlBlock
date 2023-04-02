#ifndef CONTROLBLOCK_ANSWERSTOQUESTION_H
#define CONTROLBLOCK_ANSWERSTOQUESTION_H

#include "stm32f4xx.h"
#include "usart.h"
#include "GlobalSettings.h"
#include "Crc16.h"
#include "string.h"
#include "Flash.h"

// Отправляет ведущему текущее состояние.
void GetStatus(void);
//По запросу отправляет свой UID
void GetUID(void);
void SetValveCoolWaterState(uint8_t state);
void SetValveHotWaterState(uint8_t state);
void SetValveOsmosState(uint8_t state);
void SetValveFoamState(uint8_t state);
void SetValveAirState(uint8_t state);
void SetValveDropState(uint8_t state);
void SetDispenserFoamState(uint8_t state);
void SetDispenserVoskState(uint8_t state);
void SetValveInsectState(uint8_t state);
void GetSensorStreamState(void);
void SetMessageCounter(uint8_t number);
uint8_t GetMessageCounter();

#endif //CONTROLBLOCK_ANSWERSTOQUESTION_H
