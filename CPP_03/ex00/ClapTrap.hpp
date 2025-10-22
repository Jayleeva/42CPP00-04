#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &original);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string const	getName() const;
		int					getHit() const; 
		int					getEnergy() const;
		int					getDamage() const;

		void				setName(std::string name);
		void				setHit(int hit);
		void				setEnergy(int energy);
		void				setDamage(int damage);

	private:
		std::string	name;
		int			hit = 10;
		int			energy = 10;
		int			damage = 0;
};

#endif