#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>

# define YELLOW "\001\033[1;93m\002"
# define DEFAULT "\001\033[0;39m\002"

int ft_sed(char *path, std::string s1, std::string s2);

#endif