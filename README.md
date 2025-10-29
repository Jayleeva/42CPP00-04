# Notions importantes

**ATTENTION: on ne fait plus du C, mais bien du C++!**
- On utilise les fonctions de la librairie standard (std)!!! Pas besoin de tout coder de zéro!!!
- On utilise les types propres au C++! Fini les char* (dans la plupart des cas), vive les string!
- On n'utilise plus ```malloc()``` et ```free()``` pour allouer dynamiquement (sur la heap), mais ```new``` et ```delete```.
- On n'utilise plus ```printf()``` pour imprimer, mais ```cout```.
- Pour faire un retour à la ligne, on préfère ```endl``` au ```\n```. 
- On n'utilise que des librairies en C++, qui se démarquent car ne finissent pas par .h dans les include. Ex.: ```#include <iostream>```

**ATTENTION: même si c'est bien pratique, pas le droit aux namespace!! Pour appeler une fonction ou un mot-clé de la std, il faut y accoller ```std::``` en préfixe.**

Exemple:
```
std::toupper()
```

## Eviter les doubles inclusions
En vérité, on peut faire comme on a fait jusque-là, avec des ```ifndef, define, endif```.

On peut aussi remplacer ce système en écrivant simplement ```pragma once``` en début de header, pour le même résultat.

## Différence entre heap et stack
Jusqu'ici, 42 ne nous demandait pas de bien connaître la différence entre la stack et la heap, bien qu'on ait déjà eu besoin des deux. 
Ce n'est pas un concept nouveau, mais on nous demande désormais explicitement d'en avoir une bonne compréhension.

### Heap
Mémoire allouée dynamiquement, soit avec ```malloc()``` en C, et avec ```new``` en ++, et libérée avec ```free()``` en C et ```delete``` en C++.
Cette mémoire doit être libérée manuellement lorsqu'on n'en a plus besoin, pour ne pas causer de leaks.

### Stack
Mémoire allouée de manière statique?: l'espace est résérvé à la déclaration et ne peut pas être modifié sans allocation dynamique. Par exemple: 
```
int	array[10];
```
Cette mémoire est libérée automatiquement à la fin de la fonction / du programme, et ne cause pas de leaks.

## Différence entre pointeur et référence
De même que pour la heap/stack, bien qu'on ait déjà utilisé et les pointeurs et les références, c'est la première fois qu'on nous demande explicitement de comprendre leurs différences.

Les deux permettent de passer des adresses mémoires au lieu de simples valeurs, ce qui permet de conserver les modifications effecutées sur leur contenu d'une fonction à l'autre.

Jusqu'ici, nous avons utilisé les deux de la façon suivante:
```
void	incr(int *ptr)									//Réception du pointeur (avec '*' pour signifier que c'est un pointeur)
{
	*ptr += 1;											//modification de la valeur contenue dans l'adresse pointée par le pointeur (avec '*' pour dérérencer)
	printf("address = %p\n", ptr);						//impression de l'adresse pointée par le pointeur (sans '*' pour ne pas dérérencer)
}

int	main()
{
	int	a = 42;											//déclaration d'un int et assignation d'une valeur 42
	int	*b = &a;										//déclaration d'un pointeur sur int et assignation de la référence à a grâce à '&' (avec '*' pour signifier que c'est un pointeur)

	incr(b);											//appel de la fonction d'incrémentation, en passant le pointeur (sans '*' pour ne pas déréférencer)
	incr(&a);											//appel de la fonction d'incrémentation, en passant la référence grâce à '&'
	printf("a value = %d and b value = %d\n", a, *b);	//impression de la valeur de a, suivie de la valeur contenue dans l'adresse pointée par le pointeur (avec '*' pour dérérencer)
}

//On ne veut pas déréférencer quand on doit travailler avec l'adresse mémoire; à l'inverse, on veut déréfencer quand on doit travailler avec la valeur contenue dans l'adresse.
```

Désormais,


### Pointeur - '\*'
Un pointeur est une adresse mémoire contenant l'adresse mémoire de la variable sur laquelle il pointe.

Pour signifier un pointeur lors de la déclaration du type de variable, on utilise '\*'. Attention, en-dehors des déclarations de type, si on utilise '\*', on déférencie le pointeur.

### Référence - '&'
Une référence est une adresse mémoire contenant la valeur de la variable qu'elle référence.

Pour signifier une référence, on utilise '&'.


## Classe
Les classes me font penser aux structures du C, en mieux.
- Leur instanciation crée un objet, qui peut contenir non seulement des variables mais aussi des fonctions, dites "membres"!
- Les variables et fonctions d'une classe peuvent être protégées afin d'éviter des modifications fortuites!
- Les classes peuvent être liées entre elles par de l'héritage, ce qui permet d'éviter des répétitions ET d'affiner ses objets!

