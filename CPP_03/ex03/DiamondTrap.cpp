#include "DiamondTrap.hpp"

//besoin de spécifier toutes les classes dont on hérite.
DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP default constructor called" << DEFAULT << std::endl;
}

//idem
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP string constructor called" << DEFAULT << std::endl;
	this->name = name;
	this->hit = FragTrap::hit;
	this->energy = ScavTrap::energy;
	this->damage = FragTrap::damage;
}

//idem
DiamondTrap::DiamondTrap(const DiamondTrap &original): ClapTrap(original.name + "_clap_name"), FragTrap(original.name + "_clap_name"), ScavTrap(original.name + "_clap_name")
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "[DEBUG]: DIAMONDTRAP destructor called" << DEFAULT << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &original)
{
	std::cout << YELLOW << "[DEBUG]: Copy assignment operator = called" << DEFAULT << std::endl;
	if (this != &original)
	{
		this->name = original.name;
		this->hit = original.hit;
		this->energy = original.energy;
		this->damage = original.damage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	if (this->hit > 0 && this->energy > 0)
		std::cout << "> \"Who am I? I... I think my DiamondTrap name is " << YELLOW << this->name << DEFAULT << ", and the ClapTrap one is "<< YELLOW << ClapTrap::name << DEFAULT << " ? I'm not sure though...\" says the DiamondTrap, visibly confused." << std::endl;
	else
		std::cout << "> The DiamondTrap tried, but it's too weak to recall its names." << std::endl;
}