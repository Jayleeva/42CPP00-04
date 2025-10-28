#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << YELLOW << "[CAT]: Default constructor called" << DEFAULT << std::endl;
}

Cat::Cat(const Cat &original) : Animal("Cat")
{
	std::cout << YELLOW << "[CAT]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

Cat::~Cat()
{
	std::cout << YELLOW << "[CAT]: Destructor called" << DEFAULT << std::endl;
}

Cat &Cat::operator=(const Cat &original)
{
    if (this != &original)
	{
		this->type = original.type;
    }
    std::cout << YELLOW << "[CAT]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "MEOW MEOW" << std::endl;
}