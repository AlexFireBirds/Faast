/*
 * MenuLogic.h
 *
 *  Created on: 3 Jan 2019
 *      Author: pi
 */
#ifndef MENULOGIC_MENULOGIC_H_
#define MENULOGIC_MENULOGIC_H_


/* === TYPES ======================================================================= */
typedef enum menuPages
{
	Home,
	ImFine,
	WhoAmI,
	SpaceOdyssey,
	Breathing,
	Father,
	Help,
	BeerOrder,
	FlyMeToTheMoon,
	FlyMeToTheMoonLong,
	RadlerOrder,
	SmirnoffOrder,
	MineralOrder,
	RegisterSound,
	Hello,
	NumberOfMenuPages
} MenuPages;

typedef void (*pageActionPointer)(void);

typedef struct
{
	MenuPages page;
	char text[32];
	pageActionPointer action;
} pageContent;


/* === PROTOTYPES ================================================================== */
void MenuLogic_NextPage(void);

void MenuLogic_PreviousPage(void);

char* MenuLogic_ReturnMenuTextOfActualPage(void);

void MenuLogic_ExecuteActualPageAction(void);

pageActionPointer MenuLogic_GetActualPageAction(void);

void MenuLogic_ShowAllMenuPages(void);


#endif /* MENULOGIC_MENULOGIC_H_ */
