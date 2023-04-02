#include "AnswersToQuestion.h"

extern uint8_t tx_usart1_data[BUF_LEN];
extern uint8_t statusState;
uint16_t crc;
uint8_t messageCounter;

/*
         * Формат сообщений
         * [0] = [адрес ведущего 1 байт]
         * [1] = [адрес ведомого 1 байт]
         * [2] = [команда 1 байт]
         * [3] = [Номер сообщения 1 байт]
         * [4] = [длина сообщения 1 байт]
         * [5] = [данные 0-251 байт]
         * [6-7] = [CRC16-2 байта]
         */
/**
 * Устанавливает в счетчик номера сообщений.
 * @param number Номер сообщения.
 */
void SetMessageCounter(uint8_t number)
{
    messageCounter = number;
}

/**
 * Получает номер последнего входящего сообщения.
 * @return Номер сообщения.
 */
uint8_t GetMessageCounter()
{
    return messageCounter;
}

// Отправляет ведущему текущее состояние.
void GetStatus(void)
{
    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_STATUS;
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x09;
    tx_usart1_data[5] = statusState;
    tx_usart1_data[6] = 0x00;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[7] = crc >> 8;
    tx_usart1_data[8] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

//По запросу отправляет свой UID
void GetUID(void)
{
    uint32_t uidPart1 = ReadFlash(UID_BASE_ADDRESS);
    uint32_t uidPart2 = ReadFlash(UID_BASE_ADDRESS + 4);
    uint32_t uidPart3 = ReadFlash(UID_BASE_ADDRESS + 8);

    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_UID;
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x13;
    tx_usart1_data[5] = uidPart1 >> 24;
    tx_usart1_data[6] = uidPart1 >> 16;
    tx_usart1_data[7] = uidPart1 >> 8;
    tx_usart1_data[8] = uidPart1;
    tx_usart1_data[9] = uidPart2 >> 24;
    tx_usart1_data[10] = uidPart2 >> 16;
    tx_usart1_data[11] = uidPart2 >> 8;
    tx_usart1_data[12] = uidPart2;
    tx_usart1_data[13] = uidPart3 >> 24;
    tx_usart1_data[14] = uidPart3 >> 16;
    tx_usart1_data[15] = uidPart3 >> 8;
    tx_usart1_data[16] = uidPart3;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[17] = crc >> 8;
    tx_usart1_data[18] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

/**
 * Управляет состоянием клапана Холодная вода
 * @param state Состояние порта SET/RESET
 */
void SetValveCoolWaterState(uint8_t state)
{
    switch (state)
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
    switch (state)
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
    switch (state)
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
    switch (state)
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
    switch (state)
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
    switch (state)
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
    switch (state)
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
    switch (state)
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
    switch (state)
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

    tx_usart1_data[0] = MASTER_ADDRESS;
    tx_usart1_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart1_data[2] = GET_SENSOR_STREAM;
    tx_usart1_data[3] = GetMessageCounter();
    tx_usart1_data[4] = 0x09;
    tx_usart1_data[5] = GetSensorStream();
    tx_usart1_data[6] = 0x00;
    crc = GetCrc16(tx_usart1_data, tx_usart1_data[4] - 2);
    tx_usart1_data[7] = crc >> 8;
    tx_usart1_data[8] = crc;

    SendDataUsart1(tx_usart1_data, tx_usart1_data[4]);
}

















