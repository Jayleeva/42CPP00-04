#include "Zombie.hpp"

Zombie *zombieHorde( int N, std::string name )
{
	Zombie	*z;
    Zombie  *zz;
    string  names[7] = {name, "Zavier", "Zénon", "Zélie", "Zelda", "Zara", "Zoé"};
    int     i = 1;

    z = newZombie(name);
    z->announce();
    while (i < N)
    {
        name = names[i++];
        zz = newZombie(name);
        zz->announce();
        //delete zz;
    }
    return (z);
}

//Retourne une nouvelle instance créée avec le mot-clé "new" suivi d'un appel du constructeur 
Zombie *newZombie( std::string name )
{
	return (new Zombie(name));
}