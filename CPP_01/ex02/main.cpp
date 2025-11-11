#include <iostream>
#include <iomanip>

int	main()
{
	std::string	str = "Hi this is brain";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << std::setw(35) << std::left << "address of string: " << &str << std::endl;
	std::cout << std::setw(35) << std::left << "address held by pointer: " << stringPTR << std::endl;
	std::cout << std::setw(35) << std::left << "address held by reference: " << &stringREF << std::endl;

	std::cout << std::setw(35) << std::left << "value of string: " << str << std::endl;
	std::cout << std::setw(35) << std::left << "value pointed to by pointer: " << *stringPTR << std::endl;
	std::cout << std::setw(35) << std::left << "value pointed to by reference: " << stringREF << std::endl;
	return (0);
}