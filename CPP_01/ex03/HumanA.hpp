#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

using namespace std;

//On construit en passant une référence à l'arme.
//Donc, l'attribut weapon est une référence.
class	HumanA
{
	public:
		HumanA(string name, Weapon &w);
		~HumanA(void);
		void	attack();
	private:
		string	name;
		Weapon	&w;
};

#endif
