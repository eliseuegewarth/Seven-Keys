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

'''c++
class Guard : public Object
'''
'''c++
guard.cpp
'''
'''c++
guard.hpp
'''

## 3.  Nomenclatura

A Nomenclatura deve seguir o padrão "CamelCase" para Classes e Enums.

'''c++
class Guard : public Object
'''

Para metodos, atributos, variaves e namespaces o padrão usado deve ser o "snake_case".

'''c++
void update_vision();
'''

Para constantes e macros deverá ser usado o "SCREAMING_SNAKE_CASE".

'''c++
#define SPEED 150.5
'''

Em structs será usado "snake_case", o mesmo deverá ser acompanhado de um "typedef" que segue o padrão CamelCase.

'''c++
typedef struct _Area
{
    double left, right;
    double top, bottom;
} Area;
'''

#### 1.1 Nome do Arquivo
The source file name consists of the case-sensitive name of the top-level class it contains, plus the `.java` extension.


#### 1.2 Structure
  * Header, containing the file name. It may contain the file purpose if needed.
  * Package statement.
  * Import statements.
  * One top-level class/interface.

``` Java
/*
*file: State.java
*purpose: determine the State model
*/

package com.mdsgpp.eef.model;

import java.util.ArrayList;
import java.util.HashMap;


public class State {
 ...
 }
```

#### 1.3 Import Statements

##### 1.3.1 Wildcard Imports
`import com.mdsgpp.eef.model.*`
Wildcard imports should not be used.

##### 1.3.2 Line Wrapping
Import statements should never be line-wrapped. The column limit does not apply to import statements.
<!-- Exemplo -->

#### 1.4 Class Declaration

##### 1.4.1 Only one top-level class declaration
Each top-level class resides in its own source file.
<!-- Exemplo -->

##### 1.4.2 Class Member Order
  * `private` attributes and methods.
  * `protected` attributes and methods.
  * `public` attributes and methods.
``` Java
public class News implements Serializable {

	private static final long serialVersionUID = 1L;
	private String newsTitle;
	...
	// protected members

	public News(Feed newsFeed) {
		this.newsFeed = newsFeed;
	}
	...
```

## Scoping

2.1 Includes
	
	primeiro o header do arquivo fonte
	depois as bibliotecas da engine
	depois as bibliotecas especificas do jogo
	depois as bibliotecas padroes do c/c++

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

2.3 Local Variables

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


2.4 Static and Global Variables

Variaveis estaticas devem ser usadas somente quando necessario devido a seus riscos de variacoes e mau uso ao longo do codigo, quando nao utilizada como constante (const).

```c++

static Font_Manager *instance;

```

## 3. Naming

#### 3.1 Classes
UpperCamelCase
``` Java
 public class FeedPersistencia { //good
...

```

#### 3.2 Methods
lowerCamelCase()
``` Java
public int getStatePopulation() {
	return statePopulation;
}
```

#### 3.3 Class Members
lowerCamelCase
``` Java
 private String stateName;
```

#### 3.4 Constants
SCREAMING_SNAKE_CASE
``` Java
 public static final String BUILD_TYPE = "debug";
```

#### 3.5 Local Variables
lowerCamelCase
``` Java
public Grade[] returnEmptyGrade() {
	Grade emptyGrade[] = { new Grade(0,0) };
	emptyGrade[0].setGradeYear(0);

	return emptyGrade;
}
```

#### 3.6 Parameters
lowerCamelCase
``` Java
public void setStateName(String stateName) {
	this.stateName = stateName;
}
```
4 Classes

