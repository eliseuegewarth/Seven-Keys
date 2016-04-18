#Weapon

##Weapon::Weapon(Object *parent, ObjectID id, const string& path,
	             int resistance, double damage, int attack_speed)
    ·m_damage = damage;
    ·m_attack_speed = attack_speed;
    ·m_resistance = resistance;

##class Weapon : public Image
    ·Weapon(Object *parent, ObjectID id, const string& path, int resistance,
            double damage, int attack_speed);
    ·double m_damage;
    ·int m_attack_speed;
    ·int m_resistance;
