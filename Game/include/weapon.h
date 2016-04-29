#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "item.h"

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
