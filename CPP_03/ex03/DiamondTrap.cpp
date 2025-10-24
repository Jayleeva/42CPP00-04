#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP default constructor called" << DEFAULT << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = FragTrap::hit;
	//this->hit = 100;
	std::cout << "diamond hit = " << this->hit << std::endl;
	this->energy = ScavTrap::energy;
	//this->energy = 50;
	this->damage = FragTrap::damage;
	//this->damage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original): ClapTrap(original), FragTrap(original), ScavTrap(original)
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP destructor called" << DEFAULT << std::endl;
}

void	DiamondTrap::whoAmI()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "\"Who am I? I... I think my DiamondTrap name is " << this->name << ", and the ClapTrap one is " << ClapTrap::name << " ? I'm not sure though...\" says the DiamondTrap." << std::endl;
	else
		std::cout << "The DiamondTrap tried, but it's too weak to recall its names." << std::endl;
}