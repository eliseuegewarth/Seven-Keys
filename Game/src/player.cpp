/*
 * Implementação da classe Player.
 */
#include "player.hpp"
#include "core/rect.hpp"
#include "core/level.hpp"
#include "core/environment.hpp"
#include "core/keyboardevent.hpp"
//#include "pause.hpp"


#include <cassert>
#include <string>

ActionID Player::hitExitDoorID { "hitExitDoorID()" };
ActionID Player::jumpNextLevelID { "jumpNextLevelID()" };
ActionID Player::takeItemID { "takeItemID()" };
ActionID Player::openDoorID { "openDoorID()" };
ActionID Player::pushItemID { "pushItemID()" };
ActionID Player::repeatLevelID { "repeatLevelID()" };
ActionID Player::changeRoomID { "changeRoomID()" };
ActionID Player::getHitID { "getHitID()" };
using std::make_pair;

class Player::Impl
{
public:
    Impl(Player *player, bool key)
        : m_sanity_loss(0), m_player(player), m_direction(Player::LEFT),
        m_moviment(make_pair(0.0, 0.0)),
        m_key(key), m_strength(0.0), m_health(100.0), m_sanity(100.0), m_stamina(100.0),
        m_pill(0), m_hweapon(false), m_weapon(nullptr), m_secondary(false), m_damage(50),
        m_life(5)
    {
    }

    int m_sanity_loss;
    Direction direction() const { return m_direction; }
    void set_direction(Direction direction) { m_direction = direction; }

    const pair<double, double>& moviment() const { return m_moviment; }

    void set_moviment(double horizontal_axis, double vertical_axis)
    {
        m_moviment = make_pair(horizontal_axis, vertical_axis);
    }

    void set_current(string nova, int posx, int posy)
    {
        m_player->set_horizontal_position(posx);
        m_player->set_vertical_position(posy);
        m_player->notify(changeRoomID, nova);
    }

    void set_strength(double strength)
    {
        m_strength = strength;
    }

    double strength()
    {
        return m_strength;
    }

    void set_health(double health)
    {
        m_health = health;
    }

    double health()
    {
        return m_health;
    }

    void set_sanity(double sanity)
    {
        m_sanity = sanity;
    }

    double sanity()
    {
        return m_sanity;
    }
    double stamina()
    {
        return m_stamina;
    }

    void set_stamina(double stamina)
    {
        m_stamina = stamina;
    }

    double damage()
    {
        return m_damage;
    }

    void get_pill(string id)
    {

        const list<Object *> items = m_player->children();
        for (auto item : items)
        {
            if(strstr(item->id().c_str(), "Pill"))
            {
                m_player->remove_child(item);
            }
        }

        Environment *env = Environment::get_instance();

        cout << "id da pill" << id << endl;

        if(id == "Pill1")
        {
            m_pill = 1;
        }

        else if (id == "Pill2")
        {
            m_pill = 2;
        }

        char path[256];
        sprintf(path, "res/items/thumb.%s.png", id.c_str());
        Item* pill = new Item(m_player, "icon_pill", path, (double)env->canvas->width() * 1/35 + 2, (double)env->canvas->height() * 25/30 + 2, 9999, true);
        m_player->add_child(pill);
    }

    void get_weapon(string weapon_id)
    {
        if(m_hweapon == true)
            return;

        Environment *env = Environment::get_instance();
        double size = env->canvas->width()/35;

        m_hweapon = true;

        char weapon_path[256];
        sprintf(weapon_path, "res/items/thumb.%s.png", weapon_id.c_str());
        Item* lWeapon = new Item(m_player, "icon_weapon", weapon_path, (double)env->canvas->width() * 1/35 + 2 + (2*size), (double)env->canvas->height() * 25/30 + 2, 9999, true);
        m_player->add_child(lWeapon);

        if(weapon_id == "Garrafa")
        {
            Weapon* weapon = new Weapon(m_player, "icon_weapon", weapon_path, 3, 34.0, 5);
            m_weapon = weapon;
            //m_player->add_child(m_weapon);
        }

        if(weapon_id == "Faca")
        {
            Weapon* weapon = new Weapon(m_player, "icon_weapon", weapon_path, 5, 60.0, 5);
            m_weapon = weapon;
            //m_player->add_child(m_weapon);
        }

        if(weapon_id == "Cacetete")
        {
            Weapon* weapon = new Weapon(m_player, "icon_weapon", weapon_path, 7, 33.0, 5);
            m_weapon = weapon;
            //m_player->add_child(m_weapon);
        }
    }

