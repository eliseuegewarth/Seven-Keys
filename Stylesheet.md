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
###### [5.4 Keys](#54-keys-1)
###### [5.5 Control Structures (if, switch)](#55-control-structures-if-switch-1)
###### [5.6 Repetition of structures (while, for, do-while)](#56-repetition-of-structures-while-for-do-while-1)
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
A Nomenclatura deve seguir o padrão "CamelCase" para Classes e Enums.
Nomes de classes devem ser compostos por substantivos.
```c++
class Guard : public Object
```
### 3.2 Class Member
Para atributos o padrão adotado é o "lowerCamelCase".

```c++
static ActionID removeGuardID;
```
### 3.3 Methods, Funcions, Variable, Namespaces
Para metodos, funções, variaves e namespaces o padrão usado deve ser o "snake_case".
Metodos e Funções devem conter pelo menos um verbo e um substantivo.

```c++
void update_vision();
```
### 3.4 Constants and Macros
Para constantes e macros deverá ser usado o "SCREAMING_SNAKE_CASE", exceto em parametros que deve ser adotado o estilo "snake_case".

```c++
#define SPEED 150.5
```
Em parametros:

```c++
void Player::get_weapon(string weapon_id)
```

### 3.5 Structs
Em structs será usado "snake_case", o mesmo deverá ser acompanhado de um *typedef*.

```c++
typedef struct _Area
{
    double left, right;
    double top, bottom;
} Area;
```
### 3.6 Typedef
Para *typedef* o padrão a ser seguido é o padrão CamelCase em tipos compostos como uma *struct* e *enum*.

```c++
typedef struct _Area
{
    ...
} Area;
```
Para tipos simples como *int* e *double* deve ser usado o padrão *snake_case*.

```c++
typedef unsigned int natural_numbers;
```

### 3.7 Ponteiros
Na declaração de ponteiros deve-se usar o *asterisco* junto ao nome da variavel, e deve seguir o modelo "snake_case" assim como o exemplo.

```c++
Environment *env = Environment::get_instance();
```

## 4. Classes

Classes devem possuir metodos e atributos condizentes com o que seu nome especifica.
### 4.1 Declaration of Order
As declarações devem vir na ordem do mais aberto (public) para o mais fechado (private) no contexto de encapsulamento.
*public* antes de *protected*, *protected* antes de *private*.
As primeiras declarações devem ser de Construtores e Destrutores, logo depois os atributos, seguidos dos metodos.

```c++
class Player : public Sprite
{
public:
    typedef enum { NONE, IDLE, RUNNING, DUCK } State;

    Player(Object *parent, const string& id);
    ~Player();
    int m_sanity_loss;

    Direction direction() const;
    void set_direction(Direction direction);

    const pair<double, double>& moviment() const;
    void set_moviment(double xaxis, double yaxis);

    static ActionID hitExitDoorID;
    static ActionID jumpNextLevelID;

    void set_current(string room, int x, int y);

    int life();
    double health();

private:
    class Impl;
    unique_ptr<Impl> m_impl;

};
```

### 4.2 Constructors and Destructors

Construtores devem sempre ser definidos em cada classe.

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

Apenas destrutores virtuais sao permitidos, quando necessarios.
### 4.3 Methods and Functions

Os metodos devem possuir as funcionalidades características de sua nomenclatura. Eles devem ser separados de outras declarações da classe por linhas em branco antes e depois, formando paragrafos.

```c++
...

void show_health()
{
		Environment * env = Environment::get_instance();
		Rect healthbar {(double)env->canvas->w()/15, (double)env->canvas->h()/24, m_player->health() * 2, 12};
		env->canvas->fill(healthbar, Color::RED);
		Rect borda {(double)env->canvas->w()/15, (double)env->canvas->h()/24, 100*2, 12};
		env->canvas->draw(borda, Color::RED);
}

...
```
#### 4.3.1 Return

O tipo de retorno deve ser declarado sempre antes do nome da função na mesma linha.

```c++
...

void show_health()
{
	...
}

...
```
## 5. FFormatting
### 5.1 Indenting

Para identação sera usado o padrão de tabulação de 4 espaços.
### 5.2 Line Size Maximum

Deve-se evitar ultrapassar o limite de 80 caracteres por linha.
Para quebras de linha, em casos de expressões muito grandes, deve-se usar os seguintes principios:
·Quebrar após virgula;

```c++

Impl(Button *button, const string& idle_image_id,
	const string& active_image_id)
	: m_button(button), m_text(nullptr), m_idle(Color::GREEN),
	m_active(Color::BLUE), m_border(Color::BLACK), m_thickness(1),
	m_state(IDLE)
```

