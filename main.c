#include <stdint.h>
#include <Board_LED.h>
#include "Board_Buttons.h"

//delay(int) takes an int and delays for 100,000 x wait_time
void delay(int wait_time) {
	uint32_t i = 0;
	long total_time = wait_time * 100000;
	for(i = 0; i < total_time; ++i);
}

int main(void) {
	LED_Initialize();
	Buttons_Initialize();
	
	while(1) {
		//Buttons_GetState() returns 1 if the button is pressed.
		if(Buttons_GetState() == 1) {
			//If button is pressed: toggle LED!
			LED_On(0);
			delay(5);
			LED_Off(0);
			delay(5);
		}
	}
	
	return 0;
}
