#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::complain( std::string level )
{
	std::string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*funcPtr[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

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
	std::cout << "*I* am the ONLY one who knows how to properly code in c++." << DEFAULT << std::endl;
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