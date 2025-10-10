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
		const string	&getType();
		void			setType(string type);
	private:
		string	type;
};

#endif