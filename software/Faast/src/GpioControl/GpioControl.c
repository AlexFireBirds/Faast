/*
 * GpioControl.c
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */

/* === INCLUDE FILES =============================================================== */
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GpioControl.h"
#include "../MenuLogic/MenuLogic.h"
#include "../EventControl/EventControl.h"


/* === DEFINES ===================================================================== */
#define debounceTime 500
#define debounceTimeAction 1000


/* === LOCAL VARIABLES ============================================================= */
unsigned long lastNextPageInterrupt  		 = 0;
unsigned long lastPreviousPageInterrupt   	 = 0;
unsigned long lastExecuteActionPageInterrupt = 0;


/* === DEFINITIONS ================================================================= */
static void InterruptHandlerNextPage(void)
{
	unsigned long interruptTime = millis();
	if(interruptTime - lastNextPageInterrupt > debounceTime)
	{
		MenuLogic_NextPage();
		if(digitalRead(BUTTON_ENTER) == 1 && digitalRead(BUTTON_LEFT_ARROW) == 1)
		{
			system("sudo reboot");
		}
	}

	lastNextPageInterrupt = interruptTime;
}

static void InterruptHandlerPreviousPage(void)
{
	unsigned long interruptTime = millis();
	if(interruptTime - lastPreviousPageInterrupt > debounceTime)
	{
		MenuLogic_PreviousPage();
		if(digitalRead(BUTTON_ENTER) == 1 && digitalRead(BUTTON_RIGHT_ARROW) == 0)
		{
			system("sudo reboot");
		}
	}

	lastPreviousPageInterrupt = interruptTime;
}

static void InterruptHandlerExecutePageAction(void)
{
	unsigned long interruptTime = millis();
	if(interruptTime - lastExecuteActionPageInterrupt > debounceTimeAction)
	{
		// Add event only if no event is already running
		if(!EventControl_IsEventPending())
		{
			EventControl_SetEventRunning();
			EventControl_SetEvent(MenuLogic_GetActualPageAction());
		}

		//MenuLogic_ExecuteActualPageAction();
		if(digitalRead(BUTTON_LEFT_ARROW) == 1 && digitalRead(BUTTON_RIGHT_ARROW) == 0)
		{
			system("sudo reboot");
		}
	}

	lastExecuteActionPageInterrupt = interruptTime;
}

void GpioControl_Initialize(void)
{
	bool successful = true;

	// Setup wiringPi
	wiringPiSetup();
	delay(500);

	// Initialize 'right arrow'
	pinMode(BUTTON_RIGHT_ARROW, INPUT);
	pinMode(BUTTON_LEFT_ARROW, INPUT);
	pinMode(BUTTON_ENTER, INPUT);


	// Setup interrupts, wiringPiIsr return 0 if successful
	if(wiringPiISR(BUTTON_RIGHT_ARROW, INT_EDGE_FALLING, InterruptHandlerNextPage))
	{
		successful = false;
	}

	if(wiringPiISR(BUTTON_LEFT_ARROW, INT_EDGE_RISING, InterruptHandlerPreviousPage))
	{
		successful = false;
	}

	if(wiringPiISR(BUTTON_ENTER, INT_EDGE_RISING, InterruptHandlerExecutePageAction))
	{
		successful = false;
	}

	if(successful)
	{
		puts("GpioControl_Initialize successful\n");
	}
	else
	{
		puts("GpioControl_Initialize failed\n");
	}
}



