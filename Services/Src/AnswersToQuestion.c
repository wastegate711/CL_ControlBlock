#include "AnswersToQuestion.h"

extern uint8_t tx_usart1_data[BUF_LEN];
extern uint8_t statusState;
uint16_t crc;

/*
 * Формат ответа
 * [0] = Адрес ведущего
 * [1] = Адрес ведомого
 * [2] = Команда
 * [3] = Длинна посылки (включая CRC16)
 * [4] = Данные
 * [^2] = CRC16
 * [^1] = CRC16
 */

// Отправляет ведущему текущее состояние.
void GetStatus(void)
{
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_STATUS;
    tx_usart1_data[3] = 0x08;
    tx_usart1_data[4] = statusState;
    tx_usart1_data[5] = 0x00;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[3] - 2);
    tx_usart1_data[6] = crc >> 8;
    tx_usart1_data[7] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[3]);
}

//По запросу отправляет свой UID
void GetUID(void) //TODO необходимо доделать.
{
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_UID;
    tx_usart1_data[3] = 0x00;
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

/**
 * Управляет состоянием дозатора Пена
 * @param state Состояние порта SET/RESET
 */
void SetDispenserFoamState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetDispenserFoam(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetDispenserFoam(GPIO_PIN_SET);
            break;
        default:
            SetDispenserFoam(GPIO_PIN_RESET);
            break;
    }
}

/**
 * Управляет состоянием дозатора Воск
 * @param state Состояние порта SET/RESET
 */
void SetDispenserVoskState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetDispenserVosk(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetDispenserVosk(GPIO_PIN_SET);
            break;
        default:
            SetDispenserVosk(GPIO_PIN_RESET);
            break;
    }
}
/**
 * Управляет состоянием клапана сброса
 * @param state Состояние порта SET/RESET
 */
void SetValveInsectState(uint8_t state)
{
    switch(state)
    {
        case 0x00:
            SetValveInsect(GPIO_PIN_RESET);
            break;
        case 0x01:
            SetValveInsect(GPIO_PIN_SET);
            break;
        default:
            SetValveInsect(GPIO_PIN_RESET);
            break;
    }
}

/**
 * Отправляет ведущему состояние датчика потока
 */
void GetSensorStreamState(void)
{
    memset(tx_usart1_data, 0, sizeof(tx_usart1_data));

    tx_usart1_data[0]=MASTER_ADDRESS;
    tx_usart1_data[1]=CONTROL_BLOCK_ADDRESS;
    tx_usart1_data[2]=GET_SENSOR_STREAM;
    tx_usart1_data[3]=0x08;
    tx_usart1_data[4]=GetSensorStream();
    tx_usart1_data[5]=0x00;
    crc= GetCrc16(tx_usart1_data,tx_usart1_data[3]-2);
    tx_usart1_data[6]=crc>>8;
    tx_usart1_data[7]=crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[3]);
}

















