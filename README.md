

sed: pour ouvrir le fichier, utiliser ifstream et ofstream comme type de variable, puis ifstream.open() puis if (!isopen()) pour check si ouverture a marche. 


# Notions importantes

**ATTENTION: on ne fait plus du C, mais bien du C++!**
- On utilise les fonctions de la librairie standard (std)!!! Pas besoin de tout coder de zéro!!!
- On utilise les types propres au C++! Fini les char* (dans la plupart des cas), vive les string!
- On n'utilise plus ```malloc()``` et ```free()``` pour allouer dynamiquement (sur la heap), mais ```new``` et ```delete```.
- On n'utilise plus ```printf()``` pour imprimer, mais ```cout```.
- Pour faire un retour à la ligne, on préfère ```endl``` au ```\n```. 
- On n'utilise que des librairies en C++, qui se démarquent car ne finissent pas par .h dans les include. Ex.: ```#include <iostream>```
- Les extensions changent: au lieu de ```.c``` et ```.h```, on utilise désormais ```.cpp``` et ```.hpp```.
- Les noms des fichiers prennent le nom de la classe qu'ils définissent, et commencent donc par une majuscule!

**ATTENTION: même si c'est bien pratique, pas le droit aux namespace!! Pour appeler une fonction ou un mot-clé de la std, il faut y accoller ```std::``` en préfixe.**

Exemple:
```
std::toupper()
```

## Deux mots sur le mot-clé "const"
Lorsqu'on précise qu'une variable est constante, on empêche sa modification.

Pour le préciser, on utilise le mot-clé "const" avant ce qu'on veut rendre constant:
```
const char c1;           //Le caractère ne peut être modifié
const char * c2;         //Le caractère pointé ne peut être modifié

char * const c3;         //Le pointeur vers le caractère ne peut être modifié
OU
char const *s (prototype donné pour certaines fonctions de la libft)?

const char * const c4;   //Le pointeur ET le caractère pointé ne peuvent être modifiés
```
```
1. `const char *p` => pointer to a constant char
2. `char * const p (OR char const *p ?)` => constant pointer to a char
3. `const char * const p` => constant pointer to a constant char
```

Dans les exercices en C++, les références (voir le chapitre sur les pointeurs et références) sont souvent constantes. On peut compiler sans les rendre constantes, mais le faire permet de sécuriser le code un peu plus?
```
YourClass const &operator=(YourClass const &src);
```
Idem pour les fonctions getter (voir le chapitre sur les classes): puisqu'elles ne modifient rien, on peut les rendre constantes de la façon suivante:
```
std::string	YourClass::getElement() const
{}
```

## Eviter les doubles inclusions
Si on ne fait pas attention, on peut inclure un même fichier plusieurs fois, ce qui reviendrait à redéfinir ce qu'il contient, et donc empêcherait la compilation.

Pour éviter ce problème, on peut faire comme, en réalité, on a déjà fait jusque-là, avec des ```ifndef, define, endif```.

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
Un pointeur est une variable (avec sa propre adresse mémoire) dont la valeur est une référence à la variable sur laquelle il pointe, soit l'adresse mémoire de celle-ci.

Pour signifier un pointeur lors de la déclaration du type de variable, on utilise '\*'. Attention, en-dehors des déclarations de type, si on utilise '\*', on déréférence le pointeur, ce qui permet d'accéder à la valeur pointée plutôt qu'à son adresse.

Un pointeur peut ne pas être initialisé. Il peut être réassigné.

Aussi, lorsqu'un pointeur a des propriétés (par ex. si c'est une instanciation d'une structure ou d'une classe), on y accède avec '->', au lieu de '.' si ce n'était pas un pointeur.

Exemples:
```
your_struct_instance.var_example;	//l'instance n'est pas référencée
```
```
this->varExample;					//l'instance est référencée
```
ASTUCE: Le mot-clé ```this``` (propre au C++) est toujours un pointeur.

### Référence - '&'
Une référence est une variable "alias" qui partage son adresse mémoire avec celle de la variable sur laquelle elle pointe.
La valeur d'une référence est donc celle de la variable qu'elle référence.

Pour signifier une référence, on utilise '&'.

Une référence DOIT être initialisée, elle ne peut pas être utilisée vide. De plus, elle ne peut pas être réassignée.


