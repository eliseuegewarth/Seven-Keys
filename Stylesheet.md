# Stylesheet

This document describe the conventions adopted for the development of games named Seven Keys.

*Você pode ler isso em português em [Folha de Estilo](Folha de Estilo.md)*

## Sumary

___

#### [1. Archive Header (.hpp)](#1-archive-header-hpp-1)

#### [2. Escope](#2-escope-1)
###### [2.1 Include](#21-include-1)
###### [2.2 Namespaces](#22-namespaces-1)
###### [2.3 Local Variable](#23-local-variable-1)
###### [2.4 Globals and Statics Variables](#24-globals-and-statics-variables-1)

#### [3. Naming](#3-naming-1)
###### [3.1 Classes and Enums](#31-classes-and-enums-1)
###### [3.2 Class Member](#32-class-member-1)
###### [3.3 Methods, Funcions, Variable, Namespaces](#33-methods-functions-variable-namespaces-1)
###### [3.4 Constants and Macros](#34-constants-and-macros-1)
###### [3.5 Structs](#35-structs-1)
###### [3.6 Typedef](#36-typedef-1)
###### [3.7 Pointers](#37-pointers-1)

#### [4. Classes](#4-classes-1)
###### [4.1 Declaration of Order](#41-declaration-of-order-1)
###### [4.2 Constructors and Destructors](#42-constructors-and-destructors-1)
###### [4.3 Methods and Functions](#43-methods-and-functions-1)
###### [4.3.1 Return](#431-return-1)

#### [5. Formatting](#5-formatting-1)
###### [5.1 Indenting](#51-indenting-1)
###### [5.2 Line Size Maximum](#52-line-size-maximum-1)
###### [5.3 Operators](#53-operators-1)
###### [5.4 Braces](#54-braces-1)
###### [5.5 Control Structures (if, switch)](#55-control-structures-if-switch-1)
###### [5.6 Loop Structures (while, for, do-while)](#56-Loop-Structures-while-for-do-while-1)
###### [5.7 Variables and Attributes](#57-variables-and-attributes-1)
###### [5.8 Structs e Enums](#58-structs-e-enums-1)

#### [6. Comments](#6-comments-1)
###### [6.1 Line comment](#61-line-comment-1)
###### [6.2 Comment block](#62-comment-block-1)

#### [7. Others functional features ](#7-others-functional-features-1)
###### [7.1 JavaDoc](#71-javadoc-1)
###### [7.2 Assertives](#72-assertives-1)
###### [7.3 Exceptions](#73-exceptions-1)
###### [7.4 Casting](#74-casting-1)

___


## 1. Archive Header (.hpp)

All file .cpp must have un .hpp corresponding, with send name. Both must have the name of classe which they implement.

Class Names:
```c++
class Guard : public Object
```
Files Names:
```c++
guard.cpp
```

```c++
guard.hpp
```

## 2. Escope
### 2.1 Include

	-First the header of source file
	-after the library engine
	-after the library specific of the game
	-after the library standards the c/c++


```c++
#include "boss.h"

#include "core/level.h"
#include "core/environment.h"
#include "core/keyboardevent.h"

#include <core/animation.h>

#include <iostream>
```
### 2.2 Namespaces

Namespaces should be used whenever possible
Namespaces should always be named

```c++
using namespace std;
```
### 2.3 Local Variable

Declare the variables the most locally possible.
The variables should be declared the most closer to their use
All the variables shoud be initialised.


```c++
	for(int id = 1; id < quantidade_salas; id++)
	{
        Room * aux = room_list.at(rand() % id);
		CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
        aux ++;
	}
```
### 2.4 Globals and Statics Variables (static)

Variables statics should be used only when its necessary due their scratchs of variations and bad over the code, when it don't be utilized as constant(const).

```c++
static Font_Manager *instance;
```

## 3. Naming
### 3.1 Classes e Enums

The nomeclature must follow the standard "CamelCase" for Classes and Enums.
Names of classes must be composed for nouns.
```c++
class Guard : public Object
```
### 3.2 Class Member

For class members the standard adopted is the "lowerCamelCase"
```c++
static ActionID removeGuardID;
```
### 3.3 Methods, Funcions, Variable, Namespaces

For methods, functions, variables and namespaces the standard used must be the "snake_case"
Methods and functions must contain at least a verb and a noun.
```c++
void update_vision();
```
### 3.4 Constants and Macros

