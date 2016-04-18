# Folha de Estilo

Este documento descreve as convenções adotadas para o desenvolvimento do jogo Seven Keys.

*You also can read in english at [Stylesheet](Stylesheet.md)*.

## Sumário

___

#### [1. Arquivos Header (.hpp)](#1-arquivos-header-hpp-1)

#### [2. Escopo](#2-escopo-1)
###### [2.1 Includes](#21-includes-1)
###### [2.2 Namespaces](#22-namespaces)
###### [2.3 Variaveis Locais](#23-variaveis-locais)
###### [2.4 Variaveis Globais e Estáticas](#24-variaveis-globais-e-estaticas-static)

#### [3. Nomenclatura](#3-nomenclatura)
###### [3.1 Classes e Enums](#31-classes-e-enums-1)
###### [3.2 Atributos](#32-atributos-1)
###### [3.3 Metodos, Funções, Variaves, Namespaces](#33-metodos-funções-variaves-namespaces-1)
###### [3.4 Constantes e Macros](#34-constantes-e-macros-1)
###### [3.5 Structs](#35-structs-1)
###### [3.6 Typedef](#36-typedef-1)
###### [3.7 Ponteiros](#37-ponteiros-1)

#### [4. Classes](#4-classes-1)
###### [4.1 Ordem de Declaração](#41-ordem-de-declaração-1)
###### [4.2 Construtores e Destrutores](#42-construtores-e-destrutores)
###### [4.3 Métodos e Funções](#43-métodos-e-funções-1)
###### [4.3.1 Retorno](#431-retorno-1)
###### [4.4 Herança](#44-herança-1)
###### [4.5 Abstract vs Virtual](#45-abstract-vs-virtual-1)
###### [4.6 Sobrecarga](#46-sobrecarga-1)

#### [5. Formatação](#5-formatação-1)
###### [5.1 Indentação](#51-indentação-1)
###### [5.2 Tamanho máximo da linha](#52-tamanho-maximo-da-linha)
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
###### [7.3 Exceções](#74-casting)

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
### 2.3 Variaveis Locais

Declare as variaveis o mais localmente possivel
As variaveis devem ser declaradas o mais proximo do seu uso
Todas as variaveis devem ser inicializadas.


```c++
	for(int id = 1; id < quantidade_salas; id++){
        Room * aux = room_list.at(rand() % id);
		CreateRoom(aux, &id, aux->pos_x, aux->pos_y, quantidade_salas, stage_id);
        aux ++;
	}
```
### 2.4 Variaveis globais e estaticas (static)

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
### 3.3 Metodos, Funções, Variaves, Namespaces
Para metodos, funções, variaves e namespaces o padrão usado deve ser o "snake_case".
Metodos e Funções devem conter pelo menos um verbo e um substantivo.

```c++
void update_vision();
```
### 3.4 Constantes e Macros
Para constantes e macros deverá ser usado o "SCREAMING_SNAKE_CASE".

```c++
#define SPEED 150.5
```
### 3.5 Structs
Em structs será usado "snake_case", o mesmo deverá ser acompanhado de um "typedef" que segue o padrão CamelCase.

```c++
typedef struct _Area
{
    double left, right;
    double top, bottom;
} Area;
```
### 3.6 Typedef
### 3.7 Ponteiros

## 4. Classes

Classes devem possuir metodos e atributos condizentes com o que seu nome especifica.
### 4.1 Ordem de Declaração
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
### 4.4 Herança
### 4.5 Abstract vs Virtual
### 4.6 Sobrecarga

## 5. Formatação
### 5.1 Indentação

Para identação sera usado o padrão de tabulação de 4 espaços.
### 5.2 Tamanho Maximo da linha

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
### 5.3 Operadores

Para operadores deve-se dar um espaço antes e um depois.

```c++
m_player->set_stamina(m_player->stamina() + 0.05);
```
### 5.4 Chaves

As chaves devem ser abertas uma linha abaixo do termino da expressão ou declaração e deve ser fechada uma linha abaixo do bloco de instruções:

```c++

if (x + m_player->w() > env->canvas->w())
{
	x = env->canvas->w() - m_player->w();
}
```
### 5.5 Estruturas de Controle (if, switch)
### 5.6 Estruturas de Repetição (while, for, do-while)
### 5.7 Variáveis e Atributos
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
### 7.2 Assertivas
### 7.3 Exceções
### 7.4 Casting

Deve-se evitar o *cast* forçado como o seguinte:

```c++
m_player->x() + (moviment.first * delta)/1000.0;
```
A maneira correta de se fazer é usando o *cast* da propria linguagem:

```c++
m_player->x() + (moviment.first * delta) / (double)1000;
```
