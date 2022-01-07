#include "RequestsSorting.h"
#include "AnswersToQuestion.h"
#include "usart.h"
#include "GlobalSettings.h"

extern uint8_t tx_usart_data[BUF_LEN];

void IncomingRequest(uint8_t *data)
{
    switch(data[2])
    {
        case GET_STATUS:
            GetStatus();
            break;
    }
}
