#include "RequestsSorting.h"
#include "AnswersToQuestion.h"
#include "usart.h"
#include "GlobalSettings.h"

extern uint8_t tx_usart1_data[BUF_LEN];

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

/**
 * Функция производит сортировку входящих запросов.
 * @param data Массив который нужно сортировать.
 */
void IncomingRequest(const uint8_t *data)
{
    switch(data[2])
    {
        case GET_STATUS:
            GetStatus();
            break;
        case GET_UID:
            GetUID();
            break;
        case SET_VALVE_COOL_WATER:
            SetValveCoolWaterState(data[5]);
            break;
        case SET_VALVE_HOT_WATER:
            SetValveHotWaterState(data[5]);
            break;
        case SET_VALVE_OSMOS:
            SetValveOsmosState(data[5]);
            break;
        case SET_VALVE_FOAM:
            SetValveFoamState(data[5]);
            break;
        case SET_VALVE_AIR:
            SetValveAirState(data[5]);
            break;
        case SET_VALVE_INSECT:
            SetValveInsectState(data[5]);
            break;
        case SET_VALVE_Drop:
            SetValveDropState(data[5]);
            break;
        case SET_DISPENSER_FOAM:
            SetDispenserFoamState(data[5]);
            break;
        case SET_DISPENSER_VOSK:
            SetDispenserVoskState(data[5]);
            break;
        case GET_SENSOR_STREAM:
            GetSensorStreamState();
            break;
    }
}
