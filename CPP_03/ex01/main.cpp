#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void )
{
	ClapTrap	a("Clapper");
	ScavTrap	b("Trapper");

	a.attack("the Gate Keeper!");
	b.takeDamage(b.getDamage());
	b.beRepaired(0);
	b.attack(a.getName());
	a.takeDamage(b.getDamage());
	std::cout << "***\nAt the end of this terrible fight, ClapTrap " << a.getName() << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while ClapTrap " << b.getName() << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points." << std::endl;
	if (a.getHit() == b.getHit() && a.getEnergy() == b.getEnergy())
		std::cout << "...It's a perfect draw..." << std::endl;
	else if (a.getHit() == b.getHit() && a.getEnergy() > b.getEnergy())
		std::cout << "It's a straw, but ClapTrap " << a.getName() << " seems to have more energy left in it!" << std::endl;
	else if (a.getHit() == b.getHit() && a.getEnergy() < b.getEnergy())
		std::cout << "It's a straw, but ClapTrap " << b.getName() << " seems to have more energy left in it!" << std::endl;
	else if (a.getHit() > b.getHit())
		std::cout << "AND IT'S A WIN FOR CLAPTRAP " << a.getName() << "! What a fight!" << std::endl;
	else if (a.getHit() < b.getHit())
		std::cout << "AND IT'S A WIN FOR CLAPTRAP " << b.getName() << "! What a fight!" << std::endl;
 }