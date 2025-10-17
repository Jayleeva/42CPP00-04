#include "Harl.hpp"

void complain( std::string level );

int	main()
{
	std::string	level;
	Harl	h;

	while (1)
	{
		std::cout << "Enter level (DEBUG, INFO, WARNING, ERROR), or EXIT: " << std::endl;
		h.safeGetline(level);
		if (level.empty())
			continue ;
		if (level == "EXIT")
			return (0);
		h.complain(level);
	}
	return (0);
}