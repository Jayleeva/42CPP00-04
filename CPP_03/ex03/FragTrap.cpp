#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << YELLOW << "[FRAGTRAP]: Default constructor called" << DEFAULT << std::endl;
}

FragTrap::FragTrap(std::string name_): ClapTrap(name_)
{
	std::cout << YELLOW << "[FRAGTRAP]: String constructor called" << DEFAULT << std::endl;
	this->name = name_;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->damagePoints = 30;
}

FragTrap::FragTrap(const FragTrap &original): ClapTrap(original)
{
	std::cout << YELLOW << "[FRAGTRAP]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

FragTrap::~FragTrap()
{
	std::cout << YELLOW << "[FRAGTRAP]: Destructor called" << DEFAULT << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &original)
{
    if (this != &original)
	{
		this->name = original.name;
		this->hitPoints = original.hitPoints;
		this->energyPoints = original.energyPoints;
		this->damagePoints = original.damagePoints;
    }
    std::cout << YELLOW << "[FRAGTRAP]: Copy assignment operator called" << DEFAULT << std::endl;
    return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "> FragTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to high fives anyone..." << std::endl;
	else
		std::cout << "> \"HIGH FIVES, GUYS!!!\" requests FragTrap " << YELLOW << this->name << DEFAULT << " with hope of making new friends, shoving its hand in the air." << std::endl;
}