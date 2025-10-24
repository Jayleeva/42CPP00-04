#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << YELLOW << "[DEBUG]: Default constructor called" << DEFAULT << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << YELLOW << "[DEBUG]: string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy constructor called" << DEFAULT << std::endl;
	this->setName(original.getName());
	this->setHit(original.getHit());
	this->setEnergy(original.getEnergy());
	this->setDamage(original.getDamage());
}

ClapTrap::~ClapTrap()
{
	std::cout << YELLOW << "[DEBUG]: Destructor called" << DEFAULT << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->damage << " points of damage!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->setHit(this->getHit() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " regains " << amount << " hit points!" << std::endl;
	this->setEnergy(this->getEnergy() - 1);
}


std::string const	ClapTrap::getName() const
{
	return(this->name);
}

int	ClapTrap::getHit() const
{
	return(this->hit);
} 

int	ClapTrap::getEnergy() const
{
	return(this->energy);
}

int	ClapTrap::getDamage() const
{
	return(this->damage);
}

void	ClapTrap::setName(std::string name)
{
	this->name = name;
}

void	ClapTrap::setHit(int hit)
{
	this->hit = hit;
}

void	ClapTrap::setEnergy(int energy)
{
	this->energy = energy;
}

void	ClapTrap::setDamage(int damage)
{
	this->damage = damage;
}
