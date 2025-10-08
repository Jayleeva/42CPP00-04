#include "phonebook.hpp"

int	ft_isnum(string input)
{
	int	i = 0;

	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			return (0);
		i ++;
	}
	return (1);
}

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


static int	get_nelem(int n)
{
	int	sign;
	int	nelem;

	nelem = 1;
	if (n < 0)
	{
		sign = 1;
		if (n == -2147483648)
			n ++;
		n = n * -1;
	}
	else
		sign = 0;
	while (n > 9)
	{
		nelem ++;
		n = n / 10;
	}
	return (nelem + sign);
}

static int	get_temp(int n)
{
	int	temp;

	temp = n;
	if (n < 0)
	{
		if (n == -2147483648)
			temp ++;
		temp = temp * -1;
	}
	return (temp);
}

string	ft_itoa(int n)
{
	int		nelem;
	int		i;
	int		temp;
	string	result;

	nelem = get_nelem(n);
	temp = get_temp(n);
	i = nelem -1;
	while (i > 0)
	{
		result[i] = (temp % 10) + '0';
		temp = temp / 10;
		i --;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = (temp % 10) + '0';
	if (n == -2147483648)
		result[nelem -1] = '8';
	result[nelem] = '\0';
	return (result);
}