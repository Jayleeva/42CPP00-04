#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// Derived class
class FragTrap: public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &original);
		~FragTrap();
		FragTrap &operator=(const FragTrap &original);

		void	highFivesGuys();
};

#endif