#include "Harl.hpp"

void complain( int i );

//Pour respecter le sujet et imprimer tous les niveaux au-dessus de celui reçu en argument, on ne peut pas mettre de break après chaque niveau, uniquement après le dernier et le default.
//Pour les autres, on précise __attribute__ ((fallthrough)), ce qui permet d'exécuter les cas suivants.
//On prévoit un cas par défaut si notre index ne correspond à rien d'attendu.
void ft_switch( int i )
{
	Harl	h;

	switch (i)
	{
		case 0:
			h.complain("DEBUG");
			__attribute__ ((fallthrough));
		case 1:
			h.complain("INFO");
			__attribute__ ((fallthrough));
		case 2:
			h.complain("WARNING");
			__attribute__ ((fallthrough));
		case 3:
			h.complain("ERROR");
			break;
		default:
			std::cout << GRAY << "[OTHER]   ";
			std::cout << "*muted*" << DEFAULT << std::endl;
			break;
	}
}

//on transforme l'input en index pour pouvoir travailler avec le switch case ensuite
int	ft_to_index(char *level)
{
	std::string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
			break ;
		i ++;
	}
	return (i);
}


int	main(int argc, char **argv)
{
	Harl	h;
	int		i;

	if (argc < 2)
		return (1);
	i = ft_to_index(argv[1]);
	ft_switch(i);
	return (0);
}