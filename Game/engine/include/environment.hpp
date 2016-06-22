/*
 * Singleton que contém as variáveis globais da engine.
 *
 * Autor: Edson Alves
 * Data: 06/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "exception.hpp"
#include "video.hpp"
#include "canvas.hpp"
#include "resourcesmanager.hpp"
#include "eventsmanager.hpp"

class Environment
{
public:
    ~Environment();

    static Environment * get_instance() throw (Exception);
    static void release_instance();

    Video *video;
    Canvas *canvas;
    ResourcesManager *resources_manager;
    EventsManager *events_manager;

private:
    Environment();
    void init() throw (Exception);
};

#endif
