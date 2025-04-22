/*
 * API_level.h
 *
 *  Created on: Apr 19, 2025
 *      Author: User
 */

#ifndef INCL_API_MATRIX_LEVEL_H_
#define INCL_API_MATRIX_LEVEL_H_

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Estructura de configuración para mapear inclinación a una matriz LED.
 */
typedef struct {
    float acc_max_abs_val;     /**< Valor absoluto máximo de aceleración esperada (en g). */
    uint8_t matrix_min_x;      /**< Valor mínimo de X en la matriz LED. */
    uint8_t matrix_max_x;      /**< Valor máximo de X en la matriz LED. */
    uint8_t matrix_min_y;      /**< Valor mínimo de Y en la matriz LED. */
    uint8_t matrix_max_y;      /**< Valor máximo de Y en la matriz LED. */
    uint8_t matrix_shift_x;    /**< Corrimiento de Y en la matriz LED. */
    uint8_t matrix_shift_y;    /**< Corrimiento de X en la matriz LED. */
    bool invert_x;             /**< Si es true, invierte el eje X. */
    bool invert_y;             /**< Si es true, invierte el eje Y. */
} AccelMatrixLevelConfig_t;

/**
 * @brief Inicializa una configuración por defecto: ±1g en aceleración, matriz de 1 a 7.
 *
 * @param config Puntero a la estructura de configuración a inicializar.
 */
void AccelLevel_DefaultConfig(AccelMatrixLevelConfig_t *config);

/**
 * @brief Mapea la aceleración en g a coordenadas de píxel en la matriz LED.
 *
 * @param config Puntero a configuración de mapeo.
 * @param ax Aceleración en eje X (en g).
 * @param ay Aceleración en eje Y (en g).
 * @param px Puntero donde se guardará la coordenada X resultante.
 * @param py Puntero donde se guardará la coordenada Y resultante.
 */
void AccelLevel_Map(const AccelMatrixLevelConfig_t *config, float ax, float ay, uint8_t *px, uint8_t *py);


#endif /* INCL_API_MATRIX_LEVEL_H_ */
