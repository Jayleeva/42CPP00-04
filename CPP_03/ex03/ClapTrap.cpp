#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << YELLOW << "[CLAPTRAP]: Default constructor called" << DEFAULT << std::endl;
}

ClapTrap::ClapTrap(std::string name_)
{
	std::cout << YELLOW << "[CLAPTRAP]: string constructor called" << DEFAULT << std::endl;
	this->name = name_;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->damagePoints = 0;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << YELLOW << "[CLAPTRAP]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "[CLAPTRAP]: Destructor called" << DEFAULT << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
    if (this != &original)
	{
		this->name = original.name;
		this->hitPoints = original.hitPoints;
		this->energyPoints = original.energyPoints;
		this->damagePoints = original.damagePoints;
    }
    std::cout << YELLOW << "[CLAPTRAP]: Copy assignment operator called" << DEFAULT << std::endl;
    return (*this);
}
void	ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to attack..." << std::endl;
	else
	{
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " attacks " << YELLOW << target << DEFAULT << ", causing " << this->damagePoints << " points of damage!" << std::endl;
		this->energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " takes " << amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to repair itself..." << std::endl;
	else
	{
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " regains " << amount << " hit points!" << std::endl;
		this->hitPoints += amount;
		this->energyPoints--;
	}
}


std::string const	ClapTrap::getName() const
{
	return(this->name);
}

int	ClapTrap::getHit() const
{
	return(this->hitPoints);
} 

int	ClapTrap::getEnergy() const
{
	return(this->energyPoints);
}

int	ClapTrap::getDamage() const
{
	return(this->damagePoints);
}

void	ClapTrap::setName(std::string name_)
{
	this->name = name_;
}

void	ClapTrap::setHit(int hit)
{
	this->hitPoints = hit;
}

void	ClapTrap::setEnergy(int energy)
{
	this->energyPoints = energy;
}

void	ClapTrap::setDamage(int damage)
{
	this->damagePoints = damage;
}
