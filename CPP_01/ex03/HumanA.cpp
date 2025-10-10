#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

HumanA::HumanA(string name, Weapon w)
{
	this->name = name;
	this->w = w;
}

HumanA::~HumanA()
{
	cout << this->name << " has been destroyed." << endl;
}

void	HumanA::attack(void)
{
	cout << this->name << " attacks with their " << this->w.getType() << endl;
}
