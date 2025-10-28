#include "Brain.hpp"

Brain::Brain()
{
	std::cout << YELLOW << "[BRAIN]: Default constructor called" << DEFAULT << std::endl;
}

Brain::Brain(const Brain &original)
{
	std::cout << YELLOW << "[BRAIN]: Copy constructor called" << DEFAULT << std::endl;
	*this = original;
}

Brain::~Brain()
{
    std::cout << YELLOW << "[BRAIN]: Destructor called" << DEFAULT << std::endl;
}

Brain   &Brain::operator=(const Brain &original)
{
    /*if (this != &original)
	{
		this->ideas = original.ideas;
    }*/
    (void)original;
    std::cout << YELLOW << "[BRAIN]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}