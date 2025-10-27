#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// Classe dérivée. Pour éviter l'ambiguité, on ajoute "virtual" après "public". 
class FragTrap: public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &original);
		~FragTrap();
		FragTrap &operator=(const FragTrap &original); // pour que diamond prenne bien les valeurs des classes enfants au lieu de parent, pas compris comment though

		void	highFivesGuys();

	private:
		std::string	name;
};

#endif