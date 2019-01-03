/*
 * MenuLogic.h
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */

#ifndef MENULOGIC_MENULOGIC_H_
#define MENULOGIC_MENULOGIC_H_

typedef enum menuPages
{
	Home,
	SpaceOdyssey,
	InPeace,
	NumberOfMenuPages
} MenuPages;

typedef void (*pageActionPointer)(void);

typedef struct
{
	MenuPages page;
	char text[20];
	pageActionPointer action;
} pageContent;



MenuPages MenuLogic_NextPage(void);

MenuPages MenuLogic_PreviousPage(void);

char* MenuLogic_ReturnMenuTextOfActualPage(void);

void MenuLogic_ExecuteActualPageAction(void);

#endif /* MENULOGIC_MENULOGIC_H_ */
