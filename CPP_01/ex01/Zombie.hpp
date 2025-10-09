#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

class Zombie
{
	public:
		Zombie(std::string);
		~Zombie(void);
		void	announce(void);
	private:
		string	name;
};

Zombie	*zombieHorde( int N, std::string name );
Zombie	*newZombie( std::string name );

#endif