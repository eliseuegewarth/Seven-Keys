/*
 * Implementation of the class that represents an operating system event.
 * Licença: LGPL. Sem copyright.
 */
#include "core/systemevent.h"

SystemEvent::SystemEvent(SystemEvent::Type type)
    : m_type(type)
{
}

SystemEvent::Type SystemEvent::type() const
{
    return m_type;
}

SystemEvent SystemEvent::from_SDL(const SDL_Event& event)
{
    if (event.type == SDL_QUIT)
    {
        return SystemEvent(SystemEvent::QUIT);
    }

    return SystemEvent(SystemEvent::UNKNOWN);
}
