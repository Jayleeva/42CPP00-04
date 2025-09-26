#include "phonebook.hpp"
#include "ft_itoa.cpp"

int	get_len(string input)
{
	int	i = 0;

	while (input[i])
		i ++;
	return (i);
}

int	main()
{
	PhoneBook	book;
	int			i = 0;
	string		cmd;
	int			index;

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
			cin >> index;
			if (isdigit(index))
				cout << "THIS IS A DIGIT" << endl;
			if ((index < 0 || index > 7)) // || !isdigit(index))
			{
				/*if (!isdigit(index))
				{
					cin.clear();
					//string s = to_string(index); // marche pas, transforme tout en un 0, donc 1 char.
					//int l = get_len(index);
					//cout << l << endl;
					cin.ignore(2);
				}*/
				cout << "> Invalid index." << endl;
			}
			else
			{
				cout << "index | first name | last name | nickname" << endl;
				cout << index << " | " << book.contactList[index].firstName << " | " << book.contactList[index].lastName << " | " << book.contactList[index].nickname << endl;
			}
		}
		else if (cmd == "EXIT")
			break;
		/*else
			cout << "Invalid command." << endl;*/
	}
	return (0);
}