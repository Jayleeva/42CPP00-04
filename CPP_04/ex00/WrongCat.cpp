#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << "[WRONG CAT]: Default constructor called" << DEFAULT << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal("WrongCat")
{
	std::cout << YELLOW << "[WRONG CAT]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

WrongCat::~WrongCat()
{
	std::cout << YELLOW << "[WRONG CAT]: Destructor called" << DEFAULT << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
    if (this != &original)
	{
		this->type = original.type;
    }
    std::cout << YELLOW << "[WRONG CAT]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}