#ifndef CONTROLBLOCK_ANSWERSTOQUESTION_H
#define CONTROLBLOCK_ANSWERSTOQUESTION_H

#include "stm32f4xx.h"
#include "usart.h"
#include "GlobalSettings.h"
#include "Crc16.h"
#include "string.h"

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
void GetSensorStreamState(void);

#endif //CONTROLBLOCK_ANSWERSTOQUESTION_H
