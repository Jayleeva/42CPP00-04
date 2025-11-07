#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

//On utilise une référence à weapon afin qu'elle ne puisse pas être réassignée (dans la déclaration ET dans le constructeur). Le code pourrait fonctionner sans cette protection.
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
