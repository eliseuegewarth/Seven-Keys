#include <core/rect.h>
#include <core/circle.h>
#include <core/keyboardevent.h>
#include <core/environment.h>
#include <core/level.h>

#include <iostream>

#include "item.hpp"
#include "map.hpp"
#include "room.h"
#include "player.h"
#include "stage.h"

using namespace std;

constexpr double SPEED { 300 };

class Player::SpriteState
{
public:
    virtual ~SpriteState() {}
    virtual void draw_self() {}
    virtual void update_self(unsigned long) {}
    virtual bool on_event(const KeyboardEvent&) { return false; }
};

class Idle : public Player::SpriteState
{
public:
    Idle(Player *parent,Animation* animation_idle) : m_parent(parent),
        m_animation(new Animation("res/sprites/idle.png", 0, 0, 41, 81, 1,
        400, true))
    {
        parent->set_dimensions(m_animation->w(), m_animation->h());
    }

    ~Idle() {}

    void draw_self()
    {
        m_animation->draw(m_parent->x(), m_parent->y());
    }

    void update_self(unsigned long elapsed)
    {
        m_animation->update(elapsed);

        short dir = m_parent->direction();

        if (dir >= 0)
        {
            m_parent->report_event(Player::MOVED);
            m_animation->set_row(dir);
        }
        
    }

private:
    Player *m_parent;
    unique_ptr<Animation> m_animation;
};

class Running : public Player::SpriteState
{
public:
    Running(Player *parent,Animation* animation_running) : m_parent(parent),
        m_animation(new Animation("res/sprites/running.png", 0, 0, 60,
        60, 8, 60, true))
    {
        parent->set_dimensions(m_animation->w(), m_animation->h());
    }

    ~Running() {}

    void draw_self()
    {
        m_animation->draw(m_parent->x(), m_parent->y());
    }

    void update_self(unsigned long elapsed)
    {
        m_animation->update(elapsed);

        short dir = m_parent->direction();

        if (dir == -1)
        {
            m_parent->report_event(Player::STOPPED);
        }else
        {
            m_animation->set_row(dir);
        }

        /*else if (dir < 0)
        {
            m_animation->set_row(0);
        } else
        {
            m_animation->set_row(1);
        }*/
    }

private:
    Player *m_parent;
    unique_ptr<Animation> m_animation;
};


Player::Player(Object *parent, ObjectID id,std::map<int,Animation*>actions, Map * current_map)
    : Object(parent, id), m_left(0), m_right(0), m_up(0), m_down(0), m_last(0), m_state(IDLE), current_map(current_map), key(false)
{
    Environment *env = Environment::get_instance();
    env->events_manager->register_listener(this);

    for (int state = IDLE; state < STATE_TOTAL; ++state)
    {
        m_states[state] = nullptr;

        for (int event = STOPPED; event < EVENT_TOTAL; ++event)
        {
            m_fst[state][event] = NONE;
        }
    }

    m_states[IDLE] = new Idle(this,actions[IDLE]);
    m_states[RUNNING] = new Running(this,actions[RUNNING]);

    m_fst[IDLE][MOVED] = RUNNING;
    m_fst[RUNNING][STOPPED] = IDLE;
}

Player::~Player()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);

    for (int state = IDLE; state < STATE_TOTAL; ++state)
    {
        delete m_states[state];
    }
}

bool
Player::on_event(const KeyboardEvent& event)
{
    switch (event.state())
    {
        case KeyboardEvent::PRESSED:
        switch (event.key())
        {
        case KeyboardEvent::LEFT:
                m_left = 1;
                return true;

            case KeyboardEvent::RIGHT:
                m_right = 1;
                return true;
                
            case KeyboardEvent::UP:
                m_up = 1;
                return true;
                
            case KeyboardEvent::DOWN:
                m_down = 1;
                return true;
                
            default:
                return false;
        }

        case KeyboardEvent::RELEASED:
        switch (event.key())
        {
            case KeyboardEvent::LEFT:
                m_left = 0;
                return true;

            case KeyboardEvent::RIGHT:
                m_right = 0;
                return true;
                
            case KeyboardEvent::UP:
                m_up = 0;
                return true;
                
            case KeyboardEvent::DOWN:
                m_down = 0;
                return true;
                
            default:
                return false;
        }

        default:
            break;
    }

    return false;
}

