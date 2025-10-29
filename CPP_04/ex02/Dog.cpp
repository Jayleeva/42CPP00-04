#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << YELLOW << "[DOG]: Default constructor called" << DEFAULT << std::endl;
	this->b = new Brain();
}

//Pour faire une deep copy et pas une shallow, on ne peut pas utiliser *this = original comme avant, puisque le Brain est alloué avec new.
Dog::Dog(const Dog &original) : AAnimal("Dog")
{
	std::cout << YELLOW << "[DOG]: Copy constructor called" << DEFAULT << std::endl;
	this->b = new Brain(*original.b);
	//*this = original;
}

Dog::~Dog()
{
	delete this->b;
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

Brain	&Dog::getBrain() const
{
	return *(this->b);
}

void	Dog::setBrain(Brain const &brain)
{
	*this->b = brain;
}

void    Dog::makeSound() const
{
    std::cout << "BARK BARK" << std::endl;
}