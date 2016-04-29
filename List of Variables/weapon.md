#Weapon

##```class Weapon : public Image```
###Class members
```c++
double m_damage;
```
Damage of the Weapon, used to set the damage to the weapon
```c++
int m_attack_speed;
```
Attack speed of the Weapon, used to set the attack speed to the weapon
```c++
int m_resistance;
```
Resistance of the Weapon, used to set the resistance to the weapon
##```Weapon::Weapon()```
Receives the object parent (weapon), your identifier and all your attributes(resistance, damage and attack speed)
###Parameters
```c++
Object * parent
```
The parent is the map object that will contains the weapon.
```c++
ObjectID id
```
identifier of object
```c++
const string& path
```
Path settings file
```c++
int resistance
```
Resistance of the Weapon, may change depending the weapon
```c++
double damage
```
Damage of the Weapon, may change depending the weapon
```c++
int attack_speed
```
Attack speed of the Weapon, may change depending the weapon
