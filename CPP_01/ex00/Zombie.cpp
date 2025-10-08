#include "Zombie.hpp"
using namespace std;

Zombie::Zombie( std::string name )
{
	this->name = name;
}
	
Zombie::~Zombie()
{
	cout << this->name << "has been destroyed." << endl;
}

void Zombie::announce( void )
{
	cout << this->name << ": BraiiiiiiinnnzzzZ..." << endl;
}