For constants and macros should be used the "SCREAMING_SNAKE_CASE", except in parameters which shoud be adocted the style "snake_case".

```c++
#define SPEED 150.5
```
In parameters:

```c++
void Player::get_weapon(string weapon_id)
```

### 3.5 Structs

In structs it will be used "snake_case", the same shoud be accompained of one *typedef*

```c++
typedef struct _Area
{
    double left, right;
    double top, bottom;
} Area;
```
### 3.6 Typedef

For *typedef* the standard to be followed is the standard "CamelCase" in types compounds as a *struct* and *enum*.

```c++
typedef struct _Area
{
    ...
} Area;
```

For simples styles as *int* and *double* shoud be used the standard *snake_case*.
```c++
typedef unsigned int natural_numbers;
```

### 3.7 Pointers

In declarations the pointers shoud be use the *asterisk* near to name of the variable, and shoud follow the model "snake_case" as the example.
```c++
Environment *env = Environment::get_instance();
```

## 4. Classes

Class must have methods and class members consistents with what hes name especifies.
### 4.1 Declaration of Order

The declarations make um in orther of the more open (public) for the most closed (private) in context of encapsulation.
*public* before the *protected*, *protected* before the *private*.

The first declarations shoud be the constructors and destructors, soon after the class members, followed by methods.
```c++
class Font_Manager
{
public:
    static Font_Manager* Instance();
    static void init() throw (Exception);
    void load_font(string path, unsigned int font_size) throw (Exception);
    void close_font();

    SDL_Texture* message()const;
    void make_message(SDL_Renderer * renderer, string message, Color color) throw (Exception);

protected:
    Font_Manager();
    ~Font_Manager();

private:
    static Font_Manager* instance;
    SDL_Texture* m_message;
    TTF_Font* m_font;
};
```

### 4.2 Constructors and Destructors

Constructor shoud always be defined in each class.

.hpp

```c++
Animation(const string& image, double x, double y, double w, double h,
          int frames, unsigned long speed_in_ms, bool loop = false);

    ~Animation();
```

.cpp

```c++
Animation::Animation(const string& texture, double x, double y, double w,
    		     double h, int frames, unsigned long speed_in_ms, bool loop)
    		     : m_impl(new Animation::Impl(texture, x, y, w, h, frames, speed_in_ms, loop)) {
}
```

Only virtuals destructs allowed, when necessary.
### 4.3 Methods and Functions

The method shoud have the funcionality features of his nomeclatures. They shoud be separeted of the other declarations of the classe for blank lines before and after, forming paragraphs.
```c++
...

void show_health()
{
		Environment* env = Environment::get_instance();
		Rect healthbar {(double)env->canvas->w()/15, (double)env->canvas->h()/24, m_player->health() * 2, 12};
		env->canvas->fill(healthbar, Color::RED);
		Rect borda {(double)env->canvas->w()/15, (double)env->canvas->h()/24, 100*2, 12};
		env->canvas->draw(borda, Color::RED);
}

...
```
#### 4.3.1 Return

The type of return should be declared always before the mane of the function in the same line.
```c++
...

void show_health()
{
	...
}

...
```
## 5. Formatting
### 5.1 Indenting

For indenting should used the standard of tab of four spaces.

### 5.2 Line Size Maximum

Should avoid surpass the limit of 80 characteres for line.
For breaks of line, in cases of expressions very large, should use the following principles:
Break after comma;

```c++

Impl(Button* button, const string& idle_image_id,
	const string& active_image_id)
	: m_button(button), m_text(nullptr), m_idle(Color::GREEN),
	m_active(Color::BLUE), m_border(Color::BLACK), m_thickness(1),
	m_state(IDLE)
```

·Break before the operators;
```c++

Item* pill = new Item(m_player, "icon_pill", path, (double)env->canvas->w()
* 1/35 + 2, (double)env->canvas->h() * 25/30 + 2, 9999, true);
m_player->add_child(pill);
```

·Align the new line with the same level the start of expression the previous line.
### 5.3 Operators

For operators shoud give a space before and one after.

```c++
m_player->set_stamina(m_player->stamina() + 0.05);
```
### 5.4 Braces

The braces shoud be open one line below the end of the expression or declaration and shoud be closed one line below the block instructions:

```c++

if(x + m_player->w() > env->canvas->w())
{
	x = env->canvas->w() - m_player->w();
}
```
### 5.5 Control Structures (if, switch)

