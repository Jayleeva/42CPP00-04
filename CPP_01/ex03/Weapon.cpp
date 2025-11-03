#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//Constructeur par défaut. Nécessaire pour utiliser la classe comme un type de variable (ex.argument passé à une fonction).
Weapon::Weapon()
{}

//Construit l'instance et lui assigne un type d'arme.
Weapon::Weapon(string type)
{
	this->type = type;
}

//Déconstruit l'instance.
Weapon::~Weapon()
{}

//Retourne une string: le type d'arme assigné à l'instance.
std::string Weapon::getType() const
{
	return (this->type);
}

//Assigne à l'instance le type reçu en argument.
void	Weapon::setType(string type)
{
	this->type = type;
}
