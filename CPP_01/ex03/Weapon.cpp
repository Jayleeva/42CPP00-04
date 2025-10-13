#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

Weapon::Weapon()
{}

Weapon::Weapon(string type)
{
	this->type = type;
}

Weapon::~Weapon()
{}

string const&	Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(string type)
{
	this->type = type;
}
