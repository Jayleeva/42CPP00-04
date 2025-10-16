#include "phonebook.hpp"
#include "contact.hpp"

Contact::Contact()
{
    std::cout << YELLOW << "[DEBUG] : contact created" << DEFAULT << std::endl;
}
Contact::~Contact()
{
	std::cout << YELLOW << "[DEBUG] : contact destroyed" << DEFAULT << std::endl;
}

void	Contact::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}
void	Contact::setLastName(std::string lastName)
{
    this->lastName = lastName;
}
void	Contact::setNickName(std::string nickName)
{
    this->nickName = nickName;
}
void	Contact::setPhoneNumber(std::string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void	Contact::setDarkestSecret(std::string darkestSecret)
{
    this->darkestSecret = darkestSecret;
}

std::string const    Contact::getFirstName() const
{
    return (this->firstName);
}

std::string const    Contact::getLastName() const
{
    return (this->lastName);
}

std::string const    Contact::getNickName() const
{
    return (this->nickName);
}

std::string const    Contact::getPhoneNumber() const
{
    return (this->phoneNumber);
}

std::string const    Contact::getDarkestSecret() const
{
    return (this->darkestSecret);
}