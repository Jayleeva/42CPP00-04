#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"


class	ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &original);
		~ClapTrap();
		ClapTrap	&operator=(const ClapTrap &original);

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
		int			hit;
		int			energy;
		int			damage;
};

#endif