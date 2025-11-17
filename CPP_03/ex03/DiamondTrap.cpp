#include "DiamondTrap.hpp"

//besoin de spécifier toutes les classes dont on hérite.
DiamondTrap::DiamondTrap(): ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << YELLOW << "[DIAMONDTRAP]: Default constructor called" << DEFAULT << std::endl;
}

//idem
DiamondTrap::DiamondTrap(std::string name_): ClapTrap(name_ + "_clap_name"), FragTrap(name_ + "_clap_name"), ScavTrap(name_ + "_clap_name")
{
	std::cout << YELLOW << "[DIAMONDTRAP]: String constructor called" << DEFAULT << std::endl;
	this->name = name_;
	this->hitPoints = FragTrap::hitPoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->damagePoints = FragTrap::damagePoints;
}

//idem
DiamondTrap::DiamondTrap(const DiamondTrap &original): ClapTrap(original.name + "_clap_name"), FragTrap(original.name + "_clap_name"), ScavTrap(original.name + "_clap_name")
{
	std::cout << YELLOW << "[DIAMONDTRAP]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << YELLOW << "[DIAMONDTRAP]: Destructor called" << DEFAULT << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &original)
{
	std::cout << YELLOW << "[DIAMONDTRAP]: Copy assignment operator called" << DEFAULT << std::endl;
	if (this != &original)
	{
		this->name = original.name;
		this->hitPoints = original.hitPoints;
		this->energyPoints = original.energyPoints;
		this->damagePoints = original.damagePoints;
	}
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
		std::cout << "> The DiamondTrap tried, but it's too weak to recall its names." << std::endl;
	else
		std::cout << "> \"Who am I? I... I think my DiamondTrap name is " << YELLOW << this->name << DEFAULT << ", and the ClapTrap one is "<< YELLOW << ClapTrap::name << DEFAULT << " ? I'm not sure though...\" says the DiamondTrap, visibly confused." << std::endl;
}