4.1 Constructors and destructors

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
    : m_impl(new Animation::Impl(texture, x, y, w, h, frames, speed_in_ms, loop))
{
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

4.3 Classes

Classes devem possuir metodos e atributos condizentes com o que seu nome especifica

3.3 Inheritance

Prefer using Composition instead of Inheritance, but use Inheritance when it suits
Multiple Inheritance should be used only when, between it's base classes, there is only one non-virtual class
3.4 Virtual Classes

Virtual classes may be used when convenient

3.5 Operator Overloading

May be used if it's result is obvious and expected

3.6 Access Control

Class members should be private unless they're static const

3.7 Declaration Order

public before private
using declarations, typedefs and enums
Constants (static const data members)
Constructors
Destructors
Methods, including static methods
Data Members
class CZString
{
    public:
        enum DuplicationPolicy
        {
            noDuplication = 0,
            duplicate,
            duplicateOnCopy
        };
        CZString(ArrayIndex index);
        CZString(const char* cstr, DuplicationPolicy allocate);
        CZString(const CZString& other);
        ~CZString();
        CZString& operator=(const CZString& other);
        bool operator<(const CZString& other) const;
        bool operator==(const CZString& other) const;
        ArrayIndex index() const;
        const char* c_str() const;
        bool isStaticString() const;

    private:
        void swap(CZString& other);
        const char* cstr_{nullptr};
        ArrayIndex index_;
};

## 7. Formatting

#### 4.1 Braces

##### 4.1.1 Braces are always mandatory
Braces should be used following the K & R Style, even if the block is empty.

##### 4.1.2 Brace spacing
There must be a space between the method name definition (or arguments) and the opening brace.
``` Java
public String getStateName() {	//good
...
public String getStateName(){	//bad
```

#### 4.2 Block indentation
Each time a new block is opened, the line indent increases by four spaces. At the end of the block, the line indent recedes accordingly. This applies to both code and comments throughout the block.

#### 4.3 Statements per line
There should be only one statement per line, followed by a line break.
``` Java
//good
if (percentageCollaborationWithPIB == null) {
	double[] empty = {0};
	return empty;
}

//bad
if (percentageCollaborationWithPIB == null) {
	double[] empty = {0}; return empty;
}
```

#### 4.4 Column limit
Each line has a maximum character count of 100, except on package and import statements, or where absolutely impossible to do so.
``` Java
public void setAgeGradeDistortionRate(HashMap<String, ArrayList<String[]>> information, //break
	String[] namesOfIndicative) {
	this.ageGradeDistortionRate = this.setGrade(information, namesOfIndicative);
	}
```

#### 4.5 Comma/Operator separation
A comma or operator must always be followed by a whitespace character.
``` Java
public State(String stateName, String stateAbbreviation, HashMap<String, ArrayList<String[]>> information){ //space after comma
	this.stateName = stateName;  // space after operator
	this.stateAbbreviation=stateAbbreviation; //no space after operator => BAD
```

#### 4.6 Specific Constructs

##### 4.6.1 Enum Classes
After each component of an enum declaration, a line break is optional, as long as the declaration does not exceed the column character limit.

##### 4.6.2 Variable declaration

###### 4.6.2.1 Number of variables declared per line
Each line that contains variable declarations must contain the declaration of a single variable.
``` Java
	//good declaration
	private String stateName;
	private String stateAbbreviation;

	//bad declaration
	private string stateName, stateAbbreviation;
```

###### 4.6.2.2 Variable scope and initialization
Variables must only be declared when absolutely needed, and initialized as soon as possible.

##### 4.6.3 Arrays

###### 4.6.3.1 Initializers
Arrays may be initialized following a block style. However, a single-line initialization is recommended on the cases where this does not exceed the line character limit.

###### 4.6.3.2 C-Style array declarations
Arrays are declared with the brackets being a part of the variable, not the type.
``` Java
double empty[] = {0}; //good
double[] empty = {0}; //bad
```

##### 4.6.4 Switch statements
Switch statements follow the formatting guide as described. The only salve is that the `default:` case is always present, even if it is empty.
<!-- Exemplo -->

###### 4.6.4.1 Empty default case
An empty default case must indicate that it actually does nothing.
<!-- Exemplo -->

##### 4.6.5 Comments

###### 4.6.5.1 Single-line Comments
Must be  written after a `// ` representation, and must start with an uppercase letter.

###### 4.6.5.2 Multi-line Comments
For multi-line comments, the following structure is recommended: `/* ... */`. Subsequent lines must start with `*` aligned with the `*` on the previous line.
