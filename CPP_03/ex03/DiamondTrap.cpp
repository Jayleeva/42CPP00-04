#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP default constructor called" << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name")
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = FragTrap::hit;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original): ClapTrap(original), ScavTrap(original), FragTrap(original)
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP copy constructor called" << DEFAULT << std::endl;
	//this->name = original.getName();
	//this->hit = original.getHit();
	//this->energy = original.getEnergy();
	//this->damage = original.getDamage();
	*this = original;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP destructor called" << DEFAULT << std::endl;
}

void	DiamondTrap::whoAmI()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "\"Who am I? I... I think my DiamondTrap name is " << this->name << " , and the ClapTrap one is " << ClapTrap::name << " ? I'm not sure though...\"" << std::endl;
	else
		std::cout << "The DiamondTrap tried, but it's too weak to recall its names." << std::endl;
}