La structure générale d'une classe est la suivante:

```
Class	MyClass
{
	public:								//les variables et fonctions publiques sont accessibles en-dehors de la classe
		MyClass();								//constructeur par défaut
		~MyClass();								//destructeur

		int		getVarExample() const;			//getter
		void	setVarExample(int var);			//setter

	private:							//les variables et fonctions privées ne sont pas accessibles en-dehors de la classe
		int	varExample;
}
```

Dans le fichier .cpp, on définit les fonctions de la façon suivante:

```
MyClass::MyClass()
{
	std::cout << "[MYCLASS]: Default constructor called" << std::endl;		//par exemple.
}

MyClass::~MyClass()
{
	std::cout << "[MYCLASS]: Destructor called" << std::endl;				//par exemple.
}

int		MyClas::getVarExample() const
{
	return (this->varExample);
}

void	MyClass::setVarExample(int var)
{
	this->varExample = var;
}
```

A partir d'un certain module, il est demandé d'utiliser la forme orthodoxe canonique.

Il faut alors ajouter plusieurs choses:

```
Class	MyClass
{
	public:								//les variables et fonctions publiques sont accessibles en-dehors de la classe
		MyClass();								//constructeur par défaut
		~MyClass();								//destructeur
		MyClass(int var);						//constructeur avec int
		MyClass(const MyClass &src);			//constructeur par copie
		MyClass &operator=(MyClass &src);		//copie par surcharge d'opérateur d'assignation (assignment operator overload)

		int		getVarExample() const;			//getter
		void	setVarExample(int var);			//setter

	private:							//les variables et fonctions privées ne sont pas accessibles en-dehors de la classe
		int	varExample;
}
```

Dans le fichier .cpp, on adapte:

```
MyClass::MyClass()
{
	std::cout << "[MYCLASS]: Default constructor called" << std::endl;			//par exemple.
}

MyClass::~MyClass()
{
	std::cout << "[MYCLASS]: Destructor called" << std::endl;					//par exemple.
}

MyClass::MyClass(int var)
{
	std::cout << "[MYCLASS]: Int constructor called" << std::endl;				//par exemple.
	this->varExample = var;
}

MyClass::MyClass(const MyClass &src)
{
	std::cout << "[MYCLASS]: Copy constructor called" << std::endl;				//par exemple.
	*this = src;
}

MyClass	&MyClass::operator=(MyClass &src)
{
	std::cout << "[MYCLASS]: Copy assignment operator called" << std::endl;		//par exemple.
	if (this != &src)
	{
		this->varExample = src.varExample;
	}
	return (*this);
}

int		MyClas::getVarExample() const
{
	return (this->varExample);
}

void	MyClass::setVarExample(int var)
{
	this->varExample = var;
}
```

L'ordre des éléments n'a pas d'importance, cependant, la forme orthodoxe canonique exige:
- un constructeur par défaut
- un destructeur
- un constructeur avec argument (si intéressant/nécessaire?)
- un constructeur par copie 
- un constructeur par surcharge d'opérateur d'assignation

### Constructeurs
Pour instancier un objet, une classe a besoin de constructeurs. Elle doit en avoir un par défaut, et peut en avoir d'autres. 

En C, les multiples constructeurs seraient considérés comme une erreur, puisqu'on redéfinit une fonction déjà définie. En C++, le compilateur comprend que même si elle porte le même nom, puisque les arguments sont différents, il s'agit d'une autre fonction. 

#### Constructeur par défaut
Le strict minimum est d'avoir un constructeur par défaut, soit sans arguments. Il se compose strictement du nom de la classe et de parenthèses.

Exemple:
```
MyClass();
```

#### Constructeur avec argument
Selon les cas, il peut être intéressant d'utiliser un constructeur spécifique qui reçoit un argument et en assigne la valeur à la variable concernée.

Exemple:
```
MyClass(int var);
```

#### Constructeur par copie
Ce constructeur reçoit une référence à un objet déjà créé, et assigne l'objet référencé à une déréférenciation de lui-même.

Exemple:
```
MyClass(const MyClass &src);
```

#### Constructeur par surcharge d'opérateur d'assignation
Une surcharge d'opérateur signifie qu'on redéfinit ce que fait l'opérateur par défaut.

L'opérateur d'assignation est tout simplement le '=' (le symbole qu'on utilise pour assigner).

Ce constructeur reçoit lui aussi une référence à un objet déjà créé et la compare avec lui-même: si l'objet n'est pas déjà égal à la référence reçue en argument, on assigne chaque valeur à sa variable correspondante.

Exemple:
```
MyClass &operator=(MyClass &src);
```

### Destructeur
Pour supprimer un objet, une classe a besoin d'un destructeur.

Il se compose strictement d'une ``~`` du nom de la classe et de parenthèses.
