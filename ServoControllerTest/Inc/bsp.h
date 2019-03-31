#ifndef __BSP_H
#define __BSP_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_hal.h"
#include "main.h"

// exported global variables
extern volatile int ButtonSW1_Status;
extern volatile int ButtonSW2_Status;
extern volatile int ButtonSW3_Status;

	
// exported macros
	
#define DIPSW1_READ()     (HAL_GPIO_ReadPin(DIPSW1_GPIO_Port, DIPSW1_Pin) == SET)
#define DIPSW2_READ()     (HAL_GPIO_ReadPin(DIPSW2_GPIO_Port, DIPSW2_Pin) == SET)
#define DIPSW3_READ()     (HAL_GPIO_ReadPin(DIPSW3_GPIO_Port, DIPSW3_Pin) == SET)
#define DIPSW4_READ()     (HAL_GPIO_ReadPin(DIPSW4_GPIO_Port, DIPSW4_Pin) == SET)

// Function prototype
	
void PDM_Signal_Gen(TIM_HandleTypeDef *htimpt , uint32_t channelid, uint16_t period);
uint16_t Capture_Pulse_Width(TIM_HandleTypeDef *htimpt , uint32_t channelid);
void Generate_Voltage(DAC_HandleTypeDef *hdacpt, uint32_t channel, uint32_t Alignment, uint32_t data);
uint16_t Read_Voltage(ADC_HandleTypeDef *hadcpt);
void Send_UART(UART_HandleTypeDef *huartpt, uint8_t *txt, uint16_t len);
uint16_t Receive_UART(UART_HandleTypeDef *huartpt, uint8_t *txt, uint16_t len);
	
#ifdef __cplusplus
}
#endif

#endif


