#include "phonebook.hpp"

int	is_in_set(string set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

int	atoi_utils(string str, int i)
{
	int	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i ++;
	}
	return (result);
}

int	ft_atoi(string str)
{
	int		i;
	int		n;
	int		result;
	string	set = "+-0123456789";

	i = 0;
	n = 1;
	while ((str[i] >= 9 && str[i] <= 13)
		|| str[i] == ' ')
		i ++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (!is_in_set(set, str[i +1]))
			return (0);
		if (str[i] == '-')
			n = n * -1;
		i ++;
	}
	result = atoi_utils(str, i);
	return (result * n);
}