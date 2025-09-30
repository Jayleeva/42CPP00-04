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
	string		tab[6] = {"index", "first name", "last name", "nickname", "phone number", "darkest secret"};

	while (1)
	{
		cout << "> Enter command (ADD, SEARCH, EXIT) :" << endl;
		cin >> cmd;
		if (cmd == "ADD")
		{
			if (i == 8)
				i = 0;
			cout << "> Enter first name :" << endl;
			cin >> book.contactList[i].firstName;
			cout << "> Enter last name :" << endl;
			cin >> book.contactList[i].lastName;
			cout << "> Enter nickname :" << endl;
			cin >> book.contactList[i].nickname;
			cout << "> Enter phone number :" << endl;
			cin >> book.contactList[i].phoneNumber;
			cout << "> Enter darkest secret :" << endl;
			cin >> book.contactList[i].darkestSecret;
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
					i = 0;
					while (tab[i])
					{
						if (strlen(tab[i]) > 10)
							
						cout << setw(10) << right << "index|";
						cout << setw(10) << right << "first name|";
						cout << setw(10) << right << "last name|";
						cout << setw(10) << right << "nickname|";
						cout << setw(10) << right << "phone number|";
						cout << setw(10) << right << "darkest secret" << endl;
						i ++;
					}
					cout << setw(10) << right << index << "|";
					cout << setw(10) << right << book.contactList[index].firstName << "|";
					cout << setw(10) << right << book.contactList[index].lastName << "|";
					cout << setw(10) << right << book.contactList[index].nickname << "|";
					cout << setw(10) << right << book.contactList[index].phoneNumber << "|";
					cout << setw(10) << right << book.contactList[index].darkestSecret << endl;
				}
			}
		}
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}