### Utilisation en C
Jusqu'ici, nous avons utilisé les deux de la façon suivante:
```
void	incr(int *ptr)									//Réception du pointeur (avec '*' pour signifier que c'est un pointeur)
{
	*ptr += 1;											//modification de la valeur contenue dans l'adresse pointée par le pointeur (avec '*' pour déréférencer)
	printf("address = %p\n", ptr);						//impression de l'adresse pointée par le pointeur (sans '*' pour ne pas déréférencer)
}

int	main()
{
	int	a = 42;											//déclaration d'un int et assignation d'une valeur 42
	int	*b = &a;										//déclaration d'un pointeur sur int et assignation de la référence à a grâce à '&' (avec '*' pour signifier que c'est un pointeur)

	incr(b);											//appel de la fonction d'incrémentation, en passant le pointeur (sans '*' pour ne pas déréférencer)
	incr(&a);											//appel de la fonction d'incrémentation, en passant la référence grâce à '&'
	printf("a value = %d and b value = %d\n", a, *b);	//impression de la valeur de a, suivie de la valeur contenue dans l'adresse pointée par le pointeur (avec '*' pour déréférencer)
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
		Bag		&bag;
};
```
Ici, la variable &bag est une référence car il s'agit en réalité d'une instance d'une autre classe.

ATTENTION, si une référence est attendue par une fonction, elle doit être initialisée. Pour ce faire, soit elle l'est avant l'appel de la fonction, soit on ajoute ```: yourRef(yourRef)``` à la suite du nom de la fonction:
```
MannequinA::MannequinA(std::string model, Bag &bag): bag(bag)
```
Typiquement, une telle initialisation n'est nécessaire que dans un **constructeur** (voir chapitre sur les classes). En effet, quand on appelle un **constructeur par copie** ou un **constructeur par surcharge d'opérateur d'assignation** , la référence reçue est déjà initialisée: c'est la source à copier.

ATTENTION, dans certains cas, il vaut mieux utiliser des pointeurs:
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
De même que dans notre classe MannequinA précédente, la variable *bag est en réalité une instance d'une autre classe. En revanche ici, vu que cet objet n'est pas initialisé directement dans le constructeur mais dans un setter à part, qui ne sera pas forcément appelé, on utilise un pointeur au lieu d'une référence. Pour rappel, une référence DOIT être initialisée et ne peut pas être réassignée, alors qu'un pointeur n'a pas ces contraintes.

Dans les exercices en C++, on peut aussi référencer les opérateurs, lorsqu'on veut les surcharger:
```
class	Bag
{
	public:
		Bag(std::string brand);
		Bag const &operator=(Bag const &src);	//surcharge d'opérateur d'assignation
		std::string	getBag() const;
		void		setBag(string brand);
		
	private:
		std::string	brand;
};
```
*Je suppose que c'est une syntaxe obligatoire qui permet de faire la surcharge: sans, ça ne marche pas.*

Il est intéressant de noter que dans le main, aucun '\*' ou '&' ne nous indique clairement qu'on utilise des références ou des pointeurs.
C'est dans la définition des fonctions appelées que cela devient visible.
En revanche, si on sait que l'on instancie une classe avant de passer ce nouvel objet au constructeur d'une autre classe, comme c'est le cas ici, on comprend qu'il sera forcément pointé/référencé.
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

ATTENTION, lorsque votre fonction getter est virtuelle, il faut absolument la référencer de la façon suivante:
```
virtual YourClass   &getElement(void) const = 0;
```

## Classe
Les classes me font penser aux structures du C, en mieux.
- Leur instanciation crée un objet, qui peut contenir non seulement des variables mais aussi des fonctions, dites "membres"!
- Les variables et fonctions d'une classe peuvent être protégées afin d'éviter des modifications fortuites!
- Les classes peuvent être liées entre elles par de l'héritage, ce qui permet d'éviter des répétitions ET d'affiner ses objets!

### Public, private, protected
Les variables et fonctions membres sont classées en 3 categories: publiques, privées, et protégées.

Une bonne pratique (exigée dans le cursus) est de mettre toutes les variables membres en private/protected, afin qu'elles ne puissent pas être accidentellement modifiées en-dehors de la classe. Les fonctions (constructeurs, destructeur, setter et getter, etc) sont elles mises en public afin de pouvoir être utilisées en-dehors de la classe.

Les setter et getter permettent d'acceder aux variables privées/protégées en-dehors de la classe. Ainsi, il y en a autant qu'il y a de variables privées/protégées qu'on doit pouvoir accéder.

