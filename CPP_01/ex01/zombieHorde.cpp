#include "Zombie.hpp"

//Alloue la horde en une seule allocation avec le mot-clé "new", puis attribue le nom à chaque instance, retourne la tête de l'array.
Zombie *zombieHorde( int n, std::string name )
{
	Zombie *horde = new Zombie[n];
    
    for (int i = 0; i < n; i++)
        horde[i].giveName(name);
    return (horde);
}