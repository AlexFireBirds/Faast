/*
 * ActionControl.c
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */
#include <stdlib.h>

void ActionControl_PerformSpaceOdyssey(void)
{
	system("omxplayer /home/pi/Faast/sounds/SpaceOdyssey.wav");
}

void ActionControl_PerformIAmYourFather(void)
{
	system("omxplayer /home/pi/Faast/sounds/IAmYourFather.wav");
}

void ActionControl_PerformBreathing(void)
{
	system("omxplayer /home/pi/Faast/sounds/Breathing.wav");
}
