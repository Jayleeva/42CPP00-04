#include "Zombie.hpp"

//Constructeur: créer une nouvelle instance.
Zombie::Zombie()
{}

//Destructeur: imprimer le nom de l'instance suivi du message de destruction, en utilisant le mot-clé "this".
Zombie::~Zombie()
{
	cout << this->name << " has been destroyed." << endl;
}

//Fonction membre: assigner le nom reçu en argument à l'instance, toujours avec le mot-clé "this".
void	Zombie::giveName( std::string name)
{
	this->name = name;
}

//Fonction membre: imprimer le nom de l'instance suivi du message d'annonce, toujours avec le mot-clé "this".
void Zombie::announce( void )
{
	cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}