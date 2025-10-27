#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
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

FragTrap &FragTrap::operator=(const FragTrap &original)
{
    if (this != &original)
	{
		this->name = original.name;
		this->hit = original.hit;
		this->energy = original.energy;
		this->damage = original.damage;
    }
    std::cout << YELLOW << "[DEBUG]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

void	FragTrap::highFivesGuys()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "> \"HIGH FIVES, GUYS!!!\" requests FragTrap " << YELLOW << this->name << DEFAULT << " with hope of making new friends, shoving its hand in the air." << std::endl;
	else
		std::cout << "> FragTrap " << YELLOW << this->name << DEFAULT << " tried, but it's too weak to high fives anyone..." << std::endl;
}