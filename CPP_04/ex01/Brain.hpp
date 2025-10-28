#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

# define DEFAULT "\001\033[0;39m\002"
# define YELLOW "\001\033[1;93m\002"

class   Brain
{
    public:
        Brain();
        Brain(const Brain &original);
        ~Brain();
        Brain &operator=(const Brain &original);
    
    protected:
        std::string ideas[100];
};

#endif