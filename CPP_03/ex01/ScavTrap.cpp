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
	this->setName(original.getName());
	this->setHit(original.getHit());
	this->setEnergy(original.getEnergy());
	this->setDamage(original.getDamage());
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "[DEBUG]: SCAVTRAP destructor called" << DEFAULT << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate Keeper mode." << std::endl;
}