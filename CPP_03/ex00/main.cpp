#include "ClapTrap.hpp"
#include <iomanip>

int main( void )
{
	ClapTrap			a("Clapper");
	ClapTrap			b("Trapper");
	const std::string	&target = "the air apparently";

	a.attack(target);
	b.takeDamage(b.getDamage());
	b.beRepaired(0);
	b.attack(target);
	a.takeDamage(a.getDamage());
	while (a.getEnergy())
		a.beRepaired(0);
	a.beRepaired(0);

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
	std::cout << std::setw(15) << std::right << b.getEnergy() << "|\n***" << std::endl;
 }