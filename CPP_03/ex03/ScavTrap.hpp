#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// Classe dérivée. Pour éviter l'ambiguité du diamond problem, on ajoute "virtual" 
class ScavTrap: virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name_);
		ScavTrap(const ScavTrap &original);
		~ScavTrap();
		ScavTrap	&operator=(const ScavTrap &original); // pour que diamond prenne bien les valeurs des classes enfants au lieu de parent, pas compris comment though

		void	attack(const std::string &target);
		void	guardGate();
};

#endif