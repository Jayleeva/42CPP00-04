#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << YELLOW << "[DEBUG]: SCAVTRAP default constructor called" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << YELLOW << "[DEBUG]: SCAVTRAP string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original): ClapTrap(original)
{
	std::cout << YELLOW << "[DEBUG]: SCAVTRAP copy constructor called" << DEFAULT << std::endl;
	this->name = original.getName();
	this->hit = original.getHit();
	this->energy = original.getEnergy();
	this->damage = original.getDamage();
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "[DEBUG]: SCAVTRAP destructor called" << DEFAULT << std::endl;
}

void	ScavTrap::guardGate()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "ClapTrap " << this->name << " is now in Gate Keeper mode." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " tried, but it's too weak to enter Gate Keeper mode..." << std::endl;
}