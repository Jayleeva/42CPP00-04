#include "phonebook.hpp"
#include "utils.cpp"

string	truncate(string str)
{
	int	i;

	i = str.length();
	if (i > 10)
	{
		str[9] = '.';
		str.erase(10, i);
		return (str);
	}
	else
		return (str);
}

int	main()
{
	PhoneBook	book;
	int			i = 0;
	int			j;
	int			tmp;
	string		cmd;
	int			index;
	string		input;
	//string		tab[6] = {"index", "first name", "last name", "nickname", "phone number", "darkest secret"};

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
			cout << "> Welcome, " << book.contactList[i].firstName << " " << book.contactList[i].lastName << " !" << endl;
			i ++;
		}
		else if (cmd == "SEARCH")
		{
			cout << setw(10) << right << truncate("index") << "|";
			cout << setw(10) << right << truncate("first name") << "|";
			cout << setw(10) << right << truncate("last name") << "|";
			cout << setw(10) << right << truncate("nickname") << "|";
			cout << setw(10) << right << truncate("phone number") << "|";
			cout << setw(10) << right << truncate("darkest secret") << endl;
			j = 0;
			while (j < i)
			{
				cout << setw(10) << right << j << "|";
				cout << setw(10) << right << truncate(book.contactList[j].firstName) << "|";
				cout << setw(10) << right << truncate(book.contactList[j].lastName) << "|";
				cout << setw(10) << right << truncate(book.contactList[j].nickname) << "|";
				cout << setw(10) << right << truncate(book.contactList[j].phoneNumber) << "|";
				cout << setw(10) << right << truncate(book.contactList[j].darkestSecret) << endl;
				j ++;
			}
			if (i < 2)
				tmp = 0;
			else
				tmp = i -1;
			cout << "> Enter contact index (0 to " << tmp << "):" << endl;
			cin >> input;
			if (!ft_isnum(input))
			{
				cin.clear();
				cin.ignore(input.length());
				cout << "> Invalid index." << endl;
			}
			else
			{
				index = ft_atoi(input);
				if (index < 0 || index > 7)
					cout << "> Invalid index." << endl;
				else
				{							
					cout << book.contactList[index].firstName << endl;
					cout << book.contactList[index].lastName << endl;
					cout << book.contactList[index].nickname << endl;
					cout << book.contactList[index].phoneNumber << endl;
					cout << book.contactList[index].darkestSecret << endl;
				}
			}
		}
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}