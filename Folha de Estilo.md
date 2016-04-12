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

## 2. Programming Practices

#### 2.1 `@Override`
`@Override` must be used whenever it is legal. It must be placed on the line before the overridden method.
``` Java
	@Override
	protected void onPreExecute() {
	...
	}
```

#### 2.2 Exceções
Caught exceptions should never be ignored. The runtime error should be treated into the appropriate scope.
``` Java
try {
		URL url = new URL(urls[0]);
		FeedParser handler = new FeedParser();
		InputStream is = url.openStream();
		feed = handler.parse(is);

		FeedPersistencia.getInstance(this.context).writeFeedFile(feed);
		this.updated = true;

		return feed;

	} catch (MalformedURLException e) {
		e.printStackTrace();
	} catch (IOException e) {
		e.printStackTrace();
	}
```

#### 2.3 Static Members
Whenever a reference to a static member have to be called, it should be called directly from the class.
``` Java
public static FeedPersistencia getInstance(Context context) {
	 ...
	}
...

FeedPersistencia.getInstance(this.context).writeFeedFile(feed);
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

## 4. Formatting

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
