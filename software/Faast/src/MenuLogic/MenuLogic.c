/*
 * MenuLogic.c
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */
#include <stdio.h>
#include "MenuLogic.h"
#include "../ActionControl/ActionControl.h"

MenuPages initPage = Home;
MenuPages actualPage = Home;

pageContent menu[]={
	{Home, "Home", ActionControl_PerformSpaceOdyssey},
	{SpaceOdyssey, "Space", ActionControl_PerformSpaceOdyssey},
	{Breathing, "Breath like Vader",ActionControl_PerformBreathing},
	{Father, "I am your father", ActionControl_PerformIAmYourFather},
	{Help, "Help", MenuLogic_ShowAllMenuPages}
};



MenuPages MenuLogic_NextPage(void)
{
	actualPage++;
	if(actualPage == NumberOfMenuPages)
	{
		actualPage = Home;
	}
	return actualPage;
}

MenuPages MenuLogic_PreviousPage(void)
{
	if(actualPage == Home)
	{
		actualPage = NumberOfMenuPages - 1;
	}
	else
	{
		actualPage--;
	}
	return actualPage;
}


char* MenuLogic_ReturnMenuTextOfActualPage(void)
{
	int numberOfMenuEntries = sizeof(menu)/sizeof(pageContent);

	for(int i = 0; i < numberOfMenuEntries; i++)
	{
		if(menu[i].page == actualPage)
		{
			return menu[i].text;
		}
	}
	return "No menu entry!";
}

void MenuLogic_ExecuteActualPageAction(void)
{
	int numberOfMenuEntries = sizeof(menu)/sizeof(pageContent);

	for(int i = 0; i < numberOfMenuEntries; i++)
	{
		if(menu[i].page == actualPage)
		{
			menu[i].action();
		}
	}
}

void MenuLogic_ShowAllMenuPages(void)
{
	int numberOfMenuEntries = sizeof(menu)/sizeof(pageContent);

	for(int i = 0; i < numberOfMenuEntries; i++)
	{
		printf("Page: %d: %s \n", menu[i].page, menu[i].text);
	}
}
