# Folha de Estilo

Este documento descreve as convenções adotadas para o desenvolvimento do jogo Seven Keys.

*You also can read in english at [Stylesheet](Stylesheet.md)*.

##Sumário
#### [1. Arquivos Header (.hpp)]()
#### [2. Escopo]()
#### [3. Nomenclatura]()
###### [2.1 Classes]()
###### [2.1.1 Atributos]()
###### [2.1.2 Métodos]()
###### [2.1.3 Constantes]()
###### [2.1.4 Parameters]()
###### [2.1.5 Variáveis Locais]()

___

####   [3. Formatação de código](#4-formatting)
###### [3.1 Arquivo Fonte]()
###### [3.1 Braces](#41-braces-1)
###### [3.2 Block Indentation](#42-block-indentation-1)
###### [3.3 Statements Per Line](#43-statements-per-line-1)
###### [3.4 Column Limit](#44-column-limit-1)
###### [3.5 Comma/Operator separation](#45-commaoperator-separation-1)
###### [3.6 Specific Constructs](#46-specific-constructs-1)
___

####  [4. Praticas de programação]()
###### [4.1 Exceções]()
###### [4.2 Assertivas]()
###### [4.1 Javadoc C++]()
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

##2. Escopo

2.1 Includes
	
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

2.2 Namespaces

Namespaces should be used whenever possible
Namespaces should always be named

```c++
using namespace std;
```

2.3 Variaveis Locais

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


2.4 Variaveis globais e estaticas (static) 

Variaveis estaticas devem ser usadas somente quando necessario devido a seus riscos de variacoes e mau uso ao longo do codigo, quando nao utilizada como constante (const).

```c++
static Font_Manager *instance;
```

## 3.  Nomenclatura

A Nomenclatura deve seguir o padrão "CamelCase" para Classes e Enums.

```c++
class Guard : public Object
```

Para atributos o padrão adotado é o "lowerCamelCase".

```c++
static ActionID removeGuardID;
```

Para metodos, variaves e namespaces o padrão usado deve ser o "snake_case".

```c++
void update_vision();
```

Para constantes e macros deverá ser usado o "SCREAMING_SNAKE_CASE".

```c++
#define SPEED 150.5
```

Em structs será usado "snake_case", o mesmo deverá ser acompanhado de um "typedef" que segue o padrão CamelCase.

```c++
typedef struct _Area
{
    double left, right;
    double top, bottom;
} Area;
```

## 4. Classes

Classes devem possuir metodos e atributos condizentes com o que seu nome especifica

4.1 Construtores e Destrutores

Construtores devem sempre ser definidos em cada classe

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

Apenas destrutores virtuais sao permitidos, quando necessarios

4.2 Structs

Structs devem possuir apenas dados primarios e nao podem ser implementadas quaisquer tipo de funcoes ou afins

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
