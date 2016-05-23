# Folha de Estilo

Este documento descreve as convenções adotadas para o desenvolvimento do jogo Seven Keys.

*You also can read in english at [Stylesheet](Stylesheet.md)*.

## Sumário

___

#### [1. Arquivos Header (.hpp)](#1-arquivos-header-hpp-1)

#### [2. Escopo](#2-escopo-1)
###### [2.1 Includes](#21-includes-1)
###### [2.2 Namespaces](#22-namespaces-1)
###### [2.3 Variáveis Locais](#23-variáveis-locais-1)
###### [2.4 Variáveis globais e estáticas (static)](#24-variáveis-globais-e-estáticas-static-1)

#### [3. Nomenclatura](#3-nomenclatura-1)
###### [3.1 Classes e Enums](#31-classes-e-enums-1)
###### [3.2 Atributos](#32-atributos-1)
###### [3.3 Métodos, Funções, Variáveis, Namespaces](#33-métodos-funções-variáveis-namespaces-1)
###### [3.4 Constantes e Macros](#34-constantes-e-macros-1)
###### [3.5 Structs](#35-structs-1)
###### [3.6 Typedef](#36-typedef-1)
###### [3.7 Ponteiros](#37-ponteiros-1)

#### [4. Classes](#4-classes-1)
###### [4.1 Ordem de Declaração](#41-ordem-de-declaração-1)
###### [4.2 Construtores e Destrutores](#42-construtores-e-destrutores-1)
###### [4.3 Métodos e Funções](#43-métodos-e-funções-1)
###### [4.3.1 Retorno](#431-retorno-1)

#### [5. Formatação](#5-formatação-1)
###### [5.1 Indentação](#51-indentação-1)
###### [5.2 Tamanho máximo da linha](#52-tamanho-máximo-da-linha-1)
###### [5.3 Operadores](#53-operadores-1)
###### [5.4 Chaves](#54-chaves-1)
###### [5.5 Estruturas de Controle (if, switch)](#55-estruturas-de-controle-if-switch-1)
###### [5.6 Estruturas de Repetição (while, for, do-while)](#56-estruturas-de-repetição-while-for-do-while-1)
###### [5.7 Variáveis e Atributos](#57-variáveis-e-atributos-1)
###### [5.8 Structs e Enums](#58-structs-e-enums-1)

#### [6. Comentários](#6-comentários-1)
###### [6.1 Comentário de Linha](#61-comentário-de-linha-1)
###### [6.2 Comentário de Bloco](#62-comentário-de-bloco-1)

#### [7. Outras Características Funcionais](#7-outras-características-funcionais-1)
###### [7.1 JavaDoc](#71-javadoc-1)
###### [7.2 Assertivas](#72-assertivas-1)
###### [7.3 Exceções](#73-exceções-1)
###### [7.4 Casting](#74-casting-1)

___


## 1. Arquivos Header (.hpp)

Todo arquivo .cpp deve ter um .hpp correspondente, com mesmo nome. Ambos devem ter o nome da classe a qual eles implementam.

Nome da Classe:
```c++
class Guard : public Object
```
Nome dos Arquivos:
```c++
guard.cpp
```

```c++
guard.hpp
```

## 2. Escopo
### 2.1 Includes

	-Primeiro o header do arquivo fonte
	-depois as bibliotecas da engine
	-depois as bibliotecas especificas do jogo
	-depois as bibliotecas padroes do c/c++

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
### 2.3 Variáveis Locais

Declare as variaveis o mais localmente possivel
As variaveis devem ser declaradas o mais proximo do seu uso
Todas as variaveis devem ser inicializadas.


```c++
	for(int id = 1; id < quantidade_salas; id++)
	{
        Room * aux = room_list.at(rand() % id);
		CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
        aux ++;
	}
```
### 2.4 Variáveis globais e estáticas (static)

Variaveis estaticas devem ser usadas somente quando necessario devido a seus riscos de variacoes e mau uso ao longo do codigo, quando nao utilizada como constante (const).

```c++
static Font_Manager *instance;
```

## 3. Nomenclatura
### 3.1 Classes e Enums
A Nomenclatura deve seguir o padrão "CamelCase" para Classes e Enums.
Nomes de classes devem ser compostos por substantivos.
```c++
class Guard : public Object
```
### 3.2 Atributos
Para atributos o padrão adotado é o "lowerCamelCase".

```c++
static ActionID removeGuardID;
```
### 3.3 Métodos, Funções, Variáveis, Namespaces
Para metodos, funções, variaves e namespaces o padrão usado deve ser o "snake_case".
Metodos e Funções devem conter pelo menos um verbo e um substantivo.

```c++
void update_vision();
```
### 3.4 Constantes e Macros
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
### 4.1 Ordem de Declaração
As declarações devem vir na ordem do mais aberto (public) para o mais fechado (private) no contexto de encapsulamento.
*public* antes de *protected*, *protected* antes de *private*.
As primeiras declarações devem ser de Construtores e Destrutores, logo depois os atributos, seguidos dos metodos.

