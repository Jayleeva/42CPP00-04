#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "phonebook.hpp"

# define YELLOW "\001\033[1;93m\002"
# define DEFAULT "\001\033[0;39m\002"

class Contact
{
	public:
		Contact();
		~Contact();
		void	setFirstName(std::string firstName);
		void	setLastName(std::string lastName);
		void	setNickName(std::string nickName);
		void	setPhoneNumber(std::string phoneNumber);
		void	setDarkestSecret(std::string darkestSecret);

        std::string const    getFirstName() const;
        std::string const    getLastName() const;
        std::string const    getNickName() const;
        std::string const    getPhoneNumber() const;
        std::string const    getDarkestSecret() const;

	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
};

#endif