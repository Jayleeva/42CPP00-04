#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

using namespace std;

class	HumanA
{
	public:
		HumanA(string name, Weapon &w);
		~HumanA(void);
		void	attack();
	private:
		string	name;
		Weapon	w;
};

#endif
