#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class   Animal
{
    public:
        Animal();
        Animal(std::string type);
        Animal(const Animal &original);
        ~Animal();
        Animal const &operator=(Animal const &original);

		std::string		getType(void) const;
		void	        setType(std::string type);

        virtual void    makeSound() const;

    protected:
        std::string type;
};

#endif