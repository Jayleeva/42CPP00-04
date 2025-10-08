#include "Zombie.hpp"

//Retourne une nouvelle instance créée avec le mot-clé "new" suivi d'un appel du constructeur 
Zombie *newZombie( std::string name )
{
	return (new Zombie(name));
}
