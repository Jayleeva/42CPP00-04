#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << YELLOW << "[WRONG ANIMAL]: Default constructor called" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
    this->type = type;
	std::cout << YELLOW << "[WRONG ANIMAL]: String constructor called" << DEFAULT << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original)
{
	std::cout << YELLOW << "[WRONG ANIMAL]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << YELLOW << "[WRONG ANIMAL]: Destructor called" << DEFAULT << std::endl;
}

WrongAnimal const &WrongAnimal::operator=(WrongAnimal const &original)
{
    if (this != &original)
	{
		this->type = original.type;
    }
    std::cout << YELLOW << "[WRONG ANIMAL]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WRONG [DEFAULT SOUND]" << std::endl;
}