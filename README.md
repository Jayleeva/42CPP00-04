# Notions importantes

**ATTENTION: on ne fait plus du C, mais bien du C++!**
- On utilise les fonctions de la librairie standard (std)!!! Pas besoin de tout coder de zéro!!!
- On utilise les types propres au C++! Fini les char* (dans la plupart des cas), vive les string!
- On n'utilise plus ```malloc()``` et ```free()``` pour allouer dynamiquement (sur la heap), mais ```new``` et ```delete```.
- On n'utilise plus ```printf()``` pour imprimer, mais ```cout```. Pour prendre un input utilisateur, on utilise ```cin```. 
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

### Pointeur
Un pointeur est une adresse mémoire contenant l'adresse mémoire de la variable sur laquelle il pointe?
Passer un pointeur à une fonction lui permet d'accéder à l'adresse mémoire où est stockée la valeur de la variable.

### Référence
Une référence est une adresse mémoire contenant la valeur de la variable qu'elle référence.
Passer l'adresse à une fonction lui permet d'accéder à son contenu.



