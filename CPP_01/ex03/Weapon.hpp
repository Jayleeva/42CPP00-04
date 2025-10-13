#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

using namespace std;

class	Weapon
{
	public:
		Weapon();
		Weapon(string type);
		~Weapon(void);
		string const	&getType();
		void			setType(string type);
	private:
		string	type;
};

#endif