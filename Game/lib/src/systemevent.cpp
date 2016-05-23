/*
 * Implementation of the class that represents an operating system event.
 * Licença: LGPL. Sem copyright.
 */
#include "core/systemevent.h"

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param type [description]
 */
SystemEvent::SystemEvent(SystemEvent::Type type)   
{
	m_type = type;
}

/**
 * @brief [brief description]
 * @details [long description]
 * @return [description]
 */
SystemEvent::Type SystemEvent::type() const
{
    return m_type;
}

/**
 * @brief [brief description]
 * @details [long description]
 * 
 * @param event [description]
 * @return [description]
 */
SystemEvent SystemEvent::from_SDL(const SDL_Event& event)
{
    if (event.type == SDL_QUIT)
    {
        return SystemEvent(SystemEvent::QUIT);
    }

    return SystemEvent(SystemEvent::UNKNOWN);
}