C'est quoi être "en-dehors de la classe"? Par défaut, si vous n'êtes pas dans le scope de la déclaration de votre classe, vous êtes "en-dehors" de celle-ci. Cependant, lorsque vous créez une instance de votre classe, vous pouvez y "rentrer" via cette instance, en y appondant un '.' ou un '->' si c'est un pointeur.

Dans les fichiers .cpp ou vous définissez les fonctions membres, le mot-clé ``this`` correspond à une instance. Il devient disponible quand vous précisez que votre fonction est membre de votre classe en ajoutant ``YourClass::`` devant le nom de la fonction.

La catégorie "protégée" n'est utilisée que lorsqu'il y a héritage. Elle permet de "partager" l'accès aux variables et fonctions qui y sont rangées avec les classes de la même "famille".

### Structure générale d'une classe
Dans le header (.hpp), on déclare les variables et fonctions publiques, privées et/ou protégées: 
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
	std::cout << "[YOURCLASS]: Destructor called" << std::endl;					//par exemple.
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

### Forme orthodoxe canonique
A partir d'un certain module, il est demandé d'utiliser la forme orthodoxe canonique.

Il faut alors ajouter plusieurs choses:

```
Class	YourClass
{
	public:								//les variables et fonctions publiques sont accessibles en-dehors de la classe
		YourClass();										//constructeur par défaut
		~YourClass();										//destructeur
		YourClass(int var);									//constructeur avec int
		YourClass(YourClass const &src);					//constructeur par copie
		YourClass const &operator=(YourClass const &src);	//copie par surcharge d'opérateur d'assignation (assignment operator overload)

		int		getVarExample() const;						//getter
		void	setVarExample(int var);						//setter

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

YourClass::YourClass(YourClass const &src)
{
	std::cout << "[YOURCLASS]: Copy constructor called" << std::endl;			//par exemple.
	*this = src;
}

YourClass	const &YourClass::operator=(YourClass const &src)
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
YourClass(int var)
{
	this->varExample = var;
}
```

#### Constructeur par copie
Ce constructeur reçoit une référence à un objet déjà créé, et assigne l'objet référencé à une déréférenciation de lui-même.

Exemple:
```
YourClass(const YourClass &src)
{
	*this = src;
}
```

#### Constructeur par surcharge d'opérateur d'assignation
Une surcharge d'opérateur signifie qu'on redéfinit ce que fait par défaut l'opérateur.

