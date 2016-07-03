/**
 * weapon.hpp
 * This class implements a weapon game object. Player will use this to kill his enemies in game.
 * Licença: LGPL. Sem copyright.
 */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

#include "item.hpp"

using namespace std;

class Weapon : public Image
{
public:
    Weapon(Object *parent, ObjectID id, const string& path, int resistance,
    double damage, int attack_speed);

    double m_damage; //Damage of the Weapon, used to set the damage to the weapon
    int m_attack_speed; //Attack speed of the Weapon, used to set the attack speed to the weapon
    int m_resistance; //Resistance of the Weapon, used to set the resistance to the weapon
};

#endif
