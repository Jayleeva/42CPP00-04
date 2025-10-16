#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	addContact(int i);
		void    searchContact(int n);
		void	safeGetline(std::string &input);

		void	setMaxContacts(int maxC);
		int		getMaxContacts() const;

	private:
		int		max_contacts;
		Contact	contactList[8];
};

#endif