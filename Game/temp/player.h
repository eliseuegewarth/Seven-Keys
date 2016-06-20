#ifndef PLAYER_H
#define PLAYER_H

#include <core/object.h>
#include <core/keyboardevent.h>
#include <core/animation.h>
#include <core/listener.h>


#include "map.hpp"

#include <memory>
#include <map>

using std::unique_ptr;

class Player : public Object, Listener
{
public:
    Player(Object *parent, ObjectID id, std::map<int,Animation*> actions, Map * current_map);
    ~Player();

    bool on_event(const KeyboardEvent& event);

    class SpriteState;

    typedef enum _State
    {
        NONE,
        IDLE,
        RUNNING,
        JUMPING,
        FAINTING,
        DIZZYING,
        SLIDING,
        STATE_TOTAL,
    } State;

    typedef enum _Event
    {
        STOPPED,
        MOVED,
        JUMPED,
        SLIDED,
        HITTED,
        FAINTED,
        EVENT_TOTAL,
    } Event;

    short direction() const;

    void report_event(Event event);
    void change_state(State to, State from);

    bool has_key();
    void pick_key();
    void drop_key();
protected:
    short m_left, m_right, m_up, m_down;
    unsigned long m_last;
    Map *current_map;
    
    //Status do personagem
    int health, sanity, stamina;
    bool key;
     

    State m_state;
    State m_fst[STATE_TOTAL][EVENT_TOTAL];
    SpriteState * m_states[STATE_TOTAL];

    void enter_room(Room *, Room *, int, int);
    void draw_self();
    void update_self(unsigned long elapsed);
};

#endif
