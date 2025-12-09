#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

//le deconstructeur doit etre virtual pour eviter les comportements inattendus venant du melange delete et polymorphisme.
//la func makeSound ne doit pas etre virtual parce que ne doit pas etre overwritten par celles des animaux (polymorphisme).
class   WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(std::string type);
        WrongAnimal(const WrongAnimal &original);
        virtual ~WrongAnimal();
        WrongAnimal const &operator=(WrongAnimal const &original);

		std::string		getType(void) const;
		void	        setType(std::string type);

        void    makeSound() const;

    protected:
        std::string type;
};

#endif