    void get_key()
    {
        if(m_key == true)
            return;

        Environment *env = Environment::get_instance();
        double size = env->canvas->width()/35;

        m_key = true;

        Item* key = new Item(m_player, "icon_key", "res/items/thumb.key.png", (double)env->canvas->width() * 1/35 + size + 2, (double)env->canvas->height() * 25/30 + size + 2, 9999, true);
        m_player->add_child(key);
    }
    void set_key(bool input)
    {
        m_key = input;
    }
    bool has_key()
    {
        return m_key;
    }
    void show_health()
    {
        Environment *env = Environment::get_instance();
        Rect healthbar {(double)env->canvas->width()/15, (double)env->canvas->height()/24, m_player->health()*2, 12};
        env->canvas->fill(healthbar, Color::RED);
        Rect borda {(double)env->canvas->width()/15, (double)env->canvas->height()/24, 100*2, 12};
        env->canvas->draw(borda, Color::RED);
    }
    void show_sanity()
    {
        Environment *env = Environment::get_instance();
        Rect sanitybar {(double)env->canvas->width()/15, (double)env->canvas->height()/17, m_player->sanity()*2, 12};
        env->canvas->fill(sanitybar, Color::GREEN);
        Rect borda {(double)env->canvas->width()/15, (double)env->canvas->height()/17, 100*2, 12};
        env->canvas->draw(borda, Color::GREEN);
    }
    void show_stamina()
    {
        Environment *env = Environment::get_instance();
        double stamina = m_player->stamina()*2;

        if(stamina < 0)
            stamina = 0;

        Rect staminabar {(double)env->canvas->width()/15, (double)env->canvas->height()/13, stamina, 12};
        env->canvas->fill(staminabar, Color::YELLOW);
        Rect borda {(double)env->canvas->width()/15, (double)env->canvas->height()/13, 100*2, 12};
        env->canvas->draw(borda, Color::YELLOW);
    }

    void show_inventory()
    {
        Environment *env = Environment::get_instance();
        double size = env->canvas->width()/35;

        Rect item1 {(double)(env->canvas->width() * 1/35), (double)env->canvas->height() * 25/30, size, size};
        Rect item2 {(double)env->canvas->width() * 1/35 + size, (double)env->canvas->height() * 25/30 - size, size, size};
        Rect item3 {(double)env->canvas->width() * 1/35 + 2*size, (double)env->canvas->height() * 25/30, size, size};
        Rect item4 {(double)env->canvas->width() * 1/35 + size, (double)env->canvas->height() * 25/30 + size, size, size};
        Rect not_item {(double)env->canvas->width() * 1/35 + size, (double)env->canvas->height() * 25/30, size, size};
        env->canvas->draw(item1, Color::WHITE);
        env->canvas->draw(item2, Color::WHITE);
        env->canvas->draw(item3, Color::WHITE);
        env->canvas->draw(item4, Color::WHITE);
        env->canvas->fill(not_item, Color::WHITE);
    }


