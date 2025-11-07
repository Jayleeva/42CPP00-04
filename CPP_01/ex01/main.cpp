#include "Zombie.hpp"

void	rename(Zombie *horde, int n)
{
    std::string  names[7] = {"Zachary", "Zavier", "Zénon", "Zélie", "Zelda", "Zara", "Zoé"};

    for (int i = 0; i < n; i++)
        horde[i].giveName(names[i]);
}

//Déclare un pointeur et lui assigne la fonction zombieHorde, puis fait s'annoncer chaque zombie pour s'assurer de bien avoir reçu le premier zombie en retour, déalloue la horde avec le mot-clé "delete" suivi de "[]".
int main()
{
	int		n = 7;
	Zombie	*z = zombieHorde(n, "Zachary");
	Zombie	*current;

	rename(z, n);	
	current = z;
	for (int i = 0; i < n; i++)
	{
		current->announce();
		current++;
	}
	delete [] z;
	return (0);
}