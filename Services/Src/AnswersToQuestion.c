#include "AnswersToQuestion.h"
#include "usart.h"
#include "GlobalSettings.h"
#include "Crc16.h"

extern uint8_t tx_usart_data[BUF_LEN];
extern uint8_t statusState;
uint16_t crc;

// Отправляет ведущему текущее состояние.
void GetStatus(void)
{
    tx_usart_data[0] = COMP_ADDRESS;
    tx_usart_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart_data[2] = GET_STATUS;
    tx_usart_data[3] = 0x08;
    tx_usart_data[4] = statusState;
    tx_usart_data[5] = 0x00;
    crc = GetCrc16(tx_usart_data, tx_usart_data[3] - 2);
    tx_usart_data[6] = crc >> 8;
    tx_usart_data[7] = crc;

    SendDataUsart1(tx_usart_data,tx_usart_data[3]);
}

//По запросу отправляет свой UID
void GetUID(void) //TODO необходимо доделать.
{
    tx_usart_data[0] = COMP_ADDRESS;
    tx_usart_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart_data[2] = GET_UID;
    tx_usart_data[3] = 0x00;
}
/**
 * Управляет состоянием клапана Холодная вода
 * @param state Состояние порта SET/RESET
 */
void SetValveCoolWaterState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveCoolWater(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveCoolWater(GPIO_PIN_SET);
            break;
        default:
            SetValveCoolWater(GPIO_PIN_RESET);
            break;
    }
}
/**
 * Управляет состоянием клапана Горячая вода
 * @param state Состояние порта SET/RESET
 */
void SetValveHotWaterState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveHotWater(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveHotWater(GPIO_PIN_SET);
            break;
        default:
            SetValveHotWater(GPIO_PIN_RESET);
            break;
    }
}
/**
 * Управляет состоянием клапана Осмос
 * @param state Состояние порта SET/RESET
 */
void SetValveOsmosState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveOsmos(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveOsmos(GPIO_PIN_SET);
            break;
        default:
            SetValveOsmos(GPIO_PIN_RESET);
            break;
    }
}
/**
 * Управляет состоянием клапана Пена
 * @param state Состояние порта SET/RESET
 */
void SetValveFoamState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveFoam(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveFoam(GPIO_PIN_SET);
            break;
        default:
            SetValveFoam(GPIO_PIN_RESET);
            break;
    }
}
/**
 * Управляет состоянием клапана Воздух
 * @param state Состояние порта SET/RESET
 */
void SetValveAirState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveAir(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveAir(GPIO_PIN_SET);
            break;
        default:
            SetValveAir(GPIO_PIN_RESET);
            break;
    }
}
/**
 * Управляет состоянием клапана Сброс избыточного давления
 * @param state Состояние порта SET/RESET
 */
void SetValveDropState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveDrop(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveDrop(GPIO_PIN_SET);
            break;
        default:
            SetValveDrop(GPIO_PIN_RESET);
            break;
    }
}