    void use_pill()
    {
        if(m_pill == 1)
        {
            double recover = 35;
            m_player->set_health(m_player->health() + recover);
            if(m_player->health() > 100)
                m_player->set_health(100);

            cout << "usou uma pilula! Recuperou " << recover << " de vida." << endl;

            const list<Object *> items = m_player->children();
            for (auto item : items)
            {
                if(item->id() == "icon_pill")
                {
                    m_pill = 0;
                    m_player->remove_child(item);
                }
            }
        }
        else if(m_pill == 2)
        {
            double recover = 35;
            m_player->set_sanity(m_player->sanity() + recover);
            if(m_player->sanity() > 100)
                m_player->set_sanity(100);

            cout << "usou uma pilula! Recuperou " << recover << " de sanidade." << endl;

            const list<Object *> items = m_player->children();
            for (auto item : items)
            {
                if(item->id() == "icon_pill")
                {
                    m_pill = 0;
                    m_player->remove_child(item);
                }
            }
        }
    }

    void use_weapon()
    {
        if(m_weapon)
        {
            cout << "Usou a arma!" << endl;


        }
    }

    void take_item()
    {
        m_player->notify(takeItemID, "take_item");
    }
    void jump_level()
    {
        m_player->notify(jumpNextLevelID, "next_level");
    }
    void open_door()
    {
        m_player->notify(openDoorID, "open_door");
    }
    void push_item()
    {
        m_player->notify(pushItemID, "push_item");
    }
    void you_died()
    {
        m_player->notify(repeatLevelID, "you_died");
    }
    void hit()
    {
        char message[256];
        double dmg_total;

        if(m_hweapon != false)
            dmg_total = m_weapon->m_damage;
        else
            dmg_total = m_player->damage();
        sprintf(message,"%f", dmg_total);
        m_player->notify(getHitID, message);

        const list<Object *> filhos = m_player->children();

        for (auto filho : filhos)
        {
            if(filho->id() == "visao")
            {
                m_player->remove_child(filho);
            }
        }

        if(direction() == Player::RIGHT)
        {
            Sight *visao = new Sight(m_player, "visao", m_player->horizontal_position()+40, m_player->vertical_position() + m_player->height()/4, 100, 40);
            m_player->add_child(visao);
        }
        else if(direction() == Player::LEFT)
        {
            Sight *visao = new Sight(m_player, "visao", m_player->horizontal_position() - 70, m_player->vertical_position() + m_player->height()/4, 100, 40);
            m_player->add_child(visao);
        }
        else if(direction() == Player::UP)
        {
            Sight *visao = new Sight(m_player, "visao", m_player->horizontal_position() + m_player->width()/4, m_player->vertical_position() - 70, 40, 100);
            m_player->add_child(visao);
        }
        else if(direction() == Player::DOWN)
        {
            Sight *visao = new Sight(m_player, "visao", m_player->horizontal_position()+ m_player->width()/4, m_player->vertical_position() + 40, 40, 100);
            m_player->add_child(visao);
        }
    }

    int life()
    {
        return m_life;
    }
    void set_life(int life)
    {
        m_life = life;
    }
    void die()
    {
        set_life(life() - 1);
    }


private:
    Player *m_player;
    Direction m_direction;
    pair<double, double> m_moviment;
    bool m_key;
    double m_strength;
    double m_health;
    double m_sanity;
    double m_stamina;
    int m_pill;
    bool m_hweapon;
    Weapon* m_weapon;
    bool m_secondary;
    double m_damage;
    int m_life;
};

class Idle : public SpriteState
{
public:
    Idle(Player *player)
        : m_player(player), m_animation(new Animation("res/sprites/idle.png",
            0, 0, 70, 70, 2, 1000, true)), m_left(0), m_right(0), m_top(0),
        m_down(0), m_running(false)
    {
    }

    ~Idle() {}

    void enter(int)
    {
        m_player->set_dimensions(m_animation->width(), m_animation->height());
        m_right = m_left = m_down = m_top = 0;
    }

    void leave(int)
    {
    }

