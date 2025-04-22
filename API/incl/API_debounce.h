/*
 * API_debounce.h
 *
 *  Created on: Mar 27, 2025
 *      Author: User
 */

#ifndef API_INCL_API_DEBOUNCE_H_
#define API_INCL_API_DEBOUNCE_H_

#include <stdint.h>
#include <stdbool.h>

/*! Representa el estado de la tecla detectado por la FSM de debounce */
typedef enum {
    KEY_RISING_EDGE_DETECTED, /*!< Se detectó un flanco ascendente (tecla liberada) */
    KEY_FALLING_EDGE_DETECTED, /*!< Se detectó un flanco descendente (tecla presionada) */
    KEY_NO_CHANGES /*!< No hubo cambios en el estado de la tecla */
} KeyStatus_t;


/**
 * @brief Lee el estado actual de la tecla, considerando el resultado de la máquina de estados de debounce.
 *
 * @return Estado de la tecla como valor del tipo KeyStatus_t.
 */
KeyStatus_t readKey(void);

/**
 * @brief Inicializa la máquina de estados para el control de rebote (debounce) de la tecla.
 */
void debounceFSM_init(void);

/**
 * @brief Actualiza el estado de la máquina de estados de debounce.
 *
 * Debe llamarse periódicamente para detectar cambios de estado estables en la tecla.
 */
void debounceFSM_update(void);



#endif /* API_INCL_API_DEBOUNCE_H_ */