```c++
class Font_Manager
{
public:
    static Font_Manager *Instance();
    static void init() throw (Exception);
    void load_font(string path, unsigned int font_size) throw (Exception);
    void close_font();

    SDL_Texture* message()const;
    void make_message(SDL_Renderer *renderer, string message, Color color) throw (Exception);

protected:
    Font_Manager();
    ~Font_Manager();

private:
    static Font_Manager *instance;
    SDL_Texture *m_message;
    TTF_Font *m_font;
};
```

### 4.2 Construtores e Destrutores

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
### 4.3 Métodos e Funções

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
#### 4.3.1 Retorno

O tipo de retorno deve ser declarado sempre antes do nome da função na mesma linha.

```c++
...

void show_health()
{
	...
}

...
```
## 5. Formatação
### 5.1 Indentação

Para identação sera usado o padrão de tabulação de 4 espaços.
### 5.2 Tamanho máximo da linha

Não fazer muito coisa na mesma linha. Para isso não acontecer, você deve evitar ultrapassar o limite de 80 caracteres por linha.
Para quebras de linha, em casos de expressões muito grandes, deve-se usar os seguintes principios:
* Quebrar após virgula;

```c++

Impl(Button *button, const string& idle_image_id,
	const string& active_image_id)
	: m_button(button), m_text(nullptr), m_idle(Color::GREEN),
	m_active(Color::BLUE), m_border(Color::BLACK), m_thickness(1),
	m_state(IDLE)
```

* Quebrar antes de operadores;

```c++

Item* pill = new Item(m_player, "icon_pill", path, (double)env->canvas->w()
* 1/35 + 2, (double)env->canvas->h() * 25/30 + 2, 9999, true);
m_player->add_child(pill);
```

* Alinhar a nova linha com o mesmo nivel do inicio da expressão da linha anterior
### 5.3 Operadores

Para operadores deve-se dar um espaço antes e um depois.

```c++
m_player->set_stamina(m_player->stamina() + 0.05);
```
### 5.4 Chaves

Deve-se usar chaves sempre que possível, mesmo em situações em que a linguagem permita que não seja usada. 
As chaves devem ser abertas uma linha abaixo do termino da expressão ou declaração e deve ser fechada uma linha abaixo do bloco de instruções:

```c++

if(x + m_player->w() > env->canvas->w())
{
	x = env->canvas->w() - m_player->w();
}
```
### 5.5 Estruturas de Controle (if, switch)

Sempre usar 'else' em estruturas de controle do tipo 'if'.Em estruturas do tipo 'switch', os 'cases' que representam o fluxo principal devem vir antes dos cases que representam fluxo alternativo ou mensagens de erro.
O padrão a ser seguido é de sem espaços entre a estrutura de controle e o parentese da condição, e entre as operações das condições. É preferível usar operações utilizando os comandos 'and', 'or', 'not', pertencentes à linguagem c++ ao invés de comandos menos intuitivos como '&&', '||', '!='.

Codigo ruim:
```c++
 if(id != Button::clickedID)
 {
     return false;
 }
```

codigo bom:
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

### 5.6 Estruturas de Repetição (while, for, do-while)

O padrão a ser seguido é sem espaços entre a estrutura de repetição e o parentese, e nas condições de repetição espaços apos os <ponto e virgula>, e entre os sinais de relação e operação espaço antes e depois.
```c++
for(int id = 1; id < quantidade_salas; id++)
{
    Room * aux = room_list.at(rand() % id);
    CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
    aux ++;
}
```
### 5.7 Variáveis e Atributos

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

## 6. Comentários
### 6.1 Comentário de Linha
Para comentários de uma única linha devem ser utilizadas barras duplas

```c++
// Room Criation
```
### 6.2 Comentário de Bloco
Para comentários de duas ou mais linhas devem ser utilizadas a barra com o asterisco

```c++
/*
string *str;
str = (string*)(&id);
*str = "stage1";
*/
```

## 7. Outras Características Funcionais
### 7.1 JavaDoc
A documentação no estilo "JavaDoc" deve ser usada para comentarios de classe ou metodos.
É aconselhavel apenas o uso de @param, @return, @throws e em alguns casos @deprecated.
Para qualquer comentario ao estilo JavaDoc de classe e metodos deve se usar comentarios de @param, @return, @throws e @deprecated se necessario. O padrão adotado foi o seguinte:
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
### 7.2 Assertivas
Assertivas devem ser usadas sempre que houver um comportamento inesperado, condições impossiveis e dados corrompidos que não podem ser tratados.
Seus parametros devem conter no minimo uma condição e uma mensagem de erro ou com o estado e/ou valor esperado.

```c++
assert(percent >= 0   && "Must be >= 0")
```

### 7.3 Exceções
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
