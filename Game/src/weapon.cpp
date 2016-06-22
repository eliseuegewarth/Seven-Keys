#include <iostream>
#include <core/image.hpp>
#include <core/keyboardevent.hpp>
#include <core/environment.hpp>

#include "weapon.hpp"

/**
 * [Weapon::Weapon 	Receives the object parent (weapon),
 * 					your identifier and all your attributes
 * 					(resistance, damage and attack speed)]
 * @param	*parent         [description]
 * @param	id              [identifier of object]
 * @param	path      		[description]
 * @param	resistance      [Resistance of the Weapon,
 *                        	may change depending the weapon]
 * @param	damage          [Damage of the Weapon,
 *                        	may change depending the weapon]
 * @param	attack_speed    [Attack speed of the Weapon,
 *                        	may change depending the weapon]
 */
Weapon::Weapon(Object *parent, ObjectID id, const string& path,
	int resistance,	double damage, int attack_speed)
    :Image(parent, id, path)
    {
    	m_damage = damage;
    	m_attack_speed = attack_speed;
    	m_resistance = resistance;
    }