    bool on_event(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 1;
                return true;

            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 1;
                return true;

            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_top = 1;
                return true;

            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 1;
                return true;

            case KeyboardEvent::L:
                m_running = true;
                return true;

            case KeyboardEvent::Q:
                m_player->use_pill();
                return true;

            case KeyboardEvent::E:
                m_player->open_door();
                return true;

            case KeyboardEvent::K:
                m_player->take_item();
                return true;

            case KeyboardEvent::C:
                m_player->report_event(Player::DUCKING);
                return true;

            case KeyboardEvent::J:
                m_player->hit();
                return true;

            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 0;
                return true;

            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 0;
                return true;

            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_top = 0;
                return true;

            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 0;
                return true;

            case KeyboardEvent::L:
                m_running = false;
                return true;

            case KeyboardEvent::P:
                m_player->jump_level();
                return true;

            case KeyboardEvent::K:
                m_player->take_item();
                return true;

            default:
                break;
            }
            break;
        }

        return false;
    }

    void draw()
    {
        m_animation->draw(m_player->horizontal_position(), m_player->vertical_position());
        m_player->show_health();
        m_player->show_sanity();
        m_player->show_inventory();
        m_player->show_stamina();
    }

    void update(unsigned long elapsed)
    {
        if(m_player->health() < 1)
            m_player->you_died();

        if(m_player->stamina() < 100)
        {
            m_player->set_stamina(m_player->stamina() + 0.05);
            if(m_player->stamina() > 100)
                m_player->set_stamina(100);
        }


        if(! m_player->m_sanity_loss)
            m_player->m_sanity_loss = elapsed;

        if(elapsed - m_player->m_sanity_loss > 3000)
        {
            m_player->set_sanity(m_player->sanity() - 1);
            if(m_player->sanity() < 0)
                m_player->set_sanity(0);
            m_player->m_sanity_loss = elapsed;
        }
        if (m_left)
        {
            m_player->set_moviment(-1.0, 0.0);
            m_player->set_direction(Player::LEFT);
            m_player->report_event(Player::MOVED);
        } else if (m_right)
        {
            m_player->set_moviment(0.0, 0.0);
            m_player->set_direction(Player::RIGHT);
            m_player->report_event(Player::MOVED);
        }
        if (m_top)
        {
            m_player->set_moviment(0.0, -1.0);
            m_player->set_direction(Player::UP);
            m_player->report_event(Player::MOVED);
        }else if (m_down)
        {
            m_player->set_moviment(0.0, 1.0);
            m_player->set_direction(Player::DOWN);
            m_player->report_event(Player::MOVED);
        }

        Player::Direction dir = m_player->direction();
        int row = dir;
        m_animation->set_row(row);
        m_animation->update(elapsed);
    }

private:
    Player *m_player;
    unique_ptr<Animation> m_animation;
    int m_left, m_right, m_top, m_down;
    bool m_running;
};

class Running : public SpriteState
{
public:
    Running(Player *player, bool key)
        : m_player(player), m_animation(
        new Animation("res/sprites/running.png", 0, 0, 70, 70, 8, 60, true)),
        m_left(0), m_right(0), m_top(0), m_down(0), m_last(0),
        m_key(key), m_running(false), m_pushing(false)
    {
    }

    ~Running() {}

    const double m_speed = 250.0;

    void enter(int from)
    {
        m_player->set_dimensions(m_animation->width(), m_animation->height());

        Player::Direction dir = m_player->direction();

        if(dir == Player::RIGHT)
        {
            m_right = 1;
        }else
        {
            m_right = 0;
        }

        if (dir == Player::LEFT)
        {
            m_left = 1;
        }else
        {
            m_left = 0;
        }

        if (dir == Player::UP)
        {
            m_top = 1;
        }else
        {
            m_top = 0;
        }
        
        if (dir == Player::DOWN)
        {
            m_down = 1;
        }else
        {
            m_down = 0;
        }
        
        m_last = 0;
        m_running = 0;

        if (from == Player::IDLE)
        {
            auto moviment = m_player->moviment();
            double horizontal_position = moviment.first * m_speed;
            double vertical_position = moviment.second * m_speed;
            m_player->set_moviment(horizontal_position, vertical_position);
        }
    }

