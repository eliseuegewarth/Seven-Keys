/*
 * Classe que representa o sprite do teste.
 *
 * Autor: Edson Alves
 * Data: 15/05/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef PLAYER_H
#define PLAYER_H

#include "core/sprite.hpp"
#include "map.hpp"
#include "sight.hpp"
#include "weapon.hpp"

using std::pair;

class Player : public Sprite
{
public:
    typedef enum { NONE, IDLE, RUNNING, DUCK } State;
    typedef enum { MOVED, STOPPED, DUCKING, STANDING } Event;
    typedef enum { LEFT, UP, RIGHT, DOWN } Direction;

    Player(Object *parent, const string& id);
    ~Player();
    int m_sanity_loss;

    Direction direction() const;
    void set_direction(Direction direction);

    const pair<double, double>& moviment() const;
    void set_moviment(double xaxis, double yaxis);

    static ActionID hitExitDoorID;
    static ActionID jumpNextLevelID;
    static ActionID takeItemID;
    static ActionID openDoorID;
    static ActionID pushItemID;
    static ActionID repeatLevelID;
    static ActionID changeRoomID;
    static ActionID getHitID;

    void set_current(string room, int x, int y);

    int life();
    double health();
    double sanity();
    double strength();
    double stamina();
    double damage();

    void set_life(int life);
    void set_health(double health = 100.0);
    void set_sanity(double sanity = 100.0);
    void set_strength(double strength = 0.0);
    void set_stamina(double stamina = 100.0);

    void set_key(bool input);
    void get_key();
    bool has_key();

    void get_pill(string id);
    void get_weapon(string weapon_id);

    void take_item();
    void jump_level();
    void open_door();
    void push_item();
    void use_pill();
    void use_weapon();
    void you_died();
    void hit();
    void die();

    void show_health();
    void show_sanity();
    void show_inventory();
    void show_stamina();

private:
    class Impl;
    unique_ptr<Impl> m_impl;
    bool m_key = false;
    int m_pill = 0;
    bool m_hweapon = false;
    Weapon* m_weapon = nullptr;
    bool m_secondary = false;
    double m_damage = 50;

};

#endif
