#include "GpioControl.h"
#include <wiringPi.h>
#include <stdio.h>
#include "../MenuLogic/MenuLogic.h"

#define deboundeTime 150

unsigned long lastNextPageInterrupt = 0;

static void InterruptHandlerNextPage(void)
{
	unsigned long interruptTime = millis();
	if(interruptTime - lastNextPageInterrupt > deboundeTime)
	{
		MenuLogic_NextPage();
	}

	lastNextPageInterrupt = interruptTime;
}



void GpioControl_Initialize(void)
{
	// Setup gpios
	wiringPiSetup();
	delay(500);

	// Initialize 'right arrow'
	pinMode(BUTTON_RIGHT_ARROW, INPUT);

	// Setup interrupts
	if(!wiringPiISR(BUTTON_RIGHT_ARROW, INT_EDGE_FALLING, InterruptHandlerNextPage))
	{
		puts("GpioControl_Initialize successful");
	}
}



