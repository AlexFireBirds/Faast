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
#include "MenuLogic/MenuLogic.h"

int main(void)
{
	char inputBuffer[5];
	puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */


	while(1)
	{
		fgets(inputBuffer, 5, stdin);

		if(strcmp("d\n\0", inputBuffer) == 0)
		{
			printf("actual Page: %d ", MenuLogic_NextPage());
			printf("Text: %s", MenuLogic_ReturnMenuTextOfActualPage());
		}
		else if(strcmp("a\n\0", inputBuffer) == 0)
		{
			printf("actual Page: %d", MenuLogic_PreviousPage());
		}
		else if(strcmp("s\n\0", inputBuffer) == 0)
		{
			printf("Perform Action!");
			MenuLogic_ExecuteActualPageAction();
		}


//
//		printf("input: %s", inputBuffer);
//
//		printf("actual Page: %d", MenuLogic_NextPage());

	}


	system("omxplayer /home/pi/Faast/sounds/demo.wav");

	return EXIT_SUCCESS;
}
