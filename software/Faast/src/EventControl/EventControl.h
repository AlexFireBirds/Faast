/*
 * EventControl.h
 *
 *  Created on: 10 Feb 2019
 *      Author: pi
 */

#ifndef EVENTCONTROL_EVENTCONTROL_H_
#define EVENTCONTROL_EVENTCONTROL_H_

#include <stdbool.h>
#include "../MenuLogic/MenuLogic.h"

void EventControl_SetEventRunning(void);

void EventControl_ClearEventPending(void);

bool EventControl_IsEventPending(void);

void EventControl_SetEvent(pageActionPointer newEvent);

void EventControl_ExecuteEvent(void);

#endif /* EVENTCONTROL_EVENTCONTROL_H_ */
