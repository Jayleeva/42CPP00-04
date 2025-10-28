#include "Animal.hpp"

Animal::Animal()
{
	std::cout << YELLOW << "[ANIMAL]: Default constructor called" << DEFAULT << std::endl;
}

Animal::Animal(std::string type)
{
    this->type = type;
	std::cout << YELLOW << "[ANIMAL]: String constructor called" << DEFAULT << std::endl;
}

Animal::Animal(const Animal &original)
{
	std::cout << YELLOW << "[ANIMAL]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

Animal::~Animal()
{
	std::cout << YELLOW << "[ANIMAL]: Destructor called" << DEFAULT << std::endl;
}

Animal const &Animal::operator=(Animal const &original)
{
    if (this != &original)
	{
		this->type = original.type;
    }
    std::cout << YELLOW << "[ANIMAL]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

std::string Animal::getType() const
{
    return (this->type);
}

/*std::string Animal::getSound() const
{
    return (this->sound);
}*/

void    Animal::makeSound() const
{
    if (this->getType() == "Cat")
        std::cout << "MEOW MEOW" << std::endl;
    else if (this->getType() == "Dog")
        std::cout << "BARK BARK" << std::endl;
    /*else
        std::cout << "[DEFAULT SOUND]" << std::endl;*/
    //std::cout << this->getSound() << std::endl;
    //std::cout << "[DEFAULT SOUND]" << std::endl;
}