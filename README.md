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

### Pointeur - '\*'
Un pointeur est une variable (avec sa propre adresse mémoire) contenant l'adresse mémoire de la variable sur laquelle il pointe.

Pour signifier un pointeur lors de la déclaration du type de variable, on utilise '\*'. Attention, en-dehors des déclarations de type, si on utilise '\*', on déférence le pointeur.

### Référence - '&'
Une référence est une adresse mémoire contenant la valeur de la variable qu'elle référence.

Pour signifier une référence, on utilise '&'.


### Utilisation en C
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
Dans notre exemple, la variable ```a``` n'est pas un pointeur, si bien que pour qu'elle puisse être assignée à ```b```, qui elle est un pointeur, on doit la référencer avec '&'. Même logique lors de l'appel de la fonction ```incr()```.

A l'inverse, lors de l'appel de la fonction ```printf()```, on veut imprimer la valeur de ```a```, donc pas besoin de la référencer, et la valeur de ```b```, qui elle doit être déréférencée. Sinon, on aura une erreur de compilation, qu'on pourra corriger de deux façons: soit on déférence ```b``` pour imprimer sa valeur, soit on utilise '%p' à la place de '%d' pour imprimer son adresse (comme dans la fonction ```incr()```).

### Utilisation en C++
Désormais, nos variables peuvent être directement des références, recevables telles quelles par nos fonctions:
```
class	MannequinA
{
	public:
		MannequinA(std::string model, Bag &bag);
	private:
		std::string	model;
		Color		&bag;
};
```
ATTENTION, si une référence est attendue par un **constructeur** (voir chapitre sur les classes), elle doit être initialisée. Pour ce faire, on ajoute ```: yourRef(yourRef)``` à la suite du nom de la fonction:
```
MannequinA::MannequinA(std::string model, Bag &bag): bag(bag)
```
ATTENTION, une telle initialisation n'est possible QUE dans un **constructeur**.

ATTENTION, bien qu'on puisse utiliser les références, on peut toujours utiliser des pointeurs:
```
class	MannequinB
{
	public:
		MannequinB(std::string model);
		void	setBag(Bag &bag);
	private:
		std::string	model;
		Bag		*bag;
};
```
Ici, il est plus intéressant d'utiliser un pointeur au lieu d'une référence car ???

Dans les exercices en C++, il arrive aussi de référencer des fonctions entières:
```
class	Bag
{
	public:
		Bag(string brand);
		string const	&getBag();
		void			setBag(string brand);
	private:
		string	brand;
};
```
Car ???

Il est intéressant de noter que dans le main, rien ne nous indique clairement qu'on utilise des références ou des pointeurs.
C'est dans la définition des fonctions appelées que cela devient visible.
```
int	main()
{
	{
		Bag hermes = Bag("Hermes");
	
		MannequinA female("Female model", hermes);
	}
	{
		Bag louisvitton = Bag("Louis Vitton");

		MannequinB male("Male model");
		male.setBag(louisvitton);
	}
}
```




## Classe
Les classes me font penser aux structures du C, en mieux.
- Leur instanciation crée un objet, qui peut contenir non seulement des variables mais aussi des fonctions, dites "membres"!
- Les variables et fonctions d'une classe peuvent être protégées afin d'éviter des modifications fortuites!
- Les classes peuvent être liées entre elles par de l'héritage, ce qui permet d'éviter des répétitions ET d'affiner ses objets!

La structure générale d'une classe est la suivante:

```
Class	YourClass
{
	public:								//les variables et fonctions publiques sont accessibles en-dehors de la classe
		YourClass();							//constructeur par défaut
		~YourClass();							//destructeur

		int		getVarExample() const;			//getter
		void	setVarExample(int var);			//setter

	private:							//les variables et fonctions privées ne sont pas accessibles en-dehors de la classe
		int	varExample;
}
```

Dans le fichier .cpp, on définit les fonctions de la façon suivante:

```
YourClass::YourClass()
{
	std::cout << "[YOURCLASS]: Default constructor called" << std::endl;		//par exemple.
}

YourClass::~YourClass()
{
	std::cout << "[YOURCLASS]: Destructor called" << std::endl;				//par exemple.
}

int		YourClas::getVarExample() const
{
	return (this->varExample);
}

void	YourClass::setVarExample(int var)
{
	this->varExample = var;
}
```

A partir d'un certain module, il est demandé d'utiliser la forme orthodoxe canonique.

Il faut alors ajouter plusieurs choses:

```
Class	YourClass
{
	public:								//les variables et fonctions publiques sont accessibles en-dehors de la classe
		YourClass();							//constructeur par défaut
		~YourClass();							//destructeur
		YourClass(int var);						//constructeur avec int
		YourClass(const YourClass &src);		//constructeur par copie
		YourClass &operator=(YourClass &src);	//copie par surcharge d'opérateur d'assignation (assignment operator overload)

		int		getVarExample() const;			//getter
		void	setVarExample(int var);			//setter

	private:							//les variables et fonctions privées ne sont pas accessibles en-dehors de la classe
		int	varExample;
}
```

Dans le fichier .cpp, on adapte:

```
YourClass::YourClass()
{
	std::cout << "[YOURCLASS]: Default constructor called" << std::endl;		//par exemple.
}

YourClass::~YourClass()
{
	std::cout << "[YOURCLASS]: Destructor called" << std::endl;					//par exemple.
}

YourClass::YourClass(int var)
{
	std::cout << "[YOURCLASS]: Int constructor called" << std::endl;			//par exemple.
	this->varExample = var;
}

MyClass::MyClass(const MyClass &src)
{
	std::cout << "[YOURCLASS]: Copy constructor called" << std::endl;			//par exemple.
	*this = src;
}

YourClass	&YourClass::operator=(YourClass &src)
{
	std::cout << "[YOURCLASS]: Copy assignment operator called" << std::endl;	//par exemple.
	if (this != &src)
	{
		this->varExample = src.varExample;
	}
	return (*this);
}

int		YourClas::getVarExample() const
{
	return (this->varExample);
}

void	YourClass::setVarExample(int var)
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
YourClass();
```

#### Constructeur avec argument
Selon les cas, il peut être intéressant d'utiliser un constructeur spécifique qui reçoit un argument et en assigne la valeur à la variable concernée.

Exemple:
```
YourClass(int var);
```

#### Constructeur par copie
Ce constructeur reçoit une référence à un objet déjà créé, et assigne l'objet référencé à une déréférenciation de lui-même.

Exemple:
```
YourClass(const YourClass &src);
```

#### Constructeur par surcharge d'opérateur d'assignation
Une surcharge d'opérateur signifie qu'on redéfinit ce que fait l'opérateur par défaut.

L'opérateur d'assignation est tout simplement le '=' (le symbole qu'on utilise pour assigner).

Ce constructeur reçoit lui aussi une référence à un objet déjà créé et la compare avec lui-même: si l'objet n'est pas déjà égal à la référence reçue en argument, on assigne chaque valeur à sa variable correspondante.

Exemple:
```
YourClass &operator=(YourClass &src);
```

### Destructeur
Pour supprimer un objet, une classe a besoin d'un destructeur.

Il se compose strictement d'une ``~`` du nom de la classe et de parenthèses.
