/*
 * MenuLogic.c
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */
#include "MenuLogic.h"


#include <stdlib.h>

MenuPages initPage = Home;
MenuPages actualPage = Home;


void SpaceOdysseyAction(void)
{
	system("omxplayer /home/pi/Faast/sounds/SpaceOdyssey.wav");
}

void IAmYourFatherAction(void)
{
	system("omxplayer /home/pi/Faast/sounds/IAmYourFather.wav");
}


pageContent menu1[]={
	{Home, "Home", SpaceOdysseyAction},
	{SpaceOdyssey, "Space", SpaceOdysseyAction},
	{Father, "I am your father", IAmYourFatherAction}
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
	int numberOfMenuEntries = sizeof(menu1)/sizeof(pageContent);

	for(int i = 0; i < numberOfMenuEntries; i++)
	{
		if(menu1[i].page == actualPage)
		{
			return menu1[i].text;
		}
	}
	return "empty";
}

void MenuLogic_ExecuteActualPageAction(void)
{
	int numberOfMenuEntries = sizeof(menu1)/sizeof(pageContent);

	for(int i = 0; i < numberOfMenuEntries; i++)
	{
		if(menu1[i].page == actualPage)
		{
			menu1[i].action();
		}
	}
}
