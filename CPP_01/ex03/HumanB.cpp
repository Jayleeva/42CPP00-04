#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//Construit l'instance et assigne à son nom celui reçu en argument.
HumanB::HumanB(std::string name)
{
	this->name = name;
}

//Déconstruit l'instance et imprime un message.
HumanB::~HumanB()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

//Comme n'est pas un constructeur, ne peut pas initialiser la référence comme dans HumanA().
//Assigne l'arme de l'instance avec celle référencée en argument.
void	HumanB::setWeapon(Weapon &w)
{
	this->w = &w;
}

//Imprime le message d'attaque en récupérant le nom de l'instance et son arme.
//Comme on utilise un pointeur pour l'arme, on appelle getType avec "->" et pas '.'.
void	HumanB::attack(void)
{
	std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
}
