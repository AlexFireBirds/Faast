/*
 * LcdDriver.h
 *
 *  Created on: 12 Jan 2019
 *      Author: pi
 */

#ifndef LCDDRIVER_LCDDRIVER_H_
#define LCDDRIVER_LCDDRIVER_H_

void LcdDriver_Initialize(void);

int LcdDriver_Test(void);

void LcdDriver_Clear(void);

void LcdDriver_Write(const char *s);

#endif /* LCDDRIVER_LCDDRIVER_H_ */
