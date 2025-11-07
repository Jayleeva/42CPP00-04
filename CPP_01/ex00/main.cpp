#include "Zombie.hpp"

//Crée un premier zombie et l'annonce, puis le supprime, puis demande à l'utilisateur un nom pour créer un deuxième zombie.
//La première création se fait sur la heap car utilise le mot-clé new, et la deuxième sur la stack car se contente du constructeur.
//Comme la 1ère était faite sur la heap, il faut la déallouer avec le mot-clé delete, alors que ce n'est pas nécessaire pour la 2ème.
//On utilise un pointeur pour le premier car on déclare un objet (donc pointé/référencé) qu'on construit ensuite (via une fonction qui appelera elle un constructeur), or une référence doit être initialisée tout de suite.
//Le deuxième n'est pas retourné donc pas besoin de déclarer un pointeur.
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
