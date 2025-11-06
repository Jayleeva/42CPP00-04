#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

//On construit en passant une référence à l'arme (pourquoi?)
//Donc, l'attribut weapon est une référence.
class	HumanA
{
	public:
		HumanA(std::string name, Weapon &w);
		~HumanA(void);
		void	attack();
	private:
		std::string	name;
		Weapon	&w;
};

#endif