    void leave(int)
    {
    }

    void draw()
    {
        m_animation->draw(m_player->horizontal_position(), m_player->vertical_position());
        m_player->show_health();
        m_player->show_sanity();
        m_player->show_inventory();
        m_player->show_stamina();
    }

    bool on_event(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 1;
                return true;

            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 1;
                return true;

            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_top = 1;
                return true;

            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 1;
                return true;

            case KeyboardEvent::L:
                m_running = true;
                return true;

            case KeyboardEvent::Q:
                m_player->use_pill();
                return true;

            case KeyboardEvent::K:
                m_player->take_item();
                m_pushing = true;
                return true;

            case KeyboardEvent::E:
                m_player->open_door();
                return true;

            case KeyboardEvent::C:
                m_player->report_event(Player::DUCKING);
                return true;

            case KeyboardEvent::J:
                m_player->hit();
                return true;

            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 0;
                return true;

            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 0;
                return true;

            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_top = 0;
                return true;

            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 0;
                return true;

            case KeyboardEvent::L:
                m_running = false;
                return true;

            case KeyboardEvent::K:
                m_pushing = false;
                return true;

            default:
                break;
            }
            break;
        }

        return false;
    }

    void update(unsigned long elapsed)
    {
        double speed = m_speed;

        if(m_player->health() < 1)
            m_player->you_died();

        if(m_player->stamina() < 100)
        {
            m_player->set_stamina(m_player->stamina() + 0.05);
            if(m_player->stamina() > 100)
                m_player->set_stamina(100);
        }

        if(m_running)
        {
            if(m_player->stamina() > 1)
            {

                speed += 50 + 10 * ((int)m_player->stamina())/5;
                m_player->set_stamina(m_player->stamina() - 0.25);
                if(m_player->stamina() < 1)
                    m_player->set_stamina(-(0.05 * 1000));
            }

//            cout << "speed: " << speed << endl;
        }

        if(m_pushing)
        {
            m_player->push_item();
        }

        if(! m_player->m_sanity_loss)
            m_player->m_sanity_loss = elapsed;

        if(elapsed - m_player->m_sanity_loss > 3000)
        {
            m_player->set_sanity(m_player->sanity() - 1);
            if(m_player->sanity() < 0)
                m_player->set_sanity(0);
            m_player->m_sanity_loss = elapsed;
        }

        if (m_left)
        {
            m_player->set_direction(Player::LEFT);
            m_player->report_event(Player::MOVED);
        }else if (m_right)
        {
            m_player->set_direction(Player::RIGHT);
            m_player->report_event(Player::MOVED);
        }
        if (m_top)
        {
            m_player->set_direction(Player::UP);
            m_player->report_event(Player::MOVED);
        } else if (m_down)
        {
            m_player->set_direction(Player::DOWN);
            m_player->report_event(Player::MOVED);
        }

        if(!m_top && !m_down && !m_right && !m_left)
        {
            m_player->report_event(Player::STOPPED);
        }
        else
        {
            m_player->set_moviment(speed*(m_right - m_left), speed*(m_down - m_top));
        }



        Player::Direction dir = m_player->direction();
        int row = dir;
        m_animation->set_row(row);

        if (not m_last)
        {
            m_last = elapsed;
        }

        auto moviment = m_player->moviment();
        unsigned long delta = elapsed - m_last;
        double horizontal_position = m_player->horizontal_position() + (moviment.first * delta)/1000.0;
        double vertical_position = m_player->vertical_position() + (moviment.second * delta)/1000.0;

        /*limite da sala */
        Environment *env = Environment::get_instance();

        if (horizontal_position + m_player->width() > env->canvas->width())
        {
            horizontal_position = env->canvas->width() - m_player->width();
        }

        if ((horizontal_position >= env->canvas->width() - m_player->width() and moviment.first > 0) or
            (horizontal_position <= 0 and moviment.first < 0))
        {
            horizontal_position -= (moviment.first * delta)/1000.0;
        }

        if (vertical_position + m_player->height() > env->canvas->height())
        {
            vertical_position = env->canvas->height() - m_player->height();
        }

        if ((vertical_position >= env->canvas->height() - m_player->height() and moviment.second > 0) or
            (vertical_position <= 0 and moviment.second < 0))
        {
            vertical_position -= (moviment.second * delta)/1000.0;
        }

        m_player->set_horizontal_position(horizontal_position);
        m_player->set_vertical_position(vertical_position);

        m_last = elapsed;
        m_animation->update(elapsed);

    }

