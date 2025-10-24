//#ifndef DIAMONDTRAP_HPP
//# define DIAMONDTRAP_HPP

#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

// Classe dérivée de deux classes elles-mêmes dérivées d'une autre
class DiamondTrap: public FragTrap, public ScavTrap
{
	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &original);
		~DiamondTrap();

		DiamondTrap &operator=(DiamondTrap const &original); // pour que diamond prenne bien les valeurs des classes enfants au lieu de parent? ne semble pas marcher...

		void	whoAmI();

	private:
		std::string	name;
};

//#endif