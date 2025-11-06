#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class   WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &original);
        ~WrongCat();
        WrongCat &operator=(const WrongCat &original);

        void    makeSound() const;
};

#endif