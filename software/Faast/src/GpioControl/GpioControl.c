#include "GpioControl.h"
#include <wiringPi.h>
#include <stdio.h>
#include "../MenuLogic/MenuLogic.h"






void GpioControl_Initialize(void)
{
	// Setup gpios
	wiringPiSetup();
	delay(500);

	// Initialize 'right arrow'
	pinMode(BUTTON_RIGHT_ARROW, INPUT);

	if(!wiringPiISR(BUTTON_RIGHT_ARROW, INT_EDGE_FALLING, MenuLogic_NextPage))
	{
		puts("GpioControl_Initialize successfull");
	}
}



