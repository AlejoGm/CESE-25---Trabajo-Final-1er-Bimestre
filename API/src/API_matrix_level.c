#include "API_matrix_level.h"
#define EDGE_TOLERANCE_PERCENT 5.0f

void AccelLevel_DefaultConfig(AccelMatrixLevelConfig_t *config)
{
    if (!config) return;

    config->acc_max_abs_val = 1.0f; // ±1g
    config->matrix_min_x = 1;
    config->matrix_max_x = 7;
    config->matrix_min_y = 1;
    config->matrix_max_y = 7;
    config->matrix_shift_x =0;
    config->matrix_shift_y =0;
    config->invert_x = false;
    config->invert_y = false;
}



static uint8_t MapAxis(float a, float a_max, uint8_t min_idx, uint8_t max_idx, bool invert, uint8_t shift) {
    float tol = (EDGE_TOLERANCE_PERCENT / 100.0f) * a_max;

    // Inversión si corresponde
    if (invert) a = -a;

    uint8_t range = max_idx - min_idx;
    if (range < 2) return min_idx + shift; // Nada para mapear, por seguridad

    uint8_t mapped = 0;
    if (a <= -a_max + tol) {
        mapped = min_idx;
    } else if (a >= a_max - tol) {
        mapped = max_idx;
    } else {
        // Mapeo lineal al rango interno (sin extremos)
        float middle_min = -a_max + tol;
        float middle_max = a_max - tol;
        float normalized = (a - middle_min) / (middle_max - middle_min); // [0,1]

        uint8_t internal_range = range - 2; // porque extremos están reservados
        mapped = min_idx + 1 + (uint8_t)(normalized * internal_range + 0.5f);

        // Protección extra por saturación numérica
        if (mapped >= max_idx) mapped = max_idx - 1;
    }

    return mapped + shift;
}

void AccelLevel_Map(const AccelMatrixLevelConfig_t *config, float ax, float ay, uint8_t *px, uint8_t *py) {
    if (!config || !px || !py) return;

    *px = MapAxis(ax, config->acc_max_abs_val, config->matrix_min_x, config->matrix_max_x,
                  config->invert_x, config->matrix_shift_x);

    *py = MapAxis(ay, config->acc_max_abs_val, config->matrix_min_y, config->matrix_max_y,
                  config->invert_y, config->matrix_shift_y);
}

//void AccelLevel_Map(const AccelMatrixLevelConfig_t *config, float ax, float ay, uint8_t *px, uint8_t *py)
//{
//    if (!config || !px || !py) return;
//
//    float norm_x = (ax + config->acc_max_abs_val) / (2.0f * config->acc_max_abs_val);
//    float norm_y = (ay + config->acc_max_abs_val) / (2.0f * config->acc_max_abs_val);
//
//    if (config->invert_x) norm_x = 1.0f - norm_x;
//    if (config->invert_y) norm_y = 1.0f - norm_y;
//
//    uint8_t steps_x = config->matrix_max_x - config->matrix_min_x - 1;// + 1;
//    uint8_t steps_y = config->matrix_max_y - config->matrix_min_y - 1;// + 1;
//
//    uint8_t raw_x = (uint8_t)(norm_x * steps_x);
//    uint8_t raw_y = (uint8_t)(norm_y * steps_y);
//
//    if (raw_x >= steps_x) raw_x = steps_x - 1;
//    if (raw_y >= steps_y) raw_y = steps_y - 1;
//
//    *px = config->matrix_min_x + raw_x;
//    *py = config->matrix_min_y + raw_y;
//}
//
