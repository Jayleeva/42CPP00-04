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
	std::cout << " ClapTrap " << a.getName() << " has " << a.getHit() << " hit points and " << a.getEnergy() << " energy points, while";
	std::cout << " ClapTrap " << b.getName() << " has " << b.getHit() << " hit points and " << b.getEnergy() << " energy points, and";
	std::cout << " ClapTrap " << c.getName() << " has " << c.getHit() << " hit points and " << c.getEnergy() << " energy points." << std::endl;

	if (a.getHit() == b.getHit() && b.getHit() == c.getHit())
	{
		if (a.getEnergy() == b.getEnergy() && b.getEnergy() == c.getEnergy())
				std::cout << "...It's a perfect draw..." << std::endl;
		else if (a.getEnergy() > b.getEnergy() && a.getEnergy() > c.getEnergy())
			std::cout << "It looks like a draw, but ClapTrap " << a.getName() << " has more energy left than its adversaries and WINS!" << std::endl;
		else if (b.getEnergy() > a.getEnergy() && b.getEnergy() > c.getEnergy())
			std::cout << "It looks like a draw, but ClapTrap " << b.getName() << " has more energy left than its adversaries and WINS!" << std::endl;
		else if (c.getEnergy() > a.getEnergy() && c.getEnergy() > b.getEnergy())
			std::cout << "It looks like a draw, but ClapTrap " << c.getName() << " has more energy left than its adversaries and WINS!" << std::endl;
		else
			std::cout << "Meh, no winner this time!" << std::endl;
	}
	else
	{
		if (a.getHit() > b.getHit() && a.getHit() > c.getHit())
		{
			std::cout << "AND IT'S A WIN FOR CLAPTRAP " << a.getName() << "! What a fight!" << std::endl;
		}
		else if (a.getHit() > b.getHit() && a.getHit() <= c.getHit())
		{
			if (a.getEnergy() == c.getEnergy())
				std::cout << "Aaaaand it's a draw between ClapTrap " << a.getName() << " and ClapTrap " << c.getName() << "." << std::endl;
			if (a.getEnergy() > c.getEnergy())
				std::cout << "It looks like a draw, but ClapTrap " << a.getName() << " has more energy left than its stronger adversary and WINS!" << std::endl;
		} 
		else if (a.getHit() > c.getHit() && a.getHit() <= b.getHit())
		{
			if (a.getEnergy() == b.getEnergy())
				std::cout << "Aaaaand it's a draw between ClapTrap " << a.getName() << " and ClapTrap " << b.getName() << "." << std::endl;
			if (a.getEnergy() > b.getEnergy())
				std::cout << "It looks like a draw, but ClapTrap " << a.getName() << " has more energy left than its stronger adversary and WINS!" << std::endl;
		}
		if (b.getHit() > a.getHit() && b.getHit() > c.getHit())
		{
			std::cout << "AND IT'S A WIN FOR CLAPTRAP " << b.getName() << "! What a fight!" << std::endl;
		}
		else if (b.getHit() > a.getHit() && b.getHit() <= c.getHit())
		{
			if (b.getEnergy() == c.getEnergy())
				std::cout << "Aaaaand it's a draw between ClapTrap " << b.getName() << " and ClapTrap " << c.getName() << "." << std::endl;
			if (b.getEnergy() > c.getEnergy())
				std::cout << "It looks like a draw, but ClapTrap " << b.getName() << " has more energy left than its stronger adversary and WINS!" << std::endl;
		}
		else if (b.getHit() > c.getHit() && b.getHit() <= a.getHit())
		{
			if (b.getEnergy() == a.getEnergy())
				std::cout << "Aaaaand it's a draw between ClapTrap " << b.getName() << " and ClapTrap " << a.getName() << "." << std::endl;
			if (b.getEnergy() > a.getEnergy())
				std::cout << "It looks like a draw, but ClapTrap " << b.getName() << " has more energy left than its stronger adversary and WINS!" << std::endl;
		}
		if (c.getHit() > a.getHit() && c.getHit() > b.getHit())
		{
			std::cout << "AND IT'S A WIN FOR CLAPTRAP " << c.getName() << "! What a fight!" << std::endl;
		}
		else if (c.getHit() > a.getHit() && c.getHit() <= b.getHit())
		{
			if (c.getEnergy() == b.getEnergy())
				std::cout << "Aaaaand it's a draw between ClapTrap " << c.getName() << " and ClapTrap " << b.getName() << "." << std::endl;
			if (c.getEnergy() > b.getEnergy())
				std::cout << "It looks like a draw, but ClapTrap " << c.getName() << " has more energy left than its stronger adversary and WINS!" << std::endl;
		}
		else if (c.getHit() > b.getHit() && c.getHit() <= a.getHit())
		{
			if (c.getEnergy() == a.getEnergy())
				std::cout << "Aaaaand it's a draw between ClapTrap " << c.getName() << " and ClapTrap " << a.getName() << "." << std::endl;
			if (c.getEnergy() > a.getEnergy())
				std::cout << "It looks like a draw, but ClapTrap " << c.getName() << " has more energy left than its stronger adversary and WINS!" << std::endl;
		}
	}
 }