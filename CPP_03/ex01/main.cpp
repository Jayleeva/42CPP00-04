#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	a("Clapper");
	ScavTrap	b("Trapper");

	a.attack(b.getName());
	b.takeDamage(a.getDamage());
	b.guardGate();
	b.attack(a.getName());
	a.takeDamage(b.getDamage());
	a.beRepaired(5);
	std::cout << "***\nAt the end of this terrible fight,";
	std::cout << " ClapTrap " << a.getName() << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while";
	std::cout << " ClapTrap " << b.getName() << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points." << std::endl;
	if (a.getHit() == b.getHit())
	{
		if (a.getEnergy() == b.getEnergy())
				std::cout << "...It's a perfect draw..." << std::endl;
		else if (a.getEnergy() > b.getEnergy())
			std::cout << "It looks like a draw, but ClapTrap " << a.getName() << " has more energy left than its adversary and WINS!" << std::endl;
		else if (a.getEnergy() < b.getEnergy())
			std::cout << "It looks like a draw, but ClapTrap " << b.getName() << " has more energy left than its adversary and WINS!" << std::endl;
	} 
	else if (a.getHit() > b.getHit())
		std::cout << "AND IT'S A WIN FOR CLAPTRAP " << a.getName() << "! What a fight!" << std::endl;
	else if (a.getHit() < b.getHit())
		std::cout << "AND IT'S A WIN FOR CLAPTRAP " << b.getName() << "! What a fight!" << std::endl;
 }