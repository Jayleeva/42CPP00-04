#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <iomanip>
#include <stack>

using namespace std;

class Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	giveName(std::string);
		void	announce(void);
	private:
		string	name;
};

Zombie	*zombieHorde( int N, std::string name );

#endif