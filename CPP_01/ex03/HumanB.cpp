#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanB::HumanB(string name)
{
	this->name = name;
}

HumanB::~HumanB()
{
	cout << this->name << " has been destroyed." << endl;
}

void	HumanB::setWeapon(Weapon w)
{
	this->w = w;
}

void	HumanB::attack(void)
{
	cout << this->name << "attacks with their " << this->w.getType() << endl;
}
