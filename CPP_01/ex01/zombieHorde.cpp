#include "Zombie.hpp"

//Alloue la horde en une seule allocation avec le mot-clé "new" (sans appeler le constructeur? en utilisant juste la classe comme un type, avec le N comme taille?), puis attribue un nom à chaque instance, retourne la tête de l'array.
Zombie *zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
    std::string  names[7] = {name, "Zavier", "Zénon", "Zélie", "Zelda", "Zara", "Zoé"};
    int     i = 0;

    while (i < N)
    {
        name = names[i];
        horde[i].giveName(name);
        i ++;
    }
    return (horde);
}