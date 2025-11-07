#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::safeGetline(std::string &input)
{
	getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
}

//On crée un premier array contenant les différents niveaux disponibles. Donc un array de string constantes.
//On crée ensute un autre array contenant des références aux fonctions correspondantes aux niveaux disponibles. Donc un array de pointeurs sur fonctions, qui ne reçoivent pas d'argument (void). Ces fonctions appartiennet à la classe Harl (Harl::)
//On parcourt notre premier array jusqu'à trouver le niveau reçu en argument, ce qui nous donne l'index à utiliser ensuite.
//On appelle la fonction de notre deuxième array grâce à l'index, sans lui passer d'argument puisqu'aucun n'est attendu. On déréférence l'array pour que this puisse accéder à la fonction
void Harl::complain( std::string level )
{
	std::string const	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void				(Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while (i < 4)
	{
		if (level == levels[i])
		{
			(this->*funcPtr[i])();
			break ;
		}
		i ++;
	}
	if (i == 4)
	{
		std::cout << GRAY << "[OTHER]   ";
		std::cout << "*muted*" << DEFAULT << std::endl;
	}
}

void Harl::debug( void )
{
	std::cout << MAGENTA << "[DEBUG]   ";
	std::cout << "Is this working...? I would have done it differently." << DEFAULT << std::endl;
}

void Harl::info( void )
{
	std::cout << BLUE << "[INFO]   ";
	std::cout << "*I* am the ONLY one who knows how to properly code in C++." << DEFAULT << std::endl;
}

void Harl::warning( void )
{
	std::cout << YELLOW << "WARNING]   ";
	std::cout << "If you don't do it my way, it's just not gonna work!" << DEFAULT << std::endl;
}

void Harl::error( void )
{
	std::cout << RED << "[ERROR]   ";
	std::cout << "I TOLD YOU SO!!!" << DEFAULT << std::endl;
}