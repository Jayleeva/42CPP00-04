#include "Zombie.hpp"

//Réappelle le constructeur avec le nom reçu en argument et fait l'annonce de son zombie.
void randomChump( std::string name )
{
	Zombie	z = Zombie(name);
	z.announce();
}