private:
    Player *m_player;
    unique_ptr<Animation> m_animation;
    short m_left, m_right, m_top, m_down;
    unsigned long m_last;
    bool m_key, m_running, m_pushing;
};

class Duck : public SpriteState
{
public:
    Duck(Player *player)
        : m_player(player), m_animation(new Animation("res/sprites/duck.png",
            0, 0, 70, 70, 2, 1000, true)), m_left(0), m_right(0), m_top(0),
        m_down(0)
    {
    }

    ~Duck() {}

    void enter(int)
    {
        m_player->set_dimensions(m_animation->width(), m_animation->height());
        m_right = m_left = m_down = m_top = 0;
    }

    void leave(int)
    {
    }

    bool on_event(const KeyboardEvent& event)
    {
        switch (event.state())
        {
        case KeyboardEvent::PRESSED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 1;
                return true;

            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 1;
                return true;

            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_top = 1;
                return true;

            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 1;
                return true;

            case KeyboardEvent::Q:
                m_player->use_pill();
                return true;

            case KeyboardEvent::E:
                m_player->open_door();
                return true;

            case KeyboardEvent::K:
                m_player->take_item();
                return true;

            case KeyboardEvent::C:
                m_player->report_event(Player::STANDING);
                return true;

            case KeyboardEvent::J:
                m_player->hit();
                return true;

            default:
                break;
            }
            break;

        case KeyboardEvent::RELEASED:
            switch (event.key())
            {
            case KeyboardEvent::LEFT:
            case KeyboardEvent::A:
                m_left = 0;
                return true;

            case KeyboardEvent::RIGHT:
            case KeyboardEvent::D:
                m_right = 0;
                return true;

            case KeyboardEvent::UP:
            case KeyboardEvent::W:
                m_top = 0;
                return true;

            case KeyboardEvent::DOWN:
            case KeyboardEvent::S:
                m_down = 0;
                return true;

            case KeyboardEvent::O:
                m_player->jump_level();
                return true;

            case KeyboardEvent::K:
                m_player->take_item();
                return true;

            default:
                break;
            }
            break;
        }

        return false;
    }

    void draw()
    {
        m_animation->draw(m_player->horizontal_position(), m_player->vertical_position());
        m_player->show_health();
        m_player->show_sanity();
        m_player->show_inventory();
        m_player->show_stamina();
    }

    void update(unsigned long elapsed)
    {
        if(m_player->health() < 1)
            m_player->you_died();

        if(m_player->stamina() < 100)
        {
            m_player->set_stamina(m_player->stamina() + 0.05);
            if(m_player->stamina() > 100)
                m_player->set_stamina(100);
        }


        if(! m_player->m_sanity_loss)
            m_player->m_sanity_loss = elapsed;

        if(elapsed - m_player->m_sanity_loss > 3000)
        {
            m_player->set_sanity(m_player->sanity() - 1);
            if(m_player->sanity() < 0)
                m_player->set_sanity(0);
            m_player->m_sanity_loss = elapsed;
        }

        if (m_left)
        {
            m_player->set_moviment(-1.0, 0.0);
            m_player->set_direction(Player::LEFT);
        } else if (m_right)
        {
            m_player->set_moviment(0.0, 0.0);
            m_player->set_direction(Player::RIGHT);
        }
        if (m_top)
        {
            m_player->set_moviment(0.0, -1.0);
            m_player->set_direction(Player::UP);
        }else if (m_down)
        {
            m_player->set_moviment(0.0, 1.0);
            m_player->set_direction(Player::DOWN);
        }

        Player::Direction dir = m_player->direction();
        int row = dir;
        m_animation->set_row(row);
        m_animation->update(elapsed);
    }

