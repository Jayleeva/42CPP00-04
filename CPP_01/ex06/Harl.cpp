#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void Harl::complain( std::string level )
{
	string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
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
		cout << GRAY << "[OTHER]   ";
		cout << "*muted*" << DEFAULT << endl;
	}
}

void Harl::debug( void )
{
	cout << MAGENTA << "[DEBUG]   ";
	cout << "Is this working...? I would have done it differently." << DEFAULT << endl;
}

void Harl::info( void )
{
	cout << BLUE << "[INFO]   ";
	cout << "*I* am the ONLY one who knows how to properly code in c++." << DEFAULT << endl;
}

void Harl::warning( void )
{
	cout << YELLOW << "WARNING]   ";
	cout << "If you don't do it my way, it's just not gonna work!" << DEFAULT << endl;
}

void Harl::error( void )
{
	cout << RED << "[ERROR]   ";
	cout << "I TOLD YOU SO!!!" << DEFAULT << endl;
}