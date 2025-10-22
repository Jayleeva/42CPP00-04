#include "ClapTrap.hpp"

		
ClapTrap::ClapTrap()
{

}

ClapTrap::ClapTrap(std::string name)
{

}

ClapTrap::ClapTrap(const ClapTrap &original)
{

}

ClapTrap::~ClapTrap()
{

}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing" << this->damage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " regains " << amount << " hit points!" << std::endl;
}