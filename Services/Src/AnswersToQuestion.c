#include "AnswersToQuestion.h"
#include "usart.h"
#include "GlobalSettings.h"
#include "Crc16.h"

extern uint8_t tx_usart_data[BUF_LEN];
extern uint8_t statusState;
uint16_t crc;

// Отправляет ведущему текущее состояние.
void GetStatus()
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
    HAL_UART_Transmit_IT(&huart2, tx_usart_data, tx_usart_data[3]);
}

//По запросу отправляет свой UID
void GetUID()
{
    tx_usart_data[0] = COMP_ADDRESS;
    tx_usart_data[1] = CONTROL_BLOCK_ADDRESS;
    tx_usart_data[2] = GET_UID;
    tx_usart_data[3] = 0x00;
}
