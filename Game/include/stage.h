/*
 * Exemplo de um nível: a tela de uma fase.
 *
 * Autor: Edson Alves
 * Data: 29/04/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef STAGE_H
#define STAGE_H

#include <core/level.h>
#include <core/rect.h>

#include "map.h"
#include "room.h"

class Player2;
class Map;

class Stage : public Level
{
public:
    Stage(ObjectID id);

    static ActionID colisionID;

private:
    Player2 *m_player;
    Map *m_map;

    void draw_self();
    void update_self(unsigned long);

    bool on_message(Object *object, MessageID id, Parameters p);
};

#endif
