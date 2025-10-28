#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    //this->sound = "BARK BARK";
	std::cout << YELLOW << "[DOG]: Default constructor called" << DEFAULT << std::endl;
}

Dog::Dog(const Dog &original) : Animal("Dog")
{
	std::cout << YELLOW << "[DOG]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

Dog::~Dog()
{
	std::cout << YELLOW << "[DOG]: Destructor called" << DEFAULT << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
    if (this != &original)
	{
		this->type = original.type;
    }
    std::cout << YELLOW << "[DOG]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

/*void    Dog::makeSound() const
{
    std::cout << "BARK BARK" << std::endl;
}*/