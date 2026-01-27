#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

//une fonction membre est passee en pure virtual ("virtual" + " = 0") pour qu'on ne puisse plus instancier la classe. Le destructeur est passe en virtual. On peut aussi passer les constructeurs en protected mais pas necessaire.
class   AAnimal
{
    public:
        virtual ~AAnimal();
        AAnimal const &operator=(AAnimal const &original);

		std::string		getType(void) const;
		void	        setType(std::string type);
    
		virtual Brain   &getBrain(void) const = 0;
    
        virtual void    makeSound() const;

    protected:
        AAnimal();
        AAnimal(std::string type);
        AAnimal(const AAnimal &original);
        std::string type;
};

#endif
