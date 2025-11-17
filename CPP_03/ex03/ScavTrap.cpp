#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << YELLOW << "[SCAVTRAP]: Default constructor called" << DEFAULT << std::endl;
}

ScavTrap::ScavTrap(std::string name_): ClapTrap(name_)
{
	std::cout << YELLOW << "[SCAVTRAP]: String constructor called" << DEFAULT << std::endl;
	this->name = name_;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->damagePoints = 20;
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
		this->hitPoints = original.hitPoints;
		this->energyPoints = original.energyPoints;
		this->damagePoints = original.damagePoints;
    }
    std::cout << YELLOW << "[SCAVTRAP]: Copy assignment operator called" << DEFAULT << std::endl;
    return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "> ScavTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to attack..." << std::endl;
	else
	{
		std::cout << "> ScavTrap " << YELLOW << this->name << DEFAULT << " attacks " << YELLOW << target << DEFAULT << ", causing " << this->damagePoints << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}
void	ScavTrap::guardGate()
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "> ScavTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to enter Gate Keeper mode..." << std::endl;
	else
		std::cout << "> ScavTrap " << YELLOW << this->name << DEFAULT << " is now in Gate Keeper mode." << std::endl;
}