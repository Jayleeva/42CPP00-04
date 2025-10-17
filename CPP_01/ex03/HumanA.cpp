#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

//Construit l'instance en assignant directement la référence pour weapon après les deux points car une référence DOIT être initialisée.
//Assigne le nom de l'instance avec celui reçu en argument.
HumanA::HumanA(std::string name, Weapon &w): w(w)
{
	this->name = name;
}

//Déconstruit l'instance et imprime un message.
HumanA::~HumanA()
{
	std::cout << this->name << " has been destroyed." << std::endl;
}

//Imprime le message d'attaque en récupérant le nom de l'instance et son arme.
//Comme on utilise une référence pour l'arme, on appelle getType avec '.' et pas "->".
void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->w.getType() << std::endl;
}
