/*
 * main_app.c
 *
 *  Created on: Apr 19, 2025
 *      Author: AGM
 */
#include <stdio.h>
#include "main_app.h"
#include "main.h"
#include <math.h>
#include <string.h>

#define SLOW_DELAY 200
#define FAST_DELAY 5

static char bufstr[100];
size_t size_bufstr;

static uint8_t BIT_MAP_FULL[] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
static const uint8_t BIT_MAP_SMILE[] = {
    0b00111100,
    0b01000010,
    0b10100101,
    0b10000001,
    0b10100101,
    0b10011001,
    0b01000010,
    0b00111100
};


static float x = -1, y = -1, z = -1;
static uint8_t px = 0;
static uint8_t py = 0;

static delay_t app_delay;

static mpu6050_settings_t acc_config;
static max7219_config_t matrix_config;

static AccelMatrixLevelConfig_t *level_config;
static AccelMatrixLevelConfig_t block_config = {
	.acc_max_abs_val = 1.0f, // ±1g
	.matrix_min_x = 0,
	.matrix_max_x = 8,
	.matrix_min_y = 0,
	.matrix_max_y = 8,
	.matrix_shift_x = 0,
	.matrix_shift_y = 0,
	.invert_x = false,
	.invert_y = false,
};

AccelMatrixLevelConfig_t map_intensity = {
    .acc_max_abs_val = 1.0f,
    .matrix_min_x = 0,
    .matrix_max_x = 15,
    .matrix_min_y = 0,
    .matrix_max_y = 15,
    .matrix_shift_x = 0,
    .matrix_shift_y = 0,
    .invert_x = false,
    .invert_y = false
};

static const float acc_levels[] = {1.0f, 0.5f, 0.15f, 0.05f};
static uint8_t current_level = 0;

typedef enum {
    APP_MODE_LEVEL_CYCLE_1 = 0,     // Modo: ciclo de sensibilidad por botón 1
	APP_MODE_LEVEL_CYCLE_2,         // Modo: ciclo de sensibilidad por botón 2
	APP_MODE_LEVEL_CYCLE_3,         // Modo: ciclo de sensibilidad por botón 3
	APP_MODE_LEVEL_CYCLE_4,         // Modo: ciclo de sensibilidad por botón 4
    APP_MODE_INTENSITY_BY_TILT,     // Modo: variar brillo según inclinación
    APP_MODE_CUSTOM_ANIMATION,      // Ejemplo extra
    APP_MODE_COUNT                  // Cantidad total de modos
} AppMode_t;

static AppMode_t app_mode = APP_MODE_LEVEL_CYCLE_1;


static void app_nextSensitivityLevel(bool reset)
{
	if(reset){
		current_level = 0;
	}else{
		current_level = (current_level + 1)
				% (sizeof(acc_levels) / sizeof(acc_levels[0]));
	}

    level_config->acc_max_abs_val = acc_levels[current_level];

    // Mostrar por consola
    char buf[50];
    sprintf(buf, "Sensibilidad: ±%.2f g\r\n", acc_levels[current_level]);
    LOG(buf);
}

static void app_initLedMatrix() {
	LOG("INIT LEDMATRIX...");
	matrix_config.hspi = &hspi2;
	matrix_config.CS_GPIO_PORT = CS_PIN_GPIO_Port;
	matrix_config.CS_GPIO_PIN = CS_PIN_Pin;
	LedMatrix_setup(&matrix_config);
	if (LedMatrix_Init() != LEDMATRIX_OK) {
		LOG("ERROR\r\n");
		Error_Handler();
	}
	LOG("OK\r\n");
	app_nextSensitivityLevel(true);
}

static void app_initAcc(){
  LOG("INIT ACC...");

	acc_config.port.hi2c = &hi2c1;
	acc_config.port.ad0_state = false;
	acc_config.clk_source = MPU6050_CLK_PLL_XGYRO;    // Fuente de reloj estable
	acc_config.sample_rate_div = 0x07;                // 1kHz / (1 + 7) = 125Hz
	acc_config.dlpf_cfg = MPU6050_DLPF_10HZ;          // Filtro suave
	acc_config.gyro_range = MPU6050_GYRO_250DPS;
	acc_config.accel_range = MPU6050_ACCEL_2G; 		  // Mejor resolución para ±1g (inclinación)

	if (!mpu6050_Init(&acc_config)) {
		LOG("ERROR\r\n");
		Error_Handler();
	}
	LOG("OK\r\n");
}

