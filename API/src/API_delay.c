#include "stm32f4xx_hal.h"

#include "API_delay.h"

void delayInit( delay_t * delay, tick_t duration ){
    if(delay == NULL || duration == 0)return;
    delay->duration = duration;
    delay->running = false;
    delay->startTime = 0;
}

bool_t delayRead( delay_t * delay ){
    if(delay == NULL)
        return false;

    if(!delay->running){
        delay->startTime = HAL_GetTick();
        delay->running = true;
        return false;
    }
    else{
        tick_t currentTime = HAL_GetTick();
        if((currentTime - delay->startTime) >= delay->duration){
            delay->running = false;
            return true;
        }
        else{
            return false;
        }
    }
}

void delayWrite( delay_t * delay, tick_t duration ){
    if(delay == NULL || duration == 0)return;
    delay->duration = duration;
}

bool_t delayIsRunning(delay_t * delay){
	if(delay == NULL)return false;
	return delay->running;
}
