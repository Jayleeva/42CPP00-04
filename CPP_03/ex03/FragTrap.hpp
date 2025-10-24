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

		void	highFivesGuys();

	private:
		std::string	name;
};

#endif