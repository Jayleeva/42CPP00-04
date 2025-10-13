#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

using namespace std;

//Bien que l'arme soit assignée dans une fonction membre au lieu du constructeur, on utilise la même méthode, donc une référence.
//En revanche, puisque l'arme est assignée dans un second temps, l'attribut weapon est un pointeur.
//On pourrait utiliser une référence (avec les modifications appropriées) mais l'exercice veut nous faire utiliser un mix des deux.
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