#include "DiamondTrap.hpp"
#include <iomanip>

int main( void )
{
	ClapTrap	a("Clap");
	ScavTrap	b("Scav");
	FragTrap	c("Frag");
	DiamondTrap	d("Diams");

	d.highFivesGuys();
	d.guardGate();
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
	std::cout << "***\nLet's look at the results of this terrible fight: \n";
	std::cout << std::setw(15) << std::right << "Name" << "|";
	std::cout << std::setw(15) << std::right << "Hit points" << "|";
	std::cout << std::setw(15) << std::right << "Energy points" << "|";
	std::cout << std::setw(15) << std::right << "\n---------------" << "|";
	std::cout << std::setw(15) << std::right << "---------------" << "|";
	std::cout << std::setw(15) << std::right << "---------------" << "|" << std::endl;
	std::cout << std::setw(15) << std::right << a.getName() << "|";
	std::cout << std::setw(15) << std::right << a.getHit() << "|";
	std::cout << std::setw(15) << std::right << a.getEnergy() << "|" << std::endl;
	std::cout << std::setw(15) << std::right << b.getName() << "|";
	std::cout << std::setw(15) << std::right << b.getHit() << "|";
	std::cout << std::setw(15) << std::right << b.getEnergy() << "|" << std::endl;
	std::cout << std::setw(15) << std::right << c.getName() << "|";
	std::cout << std::setw(15) << std::right << c.getHit() << "|";
	std::cout << std::setw(15) << std::right << c.getEnergy() << "|" << std::endl;
	std::cout << std::setw(15) << std::right << d.getName() << "|";
	std::cout << std::setw(15) << std::right << d.getHit() << "|";
	std::cout << std::setw(15) << std::right << d.getEnergy() << "|\n***" << std::endl;
}