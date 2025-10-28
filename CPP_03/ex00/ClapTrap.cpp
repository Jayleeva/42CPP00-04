#include "ClapTrap.hpp"

		
ClapTrap::ClapTrap()
{
	std::cout << YELLOW << "[CLAPTRAP]: Default constructor called" << DEFAULT << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << YELLOW << "[CLAPTRAP]: string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = 10;
	this->energy = 10;
	this->damage = 0;
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
		this->hit = original.hit;
		this->energy = original.energy;
		this->damage = original.damage;
    }
    std::cout << YELLOW << "[CLAPTRAP]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->hit > 0 && this->energy > 0)
	{
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " attacks " << YELLOW << target << DEFAULT << ", causing " << this->damage << " points of damage!" << std::endl;
		this->energy--;
	}
	else
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to attack..." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " takes " << amount << " points of damage!" << std::endl;
	this->hit -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit > 0 && this->energy > 0)
	{
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " regains " << amount << " hit points!" << std::endl;
		this->hit += amount;
		this->energy--;
	}
	else
		std::cout << "> ClapTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to repair itself..." << std::endl;
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
