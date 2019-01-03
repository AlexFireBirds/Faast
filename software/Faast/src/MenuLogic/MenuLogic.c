/*
 * MenuLogic.c
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */
#include <stdio.h>
#include "MenuLogic.h"
#include "../ActionControl/ActionControl.h"

int _actualPageIndex = 0;


pageContent menu[]={
	{Home, 			"Home ", 				ActionControl_PerformSpaceOdyssey},
	{SpaceOdyssey, 	"Space ", 				ActionControl_PerformSpaceOdyssey},
	{Breathing, 	"Breath like Vader ",	ActionControl_PerformBreathing},
	{Father, 		"I am your father ", 	ActionControl_PerformIAmYourFather},
	{Help, 			"Help ", 				MenuLogic_ShowAllMenuPages}
};


void MenuLogic_NextPage(void)
{
	int numberOfMenuPages = sizeof(menu)/sizeof(pageContent);

	_actualPageIndex++;

	if(_actualPageIndex == numberOfMenuPages)
	{
		_actualPageIndex = 0;
	}
}

void MenuLogic_PreviousPage(void)
{
	int numberOfMenuPages = sizeof(menu)/sizeof(pageContent);

	if(_actualPageIndex == 0)
	{
		_actualPageIndex = numberOfMenuPages - 1;
	}
	else
	{
		_actualPageIndex--;
	}
}


char* MenuLogic_ReturnMenuTextOfActualPage(void)
{
	return menu[_actualPageIndex].text;
}

void MenuLogic_ExecuteActualPageAction(void)
{
	menu[_actualPageIndex].action();
}

void MenuLogic_ShowAllMenuPages(void)
{
	int numberOfMenuEntries = sizeof(menu)/sizeof(pageContent);

	for(int i = 0; i < numberOfMenuEntries; i++)
	{
		printf("Page: %d: %s \n", menu[i].page, menu[i].text);
	}
}
