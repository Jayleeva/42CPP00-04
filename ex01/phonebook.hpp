#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>

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

#endif