private:
    Player *m_player;
    unique_ptr<Animation> m_animation;
    int m_left, m_right, m_top, m_down;
};

Player::Player(Object *parent, const string& id)
    : Sprite(parent, id), m_sanity_loss(0), m_impl(new Player::Impl(this, m_key)),
     m_key(false), m_pill(0), m_hweapon(false), m_secondary(false),m_damage(50)
{
    add_state(IDLE, new Idle(this));
    add_state(RUNNING, new Running(this, m_key));
    add_state(DUCK, new Duck(this));

    add_transition(MOVED, IDLE, RUNNING);
    add_transition(STOPPED, RUNNING, IDLE);
    add_transition(DUCKING, IDLE, DUCK);
    add_transition(STANDING, DUCK, IDLE);
    add_transition(DUCKING, RUNNING, DUCK);
    add_transition(STANDING, DUCK, RUNNING);
    change_state(IDLE, NONE);

    Environment *env = Environment::get_instance();
    env->events_manager->register_listener(this);
}

Player::~Player()
{
    Environment *env = Environment::get_instance();
    env->events_manager->unregister_listener(this);
}

Player::Direction
Player::direction() const
{
    return m_impl->direction();
}

void
Player::set_direction(Direction direction)
{
    m_impl->set_direction(direction);
}

const pair<double, double>&
Player::moviment() const
{
    return m_impl->moviment();
}

void
Player::set_moviment(double horizontal_axis, double vertical_axis)
{
    m_impl->set_moviment(horizontal_axis, vertical_axis);
}

void
Player::set_current(string nova, int posx, int posy)
{
    m_impl->set_current(nova, posx, posy);
}

void
Player::set_strength(double strength)
{
    m_impl->set_strength(strength);
}

void
Player::set_health(double health)
{
    m_impl->set_health(health);
}

void
Player::set_sanity(double sanity)
{
    m_impl->set_sanity(sanity);
}

void
Player::set_stamina(double stamina)
{
    m_impl->set_stamina(stamina);
}

double
Player::strength()
{
    return m_impl->strength();
}

double
Player::health()
{
    return m_impl->health();
}

double
Player::sanity()
{
    return m_impl->sanity();
}

double
Player::stamina()
{
    return m_impl->stamina();
}
double
Player::damage()
{
    return m_impl->damage();
}

void
Player::get_key()
{
    m_impl->get_key();
}

void
Player::set_key(bool input)
{
    m_impl->set_key(input);
}

bool
Player::has_key()
{
    return m_impl->has_key();
}

void
Player::show_health()
{
     m_impl->show_health();
}
void
Player::show_sanity()
{
    m_impl->show_sanity();
}
void
Player::show_inventory()
{
    m_impl->show_inventory();
}
void
Player::show_stamina()
{
    m_impl->show_stamina();
}

void
Player::take_item()
{
    m_impl->take_item();
}

void
Player::jump_level()
{
    m_impl->jump_level();
}

void
Player::open_door()
{
    m_impl->open_door();
}

void
Player::push_item()
{
    m_impl->push_item();
}

void
Player::get_weapon(string weapon_id)
{
    m_impl->get_weapon(weapon_id);
}

void
Player::use_pill()
{
    m_impl->use_pill();
}

void
Player::get_pill(string id)
{
    m_impl->get_pill(id);
}
void
Player::you_died()
{
    m_impl->you_died();
}
void
Player::hit()
{
    m_impl->hit();
}
int
Player::life()
{
    return m_impl->life();
}
void
Player::set_life(int life)
{
    m_impl->set_life(life);
}
void
Player::die()
{
    m_impl->die();
}
