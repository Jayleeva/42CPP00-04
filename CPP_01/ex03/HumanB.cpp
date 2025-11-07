#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//Construit l'instance et assigne à son nom celui reçu en argument.
//J'initialise l'arme à 0 pour pouvoir faire fonctionner ma protection dans la fonction attack.
HumanB::HumanB(std::string name)
{
	this->name = name;
	this->w = 0;
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
//Pour éviter un comportment inattendu au cas où le setweapon n'aurait pas été appelé précédemment, auquel cas la variable n'est pas initialisée, on ajoute une protection.
void	HumanB::attack(void)
{
	if (!this->w)
		std::cout << this->name << " wants to attack, but they don't have any weapon!!!" << std::endl;
	else
		std::cout << this->name << " attacks with their " << this->w->getType() << std::endl;
}
