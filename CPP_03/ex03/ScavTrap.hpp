#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Classe dérivée. Pour éviter l'ambiguité, on ajoute "virtual" après "public". 
class ScavTrap: public virtual ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();

		void	guardGate();
};

#endif