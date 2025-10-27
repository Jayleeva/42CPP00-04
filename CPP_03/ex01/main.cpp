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
	std::cout << " ClapTrap " << YELLOW << a.getName() << DEFAULT << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while";
	std::cout << " ClapTrap " << YELLOW << b.getName() << DEFAULT << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points.\n***" << std::endl;
}