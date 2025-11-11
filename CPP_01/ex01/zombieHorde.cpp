#include "Zombie.hpp"

//Alloue la horde en une seule allocation avec le mot-clé "new", puis attribue un nom à chaque instance, retourne la tête de l'array.
Zombie *zombieHorde( int N, std::string name )
{
	Zombie *horde = new Zombie[N];
    //std::string  names[7] = {name, "Zavier", "Zénon", "Zélie", "Zelda", "Zara", "Zoé"}; //pour le debug

    for (int i = 0; i < N; i++)
    {
        //name = names[i];  //pour le debug
        horde[i].giveName(name);
    }
    return (horde);
}