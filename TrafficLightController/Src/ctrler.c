#include "ctrler.h"
#include "bsp.h"

Ctrler_State_t Ctrler_State = RESTART;
extern uint32_t Tick;

void Ctrler_Init()
{
}

uint32_t Ctrler_Exec(Event_t evt)
{
    uint32_t timeout_value = 0;
	  static uint32_t start_walk = 0;
	  static uint32_t start_count = 0;
	  static uint32_t lastgreen = 0;
	  
    
    switch(Ctrler_State) {
        case RESTART:
						Signal_Flash();
				    timeout_value = 10;
						if (evt == TIMEOUT) {
							Ctrler_State = THROUGH;
							GREEN_ON();
							lastgreen = Tick;
						}	
            break;
				case THROUGH:
						if (evt == BUTTON) {
							if (Tick - lastgreen > (MIN_GREEN_TIME_READ() ? 1200 : 600)) {
   								Ctrler_State = BLOCKED;
								  timeout_value = WALK_INTERVAL_READ() ? 200 : 100; 
								  start_count = timeout_value/10;
									Signal_Block();
								  start_walk = Tick;
							} 
							else {
								  Ctrler_State = WAIT;
								  timeout_value = (MIN_GREEN_TIME_READ() ? 1200 : 600) - (Tick - lastgreen);
								  printf("Pedestrian needs to wait for %d sec\n", timeout_value/10);
							}
						}
						else if (evt == MODE_CHANGE) {
								Ctrler_State = OUT_OF_SERVICE;
								Signal_Flash();
						}
						break;
				case WAIT:
					  if (evt == TIMEOUT) {
							Ctrler_State = BLOCKED;
 						  timeout_value = WALK_INTERVAL_READ() ? 200 : 100;
							start_count = timeout_value/10;
							Signal_Block();
					    start_walk = Tick;
						} 
						else if (evt == MODE_CHANGE) {
							Ctrler_State = OUT_OF_SERVICE;
							Signal_Flash();
						}
						break;
				case BLOCKED:
						if (evt == TIMEOUT) {
							Ctrler_State = THROUGH;
							Signal_Pass();
							lastgreen = Tick;
						}
						else if (evt == MODE_CHANGE) {
							Ctrler_State = OUT_OF_SERVICE;
							Signal_Flash();
						}
						else {
							if ((Tick-start_walk) % 10 == 0) {
									printf("%d\n",--start_count);
							}
					  }
						break;
				case OUT_OF_SERVICE:
//						if (evt == MODE_CHANGE) {
//							Ctrler_State = RESTART;
//						}
					  break;
        default:
            Ctrler_State = OUT_OF_SERVICE;
    }
    return timeout_value;
}
