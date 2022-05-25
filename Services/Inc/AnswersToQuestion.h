#ifndef CONTROLBLOCK_ANSWERSTOQUESTION_H
#define CONTROLBLOCK_ANSWERSTOQUESTION_H

#include "stm32f4xx.h"

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

#endif //CONTROLBLOCK_ANSWERSTOQUESTION_H
