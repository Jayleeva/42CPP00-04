#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iomanip>

int main( void )
{
	ClapTrap	a("Clap");
	ScavTrap	b("Scav");
	FragTrap	c("Frag");

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
	std::cout << std::setw(15) << std::right << c.getEnergy() << "|\n***" << std::endl;
}