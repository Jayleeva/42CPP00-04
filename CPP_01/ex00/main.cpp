#include "Zombie.hpp"

using namespace std;

int	main(void)
{
	string	name;
	Zombie	*z;
	
	z = newZombie("Zach");
	z->announce();
	delete z;
	cout << "> Enter zombie name: " << endl;
	cin >> name;
	randomChump("name");
	
	return (0);
}