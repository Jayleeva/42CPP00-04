#include "Harl.hpp"

void complain( int i );


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
			cout << GRAY << "[OTHER]   ";
			cout << "*muted*" << DEFAULT << endl;
			break;
	}
}

int	ft_translate(char *level)
{
	string const levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

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
	i = ft_translate(argv[1]);
	ft_switch(i);
	return (0);
}