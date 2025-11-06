#include "phonebook.hpp"
#include "contact.hpp"

int	main()
{
	PhoneBook	    book;
	std::string		cmd;
	int			    i = 0;
    int             n = 0;

    book.setMaxContacts(8);
	while (1)
	{
		std::cout << "> Enter command (ADD, SEARCH, EXIT) :" << std::endl;
		book.safeGetline(cmd);
        if (cmd.empty())
            continue ;
		else if (cmd == "ADD")
        {
            if (i == book.getMaxContacts())
            {
                std::cout << YELLOW << "[DEBUG] : WRITING OVER OLDEST CONTACT." << DEFAULT << std::endl;
                i = 0;
            }
            else if (n < book.getMaxContacts())
                n ++;
            book.addContact(i);
            i ++;
        }
		else if (cmd == "SEARCH")
            book.searchContact(n);
		else if (cmd == "EXIT")
			break;
	}
	return (0);
}