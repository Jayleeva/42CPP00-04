#include "Zombie.hpp"

//Crée un premier zombie et l'annonce, puis le supprime, puis demande à l'utilisateur un nom pour créer un deuxième zombie.
//La première création se fait sur la heap car utilise le mot-clé new, et la deuxième sur la stack car se contente du constructeur.
//Comme la 1ère était faite sur la heap, il faut la déallouer avec le mot-clé delete, alors que ce n'est pas nécessaire pour la 2ème.
int	main()
{
	std::string	name;
	Zombie	*z;
	
	z = newZombie("Zach");
	z->announce();
	delete z;
	std::cout << "> Enter zombie name: " << std::endl;
	std::cin >> name;
	randomChump(name);
	return (0);
}
