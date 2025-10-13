#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

using namespace std;

class	HumanB
{
	public:
		HumanB(string name);
		~HumanB(void);
		void	attack();
		void	setWeapon(Weapon &w);
	private:
		string	name;
		Weapon	*w;
};

#endif