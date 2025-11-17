#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Classe dérivée. On ajoute "virtual" pour pouvoir reecrire la fonction attack
class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &original);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif