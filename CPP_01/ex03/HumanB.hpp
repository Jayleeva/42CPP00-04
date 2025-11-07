#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

//on utilise un pointeur pour la weapon d'ici parce qu'elle n'est pas assignée dans le constructeur et ne le sera possiblement jamais (aucune obligation d'appeler la fonction set), or une référence DOIT être initialisée, alors qu'un pointeur peut être vide.
//dans le setter, comme on reçoit un instance d'une autre classe, c'est forcément une référence?
class	HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void	attack();
		void	setWeapon(Weapon &w);
	private:
		std::string	name;
		Weapon	*w;
};

#endif