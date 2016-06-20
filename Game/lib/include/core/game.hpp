/*
 * Classe que representa um jogo.
 *
 * Autor: Edson Alves
 * Data: 26/03/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef GAME_H
#define GAME_H

#include "core/level.hpp"
#include "core/listener.hpp"
#include "core/exception.hpp"

#include <string>

using std::string;

class Environment;
class SystemEvent;
class KeyboardEvent;


class Game : public Listener
{
public:
    Game(const string& id);
    virtual ~Game();

    void init(const string& title, unsigned const int w = 0, unsigned const int h = 0,
              double scale = 1.0, bool fullscreen = false, 
              unsigned int volume = 50) throw (Exception);

    void init(const string& settings) throw (Exception);
    void run();

    bool on_event(const SystemEvent& event);
    bool on_event(const KeyboardEvent& event);

protected:
    string m_id; //Map identifier file.
    Level *m_level; //Stores the game levels.
    bool m_done; //Stores if it was create or not the level.
    Environment *env; //It is an object of the class environment. 
                      //Is a pointer to the current instance of the game environment.

    virtual Level * load_level(const string& id);

    unsigned long update_timestep() const;
    void process_input();
    void update_screen();
    void delay(unsigned long ms);
};

#endif
