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

std::string	PhoneBook::addContactUtils(std::string in)
{
	std::string	input;

	while (input.empty())
	{
		std::cout << in << std::endl;
		safeGetline(input);
	}
	return (input);
}

void    PhoneBook::addContact(int i)
{
    std::string  input;

	input = addContactUtils("> Enter first name :");
	this->contactList[i].setFirstName(input);
	input = addContactUtils("> Enter last name :");
	this->contactList[i].setLastName(input);
	input = addContactUtils("> Enter nickname :");
	this->contactList[i].setNickName(input);
	input = addContactUtils("> Enter phone number :");
	this->contactList[i].setPhoneNumber(input);
	input = addContactUtils("> Enter darkest secret :");
	this->contactList[i].setDarkestSecret(input);

	std::cout << YELLOW << "> Interesting secret, " << this->contactList[i].getFirstName() << " " << this->contactList[i].getLastName() << "..." << DEFAULT << std::endl;
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
	{
        return ;
	}
	while (input.empty())
	{
		std::cout << "> Enter contact index (0 to " << n - 1 << "):" << std::endl;
		safeGetline(input);
	}
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
		std::cout << YELLOW << "> Invalid index." << DEFAULT << std::endl;
	}
	else
	{
		if ((input[0] < '0' || input[0] > n - 1 + '0') || input[1])
			std::cout << YELLOW << "> Invalid index." << DEFAULT << std::endl;
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
}