L'opérateur d'assignation est tout simplement le '=' (le symbole qu'on utilise pour assigner).

Ce constructeur reçoit lui aussi une référence à un objet déjà créé et la compare avec lui-même: si l'objet n'est pas déjà égal à la référence reçue en argument (protection facultative?), on assigne chaque valeur à sa variable correspondante. La fonction retourne le mot-clé ```this``` déréférencé, soit l'instance créée par la fonction.

Exemple:
```
YourClass const	&operator=(YourClass const &src)
{
    if (this != &src)
	{
		this->varExample0 = src.varExample0;
		this->varExample1 = src.varExample1;
    }
	return (*this);
}
```

### Destructeur
Pour supprimer un objet, une classe a besoin d'un destructeur.

Il se compose strictement d'une ``~`` du nom de la classe et de parenthèses.

Exemple:
```
~YourClass();
```

### Héritage
On peut faire "hériter" une classe d'une autre. Basiquement, la seconde classe aura des propriétés communes avec la première. Par exemple, la classe Vélo peut hériter de la classe Véhicule, car un vélo est un véhicule, et que tous les deux ont un nombre de roues par ex, même si le nombre en soi peut être different.

C'est difficile de vraiment voir l'intérêt de ce système sans un exercice concret. Typiquement, dans un jeu video, on pourrait créer une classe Objet, puis des classes Arme, Munition, Consommable, Quête, ... Et on pourrait détailler ensuite avec d'autres classes encore, Epée, Massue, Fusil, ... Ce qui fait que quand vous voudrez coder "telle arme est utilisée et cause tant de dégâts", vous n'aurez besoin que des fonctions et variables de la classe parente, au lieu d'en avoir une différente par arme.

Toutes les caractéristiques communes à plusieurs classes devraient donc idéalement être identifiées et déclarées dans une classe parente dont elles hériteront. 

Pour signifier qu'une classe hérite d'une autre, on ajoute ``: public YourParentClass`` après la déclaration de la classe héritière. De son côté, la classe parente passe ses variables privées qu'elle va devoir partager en protégées.

```
Class	YourParentClass
{
	public:								
		YourParentClass();
		~YourParentClass();

		int		getSharedVar() const;
		void	setSharedVar(int var);

	protected:			
		int	sharedVar;
}
```

```
Class	YourHeritedClass0 : public YourParentClass
{
	public:								
		YourHeritedClass0();
		~YourHeritedClass0();

		void	UniqueFunction();
}
```

On peut faire hériter une classe de deux classes parentes différentes (A et B), qui elles-mêmes héritent d'une classe "chapeau": elle récupère certaines caractéristiques de la classe parente A, et d'autres de la B. Cependant, cela peut créer de l'ambiguité, qu'il faut contrer avec le mot-clé ``virtual`` après le ``public`` qui précède le nom de la classe parente.

```
Class	YourHeritedClass1 : public virtual YourParentClass
{
	public:
		YourHeritedClass1();
		~YourHeritedClass1();

		void	UniqueFunction();
}
```

```
Class	YourDoubleHeritedClass : public YourHeritedClass0, public YourHeritedClass1
{
	public:								
		YourDoubleHeritedClass();
		~YourDoubleHeritedClass();

		void	UniqueFunction();
}
```

### Polymorphisme
Il est possible de redéfinir des fonctions héritées pour qu'elles aient des comportements propres à la classe héritée à laquelle elles appartiennent. Par exemple, créons la classe parente Animal, les classes enfants Poule et Vache, et faisons-les hériter de la fonction product(): on peut préciser que pour Poule, cette fonction imprimera "oeuf", alors que pour Vache, elle imprimera "lait". Si c'est directement Animal qui l'appelle, elle imprimera un truc par defaut, par ex "produit".

Les fonctions qui sont ainsi réécrites doivent être rendues ``virtual`` dans la classe parente pour fonctionner, exemple:
```
virtual	void	product();
``` 
Cela s'applique aussi aux déconstructeurs pour éviter les comportements inattendus suite au mélange de ``delete`` avec le polymorphisme.

## Différence entre deep et shallow copy
Lorsqu'on copie une variable, on peut copier soit sa valeur, soit son adresse.

- Si on copie son adresse, les deux variables contiendront toujours la même valeur partagée, car elles accèdent au même endroit de la mémoire. Modifier l'une modifiera l'autre.
- Si on copie sa valeur, les deux variables ne seront pas liées, et modifier l'une ne modifiera pas l'autre.

### Deep copy
La deep copy nécessite d'aller copier un à un tous les attributs de l'objet copié.

Lors de la libération de la mémoire, il faudra libérer les espaces attribués à chaque objet, car ce sont bien deux objets séparés.

### Shallow copy
La shallow copy nécessite uniquement de copier l'adresse de l'objet.

Lors de la libération de la mémoire, il ne faudra libérer que l'unique espace partagé par chaque objet.

## Fixed points

### Le problème des int et des floats
Pourquoi aurait-on besoin de fixed points? Parce que les int comme les floats manquent soit de précision (precision) soit d'exactitude (accuracy). Qu'est-ce donc que ce charabia qui joue sur les mots?

Les int sont très précis: 2 n'est rien d'autre que 2, ni plus, ni moins. En revanche, ils manquent d'exactitude, car ne permettent pas de représenter ne serait-ce qu'un 2.5, par exemple. Et que dire d'un 2.725? Ou pire, d'un 3.14159265359...?

Mais les floats règlent ce problème, non? Puisqu'on peut détailler des décimales? Hélas.

- Premièrement, ils manquent de précision: remontez à vos souvenirs d'école, ou vous appreniez que 3/3 = 1, mais aussi, que 1/3 = 0.333 infini, alors que 3 x 0.333 = 0.999. Le consensus mathématique est de dire que 3 x 0.333 infini = 0.999 infini = 1. Il y a comme quelque chose qui nous démange, mais oui, mathématiquement, 0.999 infini est bien égal à 1, car 3 divisé par 3 fait bien 1, même si 1 divisé par 3 donne 0.333 infini. Vous voyez l'idée? Bon, retenez juste que les floats manquent de précision.
- Deuxièmement, même s'ils sont plus exacts que les int, ils ne le sont pas complètement, du aux limitations matérielles de la machine. En effet, comment représenter matériellement le nombre Pi par exemple, avec une machine qui, de par sa nature, ne peut stocker qu'un nombre limité de décimales? Nous sommes contraints de nous contenter d'une approximation.

Pour des choses simples, nous n'avons pas besoin d'une exactitude parfaite. Cependant, de micro inexactitudes en micro inexactitudes, on finit par obtenir des résultats déviant significativement de la réalité.

Est-ce que les fixed points règlent ce problème? Non (lol). A quoi bon alors?

Les fixed points permettent ET d'utiliser des entiers (pour plus de précision), ET de détailler des décimales au besoin (pour plus d'exactitude).

