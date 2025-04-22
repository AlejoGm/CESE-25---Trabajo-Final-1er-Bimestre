#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <inttypes.h>

#define TIMEOUT 1000
#define NL "\r\n"

#define RETRY_UNTIL_OK(func_call, max_tries) \
    do { \
        int tries = (max_tries); \
        while ((func_call) != HAL_OK && tries-- > 0) { \
            HAL_Delay(100); \
        } \
    } while (0)


static UART_HandleTypeDef huart2;

static void uartPrintConfigHex(UART_HandleTypeDef *huart, char *buffer, size_t bufSize) {
    snprintf(buffer, bufSize,
        NL"  UART Config :"NL
        "  BaudRate     : %lu"NL
		"  WordLength   : 0x%08lX"NL
        "  StopBits     : 0x%08lX"NL
        "  Parity       : 0x%08lX"NL
        "  Mode         : 0x%08lX"NL
        "  HwFlowCtl    : 0x%08lX"NL
        "  OverSampling : 0x%08lX"NL,
        huart->Init.BaudRate,
        huart->Init.WordLength,
        huart->Init.StopBits,
        huart->Init.Parity,
        huart->Init.Mode,
        huart->Init.HwFlowCtl,
        huart->Init.OverSampling
    );
}

void uartSendString(const char * pstring){
	if(!pstring)return;
	RETRY_UNTIL_OK(HAL_UART_Transmit(&huart2,(uint8_t*)pstring,strlen(pstring),TIMEOUT),10);
}

void uartSendStringSize(const uint8_t * pstring, uint16_t size){
	if(!pstring || size == 0)return;
	RETRY_UNTIL_OK(HAL_UART_Transmit(&huart2,pstring,size,TIMEOUT),10);
}

void uartReceiveStringSize(uint8_t * pstring, uint16_t size){
	if(!pstring || size == 0)return;
	RETRY_UNTIL_OK(HAL_UART_Receive(&huart2, pstring, size, TIMEOUT),10);
}

bool uartInit(){
  huart2.Instance          = USART2;
  huart2.Init.BaudRate     = 115200;
  huart2.Init.WordLength   = UART_WORDLENGTH_8B;
  huart2.Init.StopBits     = UART_STOPBITS_1;
  huart2.Init.Parity       = UART_PARITY_NONE;
  huart2.Init.Mode         = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;

  if (HAL_UART_Init(&huart2) != HAL_OK){
	return false;
  }
//  char print[500];
//  uint16_t size = sizeof(print);
//  uartPrintConfigHex(&huart2,print,size);
//  uartSendString(print);
  return true;
}

