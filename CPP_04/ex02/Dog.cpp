#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog() : AAnimal("Dog")
{
	std::cout << YELLOW << "[DOG]: Default constructor called" << DEFAULT << std::endl;
	this->b = new Brain();
}

//Pour faire une deep copy et pas une shallow, on ne peut pas utiliser *this = original comme avant (qui fait pointer sur la même adresse), il faut allouer un nouvel espace avec new.
Dog::Dog(const Dog &original) : AAnimal("Dog")
{
	std::cout << YELLOW << "[DOG]: Copy constructor called" << DEFAULT << std::endl;
	this->b = new Brain(*original.b);
}

Dog::~Dog()
{
	delete this->b;
	std::cout << YELLOW << "[DOG]: Destructor called" << DEFAULT << std::endl;

}

//Utiliser set et get pour que ça marche à cause du fait que Brain *b est un pointeur. Autre syntaxe qui permet de contourner le soucis?
Dog &Dog::operator=(const Dog &original)
{
    if (this != &original)
	{
		this->type = original.type;
		this->setBrain(original.getBrain());
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