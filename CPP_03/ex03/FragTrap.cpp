#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	std::cout << YELLOW << "[DEBUG]: FRAGTRAP default constructor called" << DEFAULT << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	std::cout << YELLOW << "[DEBUG]: FRAGTRAP string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->damage = 30;
}

FragTrap::FragTrap(const FragTrap &original): ClapTrap(original)
{
	std::cout << YELLOW << "[DEBUG]: FRAGTRAP copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "[DEBUG]: FRAGTRAP destructor called" << DEFAULT << std::endl;
}

void	FragTrap::highFivesGuys()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "\"HIGH FIVES, GUYS!!!\" requests ClapTrap " << this->name << " with hope of making new friends, shoving its hand in the air." << std::endl;
	else
		std::cout << "ClapTrap " << this->name << " tried, but it's too weak to high fives anyone..." << std::endl;
}