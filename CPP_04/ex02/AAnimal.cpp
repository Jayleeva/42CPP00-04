#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << YELLOW << "[ANIMAL]: Default constructor called" << DEFAULT << std::endl;
}

AAnimal::AAnimal(std::string type)
{
    this->type = type;
	std::cout << YELLOW << "[ANIMAL]: String constructor called" << DEFAULT << std::endl;
}

AAnimal::AAnimal(const AAnimal &original)
{
	std::cout << YELLOW << "[ANIMAL]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

AAnimal::~AAnimal()
{
	std::cout << YELLOW << "[ANIMAL]: Destructor called" << DEFAULT << std::endl;
}

AAnimal const &AAnimal::operator=(AAnimal const &original)
{
    if (this != &original)
	{
		this->type = original.type;
    }
    std::cout << YELLOW << "[ANIMAL]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (this->type);
}

//sera overwritten par la fonction membre des animaux (polymorphisme)
void    AAnimal::makeSound() const
{
    std::cout << YELLOW << "[ANIMAL]: makeSound function called" << DEFAULT << std::endl;
}