#include "Harl.hpp"

void complain( std::string level );

int	main()
{
	string	level;
	Harl	h;

	while (1)
	{
		cout << "Enter level (DEBUG, INFO, WARNING, ERROR), or EXIT: " << endl;
		cin >> level;
		if (level == "EXIT")
			return (0);
		h.complain(level);
	}
	return (0);
}