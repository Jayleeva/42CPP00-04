#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class   Cat: public Animal
{
    public:
        Cat();
        Cat(const Cat &original);
        ~Cat();
        Cat &operator=(const Cat &original);

        Brain   &getBrain() const;
        void    setBrain(Brain const &brain);

        void    makeSound() const;

    private:
        Brain   *b;
};

#endif