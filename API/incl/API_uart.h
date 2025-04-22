/*
 * API_uart.h
 *
 *  Created on: Apr 3, 2025
 *      Author: User
 */

#ifndef API_UART_H_
#define API_UART_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Inicializa la UART
 *
 * @return true si la inicialización fue exitosa, false en caso contrario.
 */
bool uartInit(void);

/**
 * @brief Envía una cadena de texto terminada en NULL por UART.
 *
 * @param pstring Puntero a la cadena de caracteres a enviar.
 */
void uartSendString(const char *pstring);

/**
 * @brief Envía una cantidad específica de bytes por UART.
 *
 * @param pstring Puntero al buffer de datos a enviar.
 * @param size Cantidad de bytes a enviar.
 */
void uartSendStringSize(uint8_t *pstring, uint16_t size);

/**
 * @brief Recibe una cantidad específica de bytes por UART (bloqueante).
 *
 * @param pstring Puntero al buffer donde se almacenarán los datos recibidos.
 * @param size Cantidad de bytes a recibir.
 */
void uartReceiveStringSize(uint8_t *pstring, uint16_t size);


#endif /* API_UART_H_ */
