#include "Zombie.hpp"

//Crée un premier zombie et l'annonce, puis le supprime, puis demande à l'utilisateur un nom pour créer un deuxième zombie.
//la première création se fait sur la (heap/stack?) et la deuxième sur la (stack/heap?)
int	main()
{
	string	name;
	Zombie	*z;
	
	z = newZombie("Zach");
	z->announce();
	delete z;
	cout << "> Enter zombie name: " << endl;
	cin >> name;
	randomChump(name);
	return (0);
}