### Les fixed points: comment ça marche?
Pour comprendre les fixed points, il faut comprendre les binary points. Pas de panique! On respire.

Même si vous ne le savez pas, vous êtes familier-es avec les decimal points, parce que oui, vous connaissez la base 10 (si si, je vous jure). Dix, décimal, vous voyez le lien? (déci = 10). 

#### Base 10, 16, 2...
Vous avez appris à compter en base 10. Qu'entend-on par là? Si vous deviez compter jusqu'à 50, vous itéreriez une première base 10, puis une deuxième, etc jusqu'à 5 itérations + 1. En effet, nos chiffres occidentaux commencent à 0 et vont jusqu'à 9 (donc 10 chiffres, base 10, tout ça), puis on recommence, en mettant à jour la dizaine, la centaine, etc.

	0	0|1|2|3|4|5|6|7|8|9
	1	0|1|2|3|4|5|6|7|8|9
	2	0|1|2|3|4|5|6|7|8|9
	...
	10	0|1|2|3|4|5|6|7|8|9
	11	0|1|2|3|4|5|6|7|8|9
	12	0|1|2|3|4|5|6|7|8|9
	...

En informatique, on compte parfois en base 16. Ces chiffres vont de 0 à 16, mais pour plus de clareté (dépendant du point de vue), la suite est la suivante: 0 1 2 3 4 5 6 7 8 9 A B C D E F. De même que pour la base 10, une fois arrivé à F, on reprend avec le 0 en mettant à jour la "seizaine". Par exemple, la valeur 17 en base 10 s'écrirait 11 en base 16 (on passe de (0)F à 10, puis de 10 à 11), la valeur 30 en base 10 s'écrirait 1E en base 16.

	0	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	1	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	...
	9	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	A	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	B	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	...
	10	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	11	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F
	...
	1F	0|1|2|3|4|5|6|7|8|9|A|B|C|D|E|F

Pour les fixed points, on s'intéressera à la base 2, celle utilisée par... le langage binaire (bi = 2). La suite est bien plus courte: 0 1. Donc dès la valeur 2 en base 10, on réitère, ce qui donne 10 en base 2.

	0	0|1|	-> 0|1 en base 10
	1	0|1|	-> 2|3 en base 10
	10	0|1|	-> 4|5 en base 10
	11	0|1|	-> 6|7 en base 10
	100	0|1|	-> 8|9 en base 10
	101	0|1|	-> 10|11 en base 10
	...

Un byte a la valeur d'un chiffre de cette suite: soit 1 soit 0.

Un bit est composé de 8 bytes, par ex.: 01010101 (soit 85 en base 10, soit "U" sur la table ASCII par ailleurs).

Le bitshifting est une opération qu'on peut effectuer sur les bits, et qu'on va utiliser dans les fixed points.

### Decimal points, binary points
Un point décimal est tout simplement "la virgule" qui sépare un chiffre de ses... décimales. Par exemple, le float 42.2314 a son point décimal après le premier 2: s'ensuivent les "chiffres après la virgule". Ces "chiffres après la virgule" peuvent être représentés par des fractions. Le point nous sert de repère: "à partir de là, on pourrait représenter ces chiffres par une fraction".

Dans la même logique, le point binaire est "la virgule" qui sépare un chiffre de ses "binairales?" ou plutôt, de ses "fractional bits"; le repère qui nous dit la même chose que le point décimal.

Dans son article "Introduction to Fixed Point Number Representation", Hayden So nous explique que pour traduire un nombre binaire en base 10, on fait le calcul suivant:

- Le byte voisin de gauche du binary point est multiplié par 2 (car base 2) puissance 0 (car premier byte pré-point)
- Celui juste à gauche de lui est multiplié par 2 puissance 1, son voisin direct par 2 puissance 2, et ainsi de suite jusqu'au dernier byte pré-point.
- Dans la continuité de cette logique, le premier byte après le point est multiplié par 2 puissance -1, le deuxième par 2 puissance -2, etc.
- On additionne ensuite tous ces produits pour obtenir le nombre en base 10.

