#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif
    
#include "stm32f4xx_hal.h"
#include "main.h"

// exported global variables
extern volatile int Button_Status;

// exported macros
#define RED_ON()        HAL_GPIO_WritePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin, GPIO_PIN_SET)
#define RED_OFF()       HAL_GPIO_WritePin(RED_LAMP_GPIO_Port, RED_LAMP_Pin, GPIO_PIN_RESET)
#define YELLOW_ON()        HAL_GPIO_WritePin(YELLOW_LAMP_GPIO_Port, YELLOW_LAMP_Pin, GPIO_PIN_SET)
#define YELLOW_OFF()       HAL_GPIO_WritePin(YELLOW_LAMP_GPIO_Port, YELLOW_LAMP_Pin, GPIO_PIN_RESET)
#define GREEN_ON()        HAL_GPIO_WritePin(GREEN_LAMP_GPIO_Port, GREEN_LAMP_Pin, GPIO_PIN_SET)
#define GREEN_OFF()       HAL_GPIO_WritePin(GREEN_LAMP_GPIO_Port, GREEN_LAMP_Pin, GPIO_PIN_RESET)
#define WALK_SYMBOL_ON()        HAL_GPIO_WritePin(WALK_SYMBOL_GPIO_Port, WALK_SYMBOL_Pin, GPIO_PIN_SET)
#define WALK_SYMBOL_OFF()       HAL_GPIO_WritePin(WALK_SYMBOL_GPIO_Port, WALK_SYMBOL_Pin, GPIO_PIN_RESET)
#define DONT_WALK_SYMBOL_ON()        HAL_GPIO_WritePin(DONT_WALK_SYMBOL_GPIO_Port, DONT_WALK_SYMBOL_Pin, GPIO_PIN_SET)
#define DONT_WALK_SYMBOL_OFF()       HAL_GPIO_WritePin(DONT_WALK_SYMBOL_GPIO_Port, DONT_WALK_SYMBOL_Pin, GPIO_PIN_RESET)

#define MIN_GREEN_TIME_READ()     (HAL_GPIO_ReadPin(MIN_GREEN_TIME_GPIO_Port, MIN_GREEN_TIME_Pin) == SET)
#define WALK_INTERVAL_READ()     (HAL_GPIO_ReadPin(WALK_INTERVAL_GPIO_Port, WALK_INTERVAL_Pin) == SET)
#define OUT_OF_SERVICE_READ()     (HAL_GPIO_ReadPin(OUT_OF_SERVICE_GPIO_Port, OUT_OF_SERVICE_Pin) == SET)
    
// Function prototype
void BSP_Init(void);
void Signal_Pass(void);
void Signal_Block(void);
void Signal_Flash(void);

#ifdef __cplusplus
}
#endif

#endif // __BSP_H
