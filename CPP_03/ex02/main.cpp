#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	c("Frag");
	ClapTrap	a("Clap");
	ScavTrap	b("Scav");

	c.highFivesGuys();
	a.attack(c.getName());
	c.takeDamage(a.getDamage());
	b.guardGate();
	b.attack(a.getName());
	a.takeDamage(b.getDamage());
	a.beRepaired(5);
	c.highFivesGuys();
	b.attack(c.getName());
	c.takeDamage(b.getDamage());
	c.beRepaired(5);
	c.attack(b.getName());
	b.takeDamage(c.getDamage());
	b.beRepaired(5);
	std::cout << "***\nAt the end of this terrible fight,";
	std::cout << " ClapTrap " << YELLOW << a.getName() << DEFAULT << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while";
	std::cout << " ClapTrap " << YELLOW << b.getName() << DEFAULT << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points, and";
	std::cout << " ClapTrap " << YELLOW << c.getName() << DEFAULT << " has " << c.getHit() << " hit points and " << c.getEnergy() << " energy points.\n***" << std::endl;
}