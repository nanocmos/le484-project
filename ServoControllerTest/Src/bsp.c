#include "bsp.h"

// exported global variables
volatile int ButtonSW1_Status = 0;
volatile int ButtonSW2_Status = 0;
volatile int ButtonSW3_Status = 0;


/** @brief  Generate PDM signal
    @retval None
*/
void PDM_Signal_Gen(TIM_HandleTypeDef *htimpt , uint32_t channelid, uint16_t period)
{
   __HAL_TIM_SET_AUTORELOAD(htimpt, period);
   __HAL_TIM_SET_COMPARE(htimpt, channelid, period/2);       
	
}

/** @brief  Capture Pulse Width
    @retval Pulse Width
*/
uint16_t Capture_Pulse_Width(TIM_HandleTypeDef *htimpt , uint32_t channelid)
{

   return  __HAL_TIM_GET_COMPARE(htimpt, channelid);       

}

/** @brief  Generate Voltage
    @retval None
*/
void Generate_Voltage(DAC_HandleTypeDef *hdacpt, uint32_t channel, uint32_t Alignment, uint32_t data)
{

    HAL_DAC_SetValue(hdacpt, channel, Alignment, data);
    HAL_DAC_Start(hdacpt, channel);
	
	
}

/** @brief  Read Voltage
    @retval Voltage
*/
uint16_t Read_Voltage(ADC_HandleTypeDef *hadcpt)
{
    HAL_ADC_Start(hadcpt);
    while(HAL_ADC_PollForConversion(hadcpt, 1000));
	
    return HAL_ADC_GetValue(hadcpt);
	
}

/** @brief  Send UART
    @retval None
*/
void Send_UART(UART_HandleTypeDef *huartpt, uint8_t *txt, uint16_t len)
{
    HAL_UART_Transmit_IT(huartpt, txt, len);
		
}

/** @brief  Receive UART
    @retval no of characters received
*/
uint16_t Receive_UART(UART_HandleTypeDef *huartpt, uint8_t *txt, uint16_t len)
{
    HAL_UART_Receive_IT(huartpt, txt, len);
	  
	  return strlen(txt);
		
}
