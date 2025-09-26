#include "phonebook.hpp"
#include "ft_atoi.cpp"

int	get_len(string input)
{
	int	i = 0;

	while (input[i])
		i ++;
	return (i);
}

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

int	main()
{
	PhoneBook	book;
	int			i = 0;
	string		cmd;
	int			index;
	string		input;

	while (1)
	{
		cout << "> Enter command (ADD, SEARCH, EXIT) :" << endl;
		cin >> cmd;
		if (cmd == "ADD")
		{
			if (i == 2)
				i = 0;
			cout << "> Enter first name :" << endl;
			cin >> book.contactList[i].firstName;
			cout << "> Enter last name :" << endl;
			cin >> book.contactList[i].lastName;
			cout << "> Enter nickname :" << endl;
			cin >> book.contactList[i].nickname;
			cout << "> Hello, " << book.contactList[i].firstName << " " << book.contactList[i].lastName << " !" << endl;
			i ++;
		}
		else if (cmd == "SEARCH")
		{
			cout << "> Enter contact index (0 to 7):" << endl;
			cin >> input;
			if (!ft_isnum(input))
			{
				cin.clear();
				cin.ignore(get_len(input));
				cout << "> Invalid index." << endl;
			}
			else
			{
				index = ft_atoi(input);
				if (index < 0 || index > 7)
					cout << "> Invalid index." << endl;
				else
				{
					cout << "index | first name | last name | nickname" << endl;
					cout << index << " | " << book.contactList[index].firstName << " | " << book.contactList[index].lastName << " | " << book.contactList[index].nickname << endl;
				}
			}
		}
		else if (cmd == "EXIT")
			break;
		/*else
			cout << "Invalid command." << endl;*/
	}
	return (0);
}