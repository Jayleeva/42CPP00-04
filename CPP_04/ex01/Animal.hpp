#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

//le deconstructeur doit etre virtual pour eviter les comportements inattendus venant du melange delete et polymorphisme.
//la func makeSound doit etre virtual parce que doit etre overwritten par celles des animaux (polymorphisme).
class   Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &original);
        virtual ~Animal();
        Animal const &operator=(Animal const &original);

		std::string		getType(void) const;
		void	        setType(std::string type);
    
		virtual Brain   &getBrain(void) const = 0;
    
        virtual void    makeSound() const;

    protected:
        std::string type;
};

#endif