#include "bsp.h"
#include "timer.h"

// exported global variables
volatile int Button_Status = 0;

/** @brief  Initialize I/O for lamps
    @retval None
*/
void BSP_Init(void)
{
}

/** @brief  Change lamps to GREEN
    @retval None
*/
void Signal_Pass(void)
{
	  int i;
	  for (i=1; i<=3 ; i++)
	  {  
			 WALK_SYMBOL_OFF();
			 Delay(5);
   		 WALK_SYMBOL_ON();
			 Delay(5);
		}
		WALK_SYMBOL_OFF();
		DONT_WALK_SYMBOL_ON();
		Delay(20);
    RED_OFF();
	  Delay(5);
	  GREEN_ON();
}

/** @brief  Change lamps to RED
    @retval None
*/
void Signal_Block(void)
{
		GREEN_OFF();
		Delay(5);
	  YELLOW_ON();
	  Delay(10);
	  YELLOW_OFF();
	  Delay(5);
		RED_ON();
	  Delay(20);
	  DONT_WALK_SYMBOL_OFF();
	  Delay(5);
	  WALK_SYMBOL_ON();
}

/** @brief  Flash YELLOW lamp
    @retval None
*/
void Signal_Flash(void)
{
    GREEN_OFF();
	  YELLOW_OFF();
	  RED_OFF();
	  DONT_WALK_SYMBOL_OFF();
	  WALK_SYMBOL_OFF();
		YELLOW_ON();
	  DONT_WALK_SYMBOL_ON();
		Delay(12);
		YELLOW_OFF();
	  DONT_WALK_SYMBOL_OFF();
		Delay(8);

}
