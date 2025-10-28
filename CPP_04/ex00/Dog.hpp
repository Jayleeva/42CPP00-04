#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class   Dog: public Animal
{
    public:
        Dog();
        Dog(const Dog &original);
        ~Dog();
        Dog &operator=(const Dog &original);

        virtual void    makeSound() const;
};

#endif