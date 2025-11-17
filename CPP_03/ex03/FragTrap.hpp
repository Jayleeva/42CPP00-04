#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// Classe dérivée. Pour éviter l'ambiguité du diamond problem, on ajoute "virtual" 
class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name_);
		FragTrap(const FragTrap &original);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &original); // pour que diamond prenne bien les valeurs des classes enfants au lieu de parent, pas compris comment though

		void	highFivesGuys();
};

#endif