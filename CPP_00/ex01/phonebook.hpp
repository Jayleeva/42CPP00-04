#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>

using namespace std;

class Contact
{
	public:
		Contact()
		{}
		string	firstName;
		string	lastName;
		string	nickname;
		string	phoneNumber;
		string	darkestSecret;
};

class PhoneBook
{
	public:
		PhoneBook()
		{}
		~PhoneBook()
		{
			cout << "phonebook destructor" << endl;
		}
		Contact	contactList[8];
};

int	ft_isnum(string input);
int	ft_atoi(string str);

#endif