·Quebrar antes de operadores;

```c++

Item* pill = new Item(m_player, "icon_pill", path, (double)env->canvas->w()
* 1/35 + 2, (double)env->canvas->h() * 25/30 + 2, 9999, true);
m_player->add_child(pill);
```

·Alinhar a nova linha com o mesmo nivel do inicio da expressão da linha anterior
### 5.3 Operators

Para operadores deve-se dar um espaço antes e um depois.

```c++
m_player->set_stamina(m_player->stamina() + 0.05);
```
### 5.4 Keys

As chaves devem ser abertas uma linha abaixo do termino da expressão ou declaração e deve ser fechada uma linha abaixo do bloco de instruções:

```c++

if(x + m_player->w() > env->canvas->w())
{
	x = env->canvas->w() - m_player->w();
}
```
### 5.5 Control Structures (if, switch)

O padrão a ser seguido é de sem espaços entre a estrutura de controle e o parentese da condição, e entre as operações das condições.

Codigo ruim:
```c++
 if(id != Button::clickedID)
 {
     return false;
 }
```

codigo bom:
```c++
 if(id != Button::clickedID)
 {
     return false;
 }
 else
 {
     //nothing to do.
 }
```

### 5.6 Repetition of structures (while, for, do-while)

O padrão a ser seguido é sem espaços entre a estrutura de repetição e o parentese, e nas condições de repetição espaços apos os <ponto e virgula>, e entre os sinais de relação e operação espaço antes e depois.
```c++
for(int id = 1; id < quantidade_salas; id++)
{
    Room * aux = room_list.at(rand() % id);
    CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
    aux ++;
}
```
### 5.7 Variables and Attributes

As variaveis e atributos devem ser usadas no padrão snake_case, as variaveis devem ser por padrão declaradas com o tipo seguido por um espaco o nome da variavel e a mesma deve ser inicializada.
<tipo>{espaço}<variavel>{espaço}={espaço}<inicialização>;

```c++
double w = env->canvas->w();
```
As funções e metodos devem seguir o seguinte formato:
<Construtor>(<tipo>{espaço}<variavel>{virgula}{espaço}...);

```c++
Animation(const string& image, double x, double y, double w, double h,
          int frames, unsigned long speed_in_ms, bool loop = false);
```
### 5.8 Structs e Enums

Structs devem possuir apenas dados primarios e nao podem ser implementadas quaisquer tipo de funcionalidades ou afins.

```c++
typedef struct _ItemInfo {
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
A declaração de enum deve ser usada com um typedef seguida por seus parametros entre chaves.
<typedef>{espaço}<enum>{espaço}<{PARAMETRO1, PARAMETRO2}>{espaço}<NomeType>;
```c++
typedef enum { NONE, BLEND } BlendMode;
```

## 6. Comments
### 6.1 Line comment
Para comentários de uma única linha devem ser utilizadas barras duplas

```c++
// Room Criation
```
### 6.2 Comment block
Para comentários de duas ou mais linhas devem ser utilizadas a barra com o asterisco

```c++
/*
string *str;
str = (string*)(&id);
*str = "stage1";
*/
```

## 7. Others functional features
### 7.1 JavaDoc
A documentação no estilo "JavaDoc" deve ser usada para comentarios de classe ou metodos.
É aconselhavel apenas o uso de @param, @return, @throws e em alguns casos @deprecated.
Para qualquer comentario ao estilo JavaDoc deve seguir o seguinte padrao para comentarios de classe e metodos:
```c++
/**
 *  
 */
```
Para comentarios de @param, @return, @throws e @deprecated deve ser usado o seguinte padrao.
```c++
/**
 * <descrição>
 * @deprecated
 * @param
 * @throws
 * @return
 */
```
### 7.2 Assertives
Assertivas devem ser usadas sempre que houver um comportamento inesperado, condições impossiveis e dados corrompidos que não podem ser tratados.
Seus parametros devem conter no minimo uma condição e uma mensagem de erro ou com o estado e/ou valor esperado.

```c++
assert(percent >= 0   && "Must be >= 0")
```

### 7.3 Exceptions
Exceções devem ser tratadas no contexto mais adequado usando *catch*, se o contexto não for adequado a exceção deve ser propagada usando *throw*.

Código ruim:
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
A exceção "AudioManagerSfxAllocationException" não tem um catch para trata-la e é propagada para quem chamou o metodo.

### 7.4 Casting

Deve-se evitar o *cast* forçado como o seguinte:

```c++
m_player->x() + (moviment.first * delta)/1000.0;
```
A maneira correta de se fazer é usando o *cast* da propria linguagem:

```c++
m_player->x() + (moviment.first * delta) / (double)1000;
```
