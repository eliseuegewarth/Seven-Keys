/*
 * Class which represents an operating system event listener.
 *
 * Licença: LGPL. Sem copyright.
 */
#ifndef SYSTEM_EVENT_LISTENER_H
#define SYSTEM_EVENT_LISTENER_H

class SystemEvent;

class SystemEventListener
{
	public:
	    virtual bool onSystemEvent(const SystemEvent& event) = 0;
};

#endif