The stunderd to be following is without spaces between the control structute and the parentheses of condition, and between the operations of condition. It's better using command operations as 'and', 'or', 'not', natives of c++.

Bad code:
```c++
 if(id != Button::clickedID)
 {
     return false;
 }
```

Good code:
```c++
 if(id not Button::clickedID)
 {
     return false;
 }
 else
 {
     //nothing to do.
 }
```

### 5.6 Loop Structures (while, for, do-while)

The standard to be following is without spaces between the repetition of structures and parentheses, and in conditions of repetition spaces before the <point and comma>, and between the signals of relation and operarion space before and after.

```c++
for(int id = 1; id < quantidade_salas; id++)
{
    Room * aux = room_list.at(rand() % id);
    CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
    aux ++;
}
```
### 5.7 Variables and Attributes

The variables and class members shoud be used in standard snake_case, the variables shoud be for standard declared with the type following for a space the name of variable and the same must be initialized.
<type>{space}<variable>{space} = {space}<inicialized>;

```c++
double w = env->canvas->w();
```

The functions and methods shoud following format:
<Constructor>(<type>{space}<variable>{comma}{space}...);

```c++
Animation(const string& image, double x, double y, double w, double h,
          int frames, unsigned long speed_in_ms, bool loop = false);
```
### 5.8 Structs e Enums

Structs shoud have only primary data and can not be implemented any funcionality type or related.

typedef struct _ ItemInfo {
        string name;
        string type;
        int variations;
        int weight;
        bool walkable;
        bool unique;
        double mass;
        int x, y;
    } ItemInfo;


```

The declaration of enum shoud be used with on typedef following for his parameters between braces.
<typedef>{space}<enum>{space}<{PARAMETRO1, PARAMETRO2}>{espaço}<NomeType>;
```c++
typedef enum { NONE, BLEND } BlendMode;
```

## 6. Comments
### 6.1 Line comment

For comments the only one line shoud be utilized double bar.
```c++
// Room Criation
```
### 6.2 Comment block

For comments the two or more lines must be utilized the bar with an asterisk.
```c++
/*
string *str;
str = (string*)(&id);
*str = "stage1";
*/
```

## 7. Others functional features
### 7.1 JavaDoc

The documentation on style "JavaDoc" shoud be used for comments of class and method.
Is advisable only the use of @param, @return, @throws and in some cases @deprecated.
For any commentary to style JavaDoc for comments of class and methods, shoud be used comments of @param, @return, @throws and @deprecated if is necessary. The standard adopted was as follows:
```c++
/**
 * [Weapon::Weapon Receives the object parent (weapon), your identifier and
 * all your attributes(resistance, damage and attack speed)]
 * @param	id              [identifier of object]
 * @param	resistance      [Resistance of the Weapon, may change depending the weapon]
 * @param	damage          [Damage of the Weapon, may change depending the weapon]
 * @param	attack_speed    [Attack speed of the Weapon, may change depending the weapon]
 */
```
### 7.2 Assertives

Assertives must be used whenever one unexpected behavior, conditions impossible and corrupted data which can not be treated.
His parameters must contain at least one condition and an error message or with the state and/or expected value.

```c++
assert(percent >= 0   && "Must be >= 0")
```

### 7.3 Exceptions

Exceptions shoud be treated in context most appropriate using *catch*, if the context is not appropriate an exception must be spread using *throw*.

Bad code:
```c++
...

try
{
	srand(time(NULL));
	SevenKeys keys;
	keys.init("7 Keys", 1280, 720, 1, true);
	keys.run();
} catch (Exception ex)
{
	cerr << ex.message() << endl;
	return -1;
}
...

```

```c++
try
{
	audio_manager = new AudioManagerWrapper();

    if (not audio_manager)
    {
        throw AudioManagerSfxAllocationException("Out of memory for a new AudioManagerSfx");
    }

    audio_manager->init();
} catch (AudioManagerMusicAllocationException audio_manager_music_allocation_exception)
{
	// Do something significant
	...
}

...
```

The excetion "AudioManagerSfxAllocationException" there is not one catch for treat it and is spread to the caller method.

### 7.4 Casting

should avoid the *cast* forced as follows:

```c++
m_player->x() + (moviment.first * delta)/1000.0;
```
A maneira correta de se fazer é usando o *cast* da propria linguagem:
The right way to make is using the *cast* own language.

```c++
m_player->x() + (moviment.first * delta) / (double)1000;
```
