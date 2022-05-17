#ifndef CONTROLBLOCK_ANSWERSTOQUESTION_H
#define CONTROLBLOCK_ANSWERSTOQUESTION_H

#include "stm32f4xx.h"

// Отправляет ведущему текущее состояние.
void GetStatus();
//По запросу отправляет свой UID
void GetUID();

#endif //CONTROLBLOCK_ANSWERSTOQUESTION_H
