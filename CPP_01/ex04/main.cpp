#include "sed.hpp"

int main()
{
    //MISSING PARAMETERS
    ft_sed(NULL, "FICHIER TEST", "fichier test");
    ft_sed("test.txt", "FICHIER TEST", NULL);
    ft_sed("test.txt", NULL, "fichier test");
    //INVALID FILE
    ft_sed("test", "FICHIER TEST", "fichier test");
    //OK
    ft_sed("test.txt", "FICHIER TEST", "fichier test");
    ft_sed("test.txt", "FICHIER\n TEST", "fichier\n test");
    ft_sed("test.txt", "FICHIER TEST", "fichier\n test");
    return (0);
}