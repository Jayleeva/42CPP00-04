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
		ScavTrap &operator=(const ScavTrap &original); // pour que diamond prenne bien les valeurs des classes enfants au lieu de parent, pas compris comment though

		void	guardGate();
};

#endif