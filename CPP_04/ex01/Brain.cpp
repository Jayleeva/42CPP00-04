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

//This ne peut pas marcher avec un array, il faut parcourir chaque élément un à un
Brain   &Brain::operator=(const Brain &original)
{
    if (this != &original)
	{
        for (int i = 0; i < this->nIdeas; i ++)
		    this->ideas[i] = original.ideas[i];
    }
    std::cout << YELLOW << "[BRAIN]: Copy assignment operator = called" << DEFAULT << std::endl;
    return (*this);
}

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index > this->nIdeas)
        return ("");
    return (this->ideas[index]);
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index >= 0 && index <= this->nIdeas)
        this->ideas[index] = idea;
}