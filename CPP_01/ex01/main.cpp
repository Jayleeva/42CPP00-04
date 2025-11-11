#include "Zombie.hpp"

//Déclare un pointeur et lui assigne la fonction zombieHorde, puis fait s'annoncer le pointeur pour s'assurer de bien avoir reçu le premier zombie en retour, déalloue la horde avec le mot-clé "delete" suivi de "[]".
int main()
{
	Zombie	*z = zombieHorde(7, "Zachary");
	z->announce(); 
	delete [] z;
	return (0);
}