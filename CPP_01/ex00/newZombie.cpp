#include "Zombie.hpp"

//Retourne une nouvelle instance créée avec le mot-clé "new" (allocation dynamique, donc sur la heap) suivi d'un appel du constructeur 
Zombie *newZombie( std::string name )
{
	return (new Zombie(name));
}
