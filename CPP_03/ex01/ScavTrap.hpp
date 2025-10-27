#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Derived class
class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &original);

		void	guardGate();
};

#endif