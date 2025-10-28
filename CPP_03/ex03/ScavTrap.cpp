#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << YELLOW << "[SCAVTRAP]: Default constructor called" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	std::cout << YELLOW << "[SCAVTRAP]: String constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = 100;
	this->energy = 50;
	this->damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &original): ClapTrap(original)
{
	std::cout << YELLOW << "[SCAVTRAP]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

ScavTrap::~ScavTrap()
{
	std::cout << YELLOW << "[SCAVTRAP]: Destructor called" << DEFAULT << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
    if (this != &original)
	{
		this->name = original.name;
		this->hit = original.hit;
		this->energy = original.energy;
		this->damage = original.damage;
    }
    std::cout << YELLOW << "[SCAVTRAP]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

void	ScavTrap::guardGate()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "> ScavTrap " << YELLOW << this->name << DEFAULT << " is now in Gate Keeper mode." << std::endl;
	else
		std::cout << "> ScavTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to enter Gate Keeper mode..." << std::endl;
}