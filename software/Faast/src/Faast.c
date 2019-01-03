/*
 ============================================================================
 Name        : Faast.c
 Author      : cha
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include "MenuLogic/MenuLogic.h"


int main(void)
{
	char inputBuffer[5];
	puts("Project Faast, have fun:");


	// Setup gpios
	//wiringPiSetupGpio();

	wiringPiSetupGpio();






	while(1)
	{
		fgets(inputBuffer, 5, stdin);

		if(strcmp("d\n\0", inputBuffer) == 0)
		{
			MenuLogic_NextPage();
			printf("%s", MenuLogic_ReturnMenuTextOfActualPage());
		}
		else if(strcmp("a\n\0", inputBuffer) == 0)
		{
			MenuLogic_PreviousPage();
			printf("%s", MenuLogic_ReturnMenuTextOfActualPage());
		}
		else if(strcmp("s\n\0", inputBuffer) == 0)
		{
			printf("\nPerform Action!\n");
			MenuLogic_ExecuteActualPageAction();
		}
		else if(strcmp("h\n\0", inputBuffer) == 0)
		{
			MenuLogic_ShowAllMenuPages();
		}
	}

	return EXIT_SUCCESS;
}
