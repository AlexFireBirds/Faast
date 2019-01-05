#include "GpioControl.h"
#include <wiringPi.h>


void GpioControl_Initialize(void)
{
	// Setup gpios
	wiringPiSetup();
	delay(500);

	// Initialize 'right arrow'
	pinMode(BUTTON_RIGHT_ARROW, INPUT);
}