Exemple:

|2<sup>4</sup>|2<sup>3</sup>|2<sup>2</sup>|2<sup>1</sup>|2<sup>0</sup>|Binary point|2<sup>-1</sup>|2<sup>-2</sup>|2<sup>-3</sup>|
| ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- | ----------- |
|0|0|0|1|0|.|1|1|0|
|0 * 2<sup>4</sup>|0 * 2<sup>3</sup>|0 * 2<sup>2</sup>|1 * 2<sup>1</sup>|0 * 2<sup>0</sup>|.|1 * 2<sup>-1</sup>|1 * 2<sup>-2</sup>|0 * 2<sup>-3</sup>|
|0|0|0|2|0|.|0.5|0.25|0|

**Résultat :	0 + 0 + 0 + 2 + 0 + 0.5 + 0.25 + 0 = 2.75**

Si bien qu'en bitshiftant d'un bit vers la droite, on divise le résultat par deux, et en bitshiftant d'un bit vers la gauche, on le multiplie par deux.

### Pourquoi du bitshift?
Notre objectif est de pouvoir avoir la précision d'un int et l'exactitude d'un float. Pour réaliser cette prouesse, on va transformer notre nombre avec le bitshift. Un fixed point est donc, en realite, un nombre binaire qui peut etre traduit en int comme en float arrondi, en fonction du besoin.

En bitshiftant notre nombre de 8, on s'assure de stocker toutes les informations importantes dans un nombre plutôt grand (x256).

Une fois cela fait, on peut choisir d'en faire un int ou un float. Dans les deux cas, il va falloir re-bitshift dans l'autre sens.

Seulement, on ne peut pas bitshift un float. Pour contourner ce probleme, au lieu de leftbitshift notre float de 8, on le multiplie par (1 leftbitshift de 8), ce qui revient au meme car comme vu plus haut, bitshift de 1 revient a multiplier ou diviser par 2. Idem pour rightbitshift notre float, comme ce n'est pas possible, on le divise par (1 leftbitshift de 8), soit par 256.

ATTENTION: quand on crée le fixedPt en recevant un float, on doit en réalite cast le résultat de notre calcul en int, car c'est le type donné a la variable qui en stocke la valeur. A l'inverse, au moment d'acceder a sa forme float (dans la fonction ToFloat(), appelee notamment par la surcharge d'operateur <<), il faut cast le résultat en float pour correspondre au type de retour attendu. 

Démonstration de bitshifting:
```
42 << 8
			101010
1			010100
10			101000
101			010000
1010		100000
10101		000000
101010		000000
1010100		000000
10101000	000000
```
10101000000000<sub>2</sub> = 10752<sub>10</sub>

```
42.31 * (1 << 8), puis arrondir le résultat, puis le cast en int à cause du type de la variable privée.
1 << 8

	00000000	00000001
1	00000000	00000010
0	00000000	00000100
...
	00000001	00000000
```
0000000100000000<sub>2</sub> = 256<sub>10</sub>

### Les operateur << et >>
Ces operateurs ont un sens different en fonction du contexte.

On peut les utiliser pour inserer des elements dans un stream (entrant ou sortant), ET pour le bitshifting (gauche ou droite).

Dans les exercices de C++ de 42 autour des fixed points, on les emploie pour les deux utilisations. On surcharge specifiquement <<, qui insere des elements dans un stream de sortie, afin que s'il recoit un fixdePt, il insere non pas le fixedPt entier mais bien uniquement la valeur de ses raw bits (la version binaire du nombre recu a sa creation), qui par defaut sera recuperee sous forme de float. On ne touche cependant pas a leur role de bitshifters.

## Lire dans l'entree standard
Le C++ permet d'utiliser simplement le mot-clé ``cin`` pour lire des inputs dans l'entrée standard, cependant, il n'est pas toujours adapté pour ce qu'on souhaite faire.

La fonction ``getline()`` va être importante, notamment pour lire des suites de mots séparés par des espaces, mais il faut egalement la protéger au cas où elle lirait EOF (fin du fichier), afin d'éviter des comportements inattendus.

Pour vérifier si une string est vide, on oublie le if (!str), et on utilise la fonction ``empty()``.
