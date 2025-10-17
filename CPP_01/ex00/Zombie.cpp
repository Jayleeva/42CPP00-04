#include "Zombie.hpp"

//Constructeur: assigner le nom reçu en argument au membre "name" de l'instance construite, en utilisant le mot-clé "this".
Zombie::Zombie( std::string name )
{
	this->name = name;
}

//Destructeur: imprimer le nom de l'instance suivi du message de destruction, toujours avec le mot-clé "this".
Zombie::~Zombie()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

//Fonction membre: imprimer le nom de l'instance suivi du message d'annonce, toujours avec le mot-clé "this".
void Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}