#include "DiamondTrap.hpp"

int main( void )
{
	ClapTrap	a("Clap");
	ScavTrap	b("Scav");
	FragTrap	c("Frag");
	DiamondTrap	d("Diams");

	d.whoAmI();
	c.highFivesGuys();

	d.attack(c.getName());
	c.takeDamage(d.getDamage());

	a.attack(d.getName());
	d.takeDamage(a.getDamage());

	b.guardGate();
	b.attack(d.getName());
	d.takeDamage(b.getDamage());
	d.beRepaired(10);

	while (d.getHit() > 0)
	{
		c.attack(d.getName());
		d.takeDamage(c.getDamage());
	}
	d.whoAmI();
	std::cout << "***\nAt the end of this terrible fight,";
	std::cout << " ClapTrap " << YELLOW << a.getName() << DEFAULT << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while";
	std::cout << " ClapTrap " << YELLOW << b.getName() << DEFAULT << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points, and";
	std::cout << " ClapTrap " << YELLOW << c.getName() << DEFAULT << " has " << c.getHit() << " hit points and " << c.getEnergy() << " energy points, and";
	std::cout << " ClapTrap " << YELLOW << d.getName() << DEFAULT << " has " << d.getHit() << " hit points and " << d.getEnergy() << " energy points.\n***" << std::endl;
 }