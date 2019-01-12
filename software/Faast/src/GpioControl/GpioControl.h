/*
 * GpioControl.h
 *
 *  Created on: 5 Jan 2019
 *      Author: pi
 */

#ifndef GPIOCONTROL_GPIOCONTROL_H_
#define GPIOCONTROL_GPIOCONTROL_H_

/* === DEFINES ===================================================================== */
#define BUTTON_RIGHT_ARROW 7	// Physical pinout: 7
#define BUTTON_LEFT_ARROW  3	// Physical pinout: 15
#define BUTTON_ENTER       2	// Physical pinout: 13


/* === PROTOTYPES ================================================================== */
void GpioControl_Initialize(void);


#endif /* GPIOCONTROL_GPIOCONTROL_H_ */
