
#ifndef _API_DELAY_
#define _API_DELAY_

#include <stdint.h>
#include <stdbool.h>

typedef uint32_t tick_t;
typedef bool bool_t;
typedef struct{
   tick_t startTime;
   tick_t duration;
   bool_t running;
} delay_t;

// Punto 3 - patrón de parpadeo
typedef struct {
    tick_t period;      // Periodo total en ms
    tick_t dutyCycle;   // Tiempo encendido en ms (ciclo de trabajo)
    uint8_t repeat;     // Cantidad de repeticiones del patrón
} blinkPattern_t;

/**
 * @brief Inicializa una estructura de retardo no bloqueante.
 *
 * Esta función configura un retardo con una duración específica.
 * No inicia el conteo; simplemente carga el valor de duración
 * y deja el flag `running` en falso.
 *
 * @param delay     Puntero a la estructura delay_t a inicializar.
 * @param duration  Duración del retardo en milisegundos.
 */
void delayInit(delay_t * delay, tick_t duration);

/**
 * @brief Cambia la duración de un retardo existente.
 *
 * Modifica el campo `duration` de la estructura sin reiniciar el estado del retardo.
 * No afecta a `running` ni reinicia el conteo.
 *
 * @param delay     Puntero a la estructura delay_t.
 * @param duration  Nueva duración del retardo en milisegundos.
 */
void delayWrite(delay_t * delay, tick_t duration);

/**
 * @brief Verifica si el tiempo del retardo ha transcurrido.
 *
 * Si el retardo no está corriendo, lo inicia. Si ya está corriendo,
 * calcula si se cumplió el tiempo de duración. Si se cumplió,
 * reinicia `running` a falso y devuelve `true`.
 *
 * @param delay  Puntero a la estructura delay_t.
 * @return `true` si el tiempo se cumplió, `false` si no.
 */
bool_t delayRead(delay_t * delay);

/**
 * @brief Informa si un retardo está corriendo actualmente.
 *
 * Devuelve el estado actual del flag `running` de la estructura delay.
 * Es útil para evitar modificar el retardo mientras está en ejecución.
 *
 * @param delay  Puntero a la estructura delay_t.
 * @return `true` si el retardo está activo, `false` si no.
 */
bool_t delayIsRunning(delay_t * delay);


#endif