void
Player::draw_self()
{
    Environment * env = Environment::get_instance();

    Rect darkness {0,0,1280,720};
    Color m_fad, m_fad2;
    m_fad.set_a(230);
    env->canvas->set_blend_mode(Canvas::BLEND);
    env->canvas->fill(darkness, m_fad);

    Circle self_light{{x() + 30, y() + 30},100};
    m_fad2 = Color::WHITE;
    m_fad2.set_a(30);
    env->canvas->fill(self_light, m_fad2);

    m_states[m_state]->draw_self();
}

void
Player::update_self(unsigned long elapsed)
{
    m_states[m_state]->update_self(elapsed);

    if (not m_last)
    {
        m_last = elapsed;
    }

    double dx = m_left*(-SPEED) + m_right*SPEED;
    double x = this->x() + dx*((elapsed - m_last)/1000.0);
    
    double dy = m_up*(-SPEED) + m_down*SPEED;
    double y = this->y() + dy*((elapsed - m_last)/1000.0);

    m_last = elapsed;

    if (x < 0)
    {
        x = 0;
    }

    Environment *env = Environment::get_instance();
    if (x + w() > env->canvas->width())
    {
        x = env->canvas->width() - w();
    }

    if ((x == env->canvas->width() - w() and dx > 0) or 
        (x == 0 and dx < 0))
    {
        change_state(Player::IDLE, m_state);
    }
    
    if (y < 0)
    {
        y = 0;
    }

    if (y + h() > env->canvas->height())
    {
        y = env->canvas->height() - h();
    }

    if ((y == env->canvas->height() - h() and dy > 0) or 
        (y == 0 and dy < 0))
    {
        change_state(Player::IDLE, m_state);
    }

    set_x(x);
    set_y(y);


    /* Colisao com as portas */
    int posx,posy;
    posx = (int) x;
    posy = (int) y;

    if(posx <= 1 && ( posy >= 280 && posy <= 420) && current_map->current_room->r_left)
    {

        enter_room(current_map->current_room, current_map->current_room->r_left, 1120, posy);
    }
    else if(posx >= 1200 && ( posy >= 280 && posy <= 420) && current_map->current_room->r_right)
    {

        enter_room(current_map->current_room, current_map->current_room->r_right, 80, posy);
    }
    else if(posy <= 1  && ( posx >= 600 && posx <= 680) && current_map->current_room->r_top)
    {

        enter_room(current_map->current_room, current_map->current_room->r_top, posx, 580);
    }
    else if(posy >= 620  && ( posx >= 600 && posx <= 680) && current_map->current_room->r_bottom)
    {

        enter_room(current_map->current_room, current_map->current_room->r_bottom, posx, 80);
    }



    /*Colisoes com os items */
    vector <Item*> aux = current_map->current_room->items;

    for(int i = 0; i < aux.size(); i++)
    {
        if(aux[i]->type == "key")
        {
            if (((posx + 40 > aux[i]->x()) && (posx + 40 < (aux[i]->x() + 32))) && ((posy + 40> aux[i]->y()) && (posy + 40 < (aux[i]->y() + 32))))
            {
                current_map->current_room->remove_child(aux[i]);
                cout << "peguei a chave" << endl;
                pick_key();
            } 
        }
        else if(aux[i]->type == "finaldoor")
        {
            if(has_key())
            {
                if (((posx + 40 > aux[i]->x()) && (posx + 40 < (aux[i]->x() + 80))) && ((posy + 40> aux[i]->y()) && (posy + 40 < (aux[i]->y() + 80))))
                {
                    cout << "você ganhou o jogo!" << endl;
                    drop_key();
                    //Passa pro prox level
                    Level *next_level = new Level("stage","stage2");
                    next_level->set_next("stage2");
                } 
            }
        }
    }
}

void
Player::enter_room(Room * anterior, Room * nova, int posx, int posy)
{
    set_position(posx, posy);
    current_map->enter_room(anterior, nova);
    
}

void
Player::report_event(Event event)
{
    State next = m_fst[m_state][event];

    if (next != m_state and next != NONE)
    {
        change_state(next, m_state);
        m_last = 0;
    }
}

void
Player::change_state(State to, State)
{
    m_state = to;
}

short
Player::direction() const
{
    if(m_left)
        return 0;
    else if(m_up)
        return 1;
    else if(m_right)
        return 2;
    else if(m_down)
        return 3;
    else
        return -1;
}

bool
Player::has_key()
{
    return key;
}

void
Player::pick_key()
{
    this->key = true;
}
void
Player::drop_key()
{
    this->key = false;
}