#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
#include <iostream>
#include <iomanip>
#include <stack>
#include "Zombie.cpp"
#include "newZombie.cpp"
#include "randomChump.cpp"
#include "main.cpp"

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

#endif