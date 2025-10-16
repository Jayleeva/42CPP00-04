#include "phonebook.hpp"
#include "contact.hpp"

PhoneBook::PhoneBook()
{}

PhoneBook::~PhoneBook()
{}

void	PhoneBook::safeGetline(std::string &input)
{
	getline(std::cin, input);
	if (std::cin.eof())
		exit(0);
}

void	PhoneBook::setMaxContacts(int maxC)
{
	this->max_contacts = maxC;
}
int		PhoneBook::getMaxContacts() const
{
	return (this->max_contacts);
}

void    PhoneBook::addContact(int i)
{
    std::string  input;

	std::cout << "> Enter first name :" << std::endl;
	this->safeGetline(input);
    this->contactList[i].setFirstName(input);
	std::cout << "> Enter last name :" << std::endl;
	safeGetline(input);
    this->contactList[i].setLastName(input);
	std::cout << "> Enter nickname :" << std::endl;
	safeGetline(input);
    this->contactList[i].setNickName(input);
	std::cout << "> Enter phone number :" << std::endl;
	safeGetline(input);
    this->contactList[i].setPhoneNumber(input);
	std::cout << "> Enter darkest secret (in \"\") :" << std::endl;
	safeGetline(input);
    this->contactList[i].setDarkestSecret(input);
	std::cout << "> Welcome, " << this->contactList[i].getFirstName() << " " << this->contactList[i].getLastName() << " !" << std::endl;
}

std::string	truncate(std::string str)
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

void    PhoneBook::searchContact(int n)
{
	std::string		input;
	int				index;
	int				j;
	int				k;

	std::cout << std::setw(10) << std::right << truncate("index") << "|";
	std::cout << std::setw(10) << std::right << truncate("first name") << "|";
	std::cout << std::setw(10) << std::right << truncate("last name") << "|";
	std::cout << std::setw(10) << std::right << truncate("nickname") << "|";
	std::cout << std::setw(10) << std::right << truncate("phone number") << "|";
	std::cout << std::setw(10) << std::right << truncate("darkest secret") << std::endl;

	j = 0;
	while (j < n)
	{
		std::cout << std::setw(10) << std::right << j << "|";
		std::cout << std::setw(10) << std::right << truncate(this->contactList[j].getFirstName()) << "|";
		std::cout << std::setw(10) << std::right << truncate(this->contactList[j].getLastName()) << "|";
		std::cout << std::setw(10) << std::right << truncate(this->contactList[j].getNickName()) << "|";
		std::cout << std::setw(10) << std::right << truncate(this->contactList[j].getPhoneNumber()) << "|";
		std::cout << std::setw(10) << std::right << truncate(this->contactList[j].getDarkestSecret()) << std::endl;
		j ++;
	}

    if (n == 0)
        return;
    std::cout << "> Enter contact index (0 to " << n - 1 << "):" << std::endl;
	std::cin >> input;
	k = 0;
	j = 0;
	while (input[j])
	{
		if (!isdigit(input[j]))
			k = 1;
		j ++;
	}
	if (k == 1)
	{
		std::cin.clear();
		std::cout << "> Invalid index." << std::endl;
	}
	else
	{
		if ((input[0] < '0' || input[0] > n - 1 + '0') || input[1])
			std::cout << "> Invalid index." << std::endl;
		else
		{					
			index = input[0] - '0';
			std::cout << this->contactList[index].getFirstName() << std::endl;
			std::cout << this->contactList[index].getLastName() << std::endl;
			std::cout << this->contactList[index].getNickName() << std::endl;
			std::cout << this->contactList[index].getPhoneNumber() << std::endl;
			std::cout << this->contactList[index].getDarkestSecret() << std::endl;
		}
	}
	std::cin.ignore(1);
}