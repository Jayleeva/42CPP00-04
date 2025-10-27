#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	a("Clapper");
	ClapTrap	b("Trapper");

	a.attack("the air apparently");
	b.takeDamage(b.getDamage());
	b.beRepaired(0);
	std::cout << "***\nAt the end of this terrible fight,";
	std::cout << " ClapTrap " << YELLOW << a.getName() << DEFAULT << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while";
	std::cout << " ClapTrap " << YELLOW << b.getName() << DEFAULT << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points.\n***" << std::endl;
 }