static void app_do_level(){
	// mapear ac a la matriz
	AccelLevel_Map(level_config, x, y, &px, &py);

	//imprimir en matriz
	LedMatrix_Clear();
	LedMatrix_SetBlock(px, py, 1);
	LedMatrix_Refresh();
}

static void app_do_intensity(){
	AccelLevel_Map(level_config, x, y, &px, &py);
	LedMatrix_intensity(px);
}

static void app_do_custom_animation(){
	LedMatrix_SweepLeft_Circular();
	LedMatrix_Refresh();
}

void app_nextMode(void)
{
    app_mode = (app_mode + 1) % APP_MODE_COUNT;
    LOG("Modo cambiado a: ");
	switch (app_mode) {
	case APP_MODE_LEVEL_CYCLE_1:
		level_config = &block_config;
		app_nextSensitivityLevel(true);
		delayWrite(&app_delay, FAST_DELAY);
		break;
	case APP_MODE_LEVEL_CYCLE_2:
		app_nextSensitivityLevel(false);
		break;
	case APP_MODE_LEVEL_CYCLE_3:
		app_nextSensitivityLevel(false);
		break;
	case APP_MODE_LEVEL_CYCLE_4:
		app_nextSensitivityLevel(false);
		break;
	case APP_MODE_INTENSITY_BY_TILT:
		LOG("Brillo por inclinación\r\n");
		LedMatrix_LoadBitmap(BIT_MAP_FULL);
		level_config = &map_intensity;
		LedMatrix_Refresh();
		break;
	case APP_MODE_CUSTOM_ANIMATION:
		LedMatrix_intensity(LED_MATRIX_MAX_INTENISITY_VALUE);
		LedMatrix_LoadBitmap(BIT_MAP_SMILE);
		LedMatrix_Refresh();
		delayWrite(&app_delay, SLOW_DELAY);
		LOG("Animación custom\r\n")		;
		break;
	default:
		LOG("Desconocido\r\n");
		break;
	}
}



static void app_do() {
	if (delayRead(&app_delay)) {
		if (MPU6050_ReadAccel()) {

			// leer ac.
			if (app_mode != APP_MODE_CUSTOM_ANIMATION) {
				MPU6050_GetAccelG(&x, &y, &z);
			}

			switch (app_mode) {
				case APP_MODE_LEVEL_CYCLE_1:
				case APP_MODE_LEVEL_CYCLE_2:
				case APP_MODE_LEVEL_CYCLE_3:
				case APP_MODE_LEVEL_CYCLE_4:
					app_do_level();
					break;

				case APP_MODE_INTENSITY_BY_TILT: {
					app_do_intensity();
					break;
				}

				case APP_MODE_CUSTOM_ANIMATION: {
					app_do_custom_animation();
					break;
				}
				default: {
					app_nextMode();
					break;
				}
			}

			memset(bufstr, 0, size_bufstr);
			snprintf(bufstr, size_bufstr, "x: %f\ty: %f\tz: %f \t(%d,%d)\r",
					((int) (x * 100)) / 100.0, ((int) (y * 100)) / 100.0,
					((int) (z * 100)) / 100.0, px, py);

			LOG(bufstr);

			//volver a empezar delay
			delayRead(&app_delay);

		}else {
			LOG("ERROR\r");
		}
	}
}


void app_setup(){
    size_bufstr = sizeof(bufstr);
	level_config = &block_config;
	uartInit();
	app_initLedMatrix();
	app_initAcc();
	debounceFSM_init();
	delayInit(&app_delay, FAST_DELAY);

}

void app_run(){
	app_do();
	debounceFSM_update();
	if (readKey() == KEY_FALLING_EDGE_DETECTED) {
		app_nextMode();
	}

}
