#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : AAnimal("Cat")
{
	std::cout << YELLOW << "[CAT]: Default constructor called" << DEFAULT << std::endl;
	this->b = new Brain();
}

//Pour faire une deep copy et pas une shallow, on ne peut pas utiliser *this = original comme avant (qui fait pointer sur la même adresse), il faut allouer un nouvel espace avec new.
Cat::Cat(const Cat &original) : AAnimal("Cat")
{
	std::cout << YELLOW << "[CAT]: Copy constructor called" << DEFAULT << std::endl;
	this->b = new Brain(*original.b);
}

Cat::~Cat()
{
	delete this->b;
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

Brain	&Cat::getBrain() const
{
	return *(this->b);
}

void	Cat::setBrain(Brain const &brain)
{
	*this->b = brain;
}

void    Cat::makeSound() const
{
    std::cout << "MEOW MEOW" << std::endl;
}