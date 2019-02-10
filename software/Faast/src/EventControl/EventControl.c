/*
 * EventControl.c
 *
 *  Created on: 10 Feb 2019
 *      Author: pi
 */
#include "EventControl.h"
#include <stdio.h>


typedef struct
{
	bool	isEventRunning;
	pageActionPointer event;
} event;

event _event;

void EventControl_SetEventRunning(void)
{
	_event.isEventRunning = true;
}

void EventControl_ClearEventPending(void)
{
	_event.isEventRunning = false;
	_event.event = NULL;
}

bool EventControl_IsEventPending(void)
{
	return _event.isEventRunning;
}

void EventControl_SetEvent(pageActionPointer newEvent)
{
	_event.event = newEvent;
}

void EventControl_ExecuteEvent(void)
{
	_event.event();
}
