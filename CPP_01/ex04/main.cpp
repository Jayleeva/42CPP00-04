#include "sed.hpp"

int ft_sed(char *path, std::string s1, std::string s2);

int main()
{
    char    *path0 = NULL;
    std::string p1 = "tests/test1.txt";
    char    *path1 = &p1[0];
    std::string p2 = "test";
    char    *path2 = &p2[0];
    std::string p3 = "tests/test3.txt";
    char    *path3 = &p3[0];
    std::string p4 = "tests/test4.txt";
    char    *path4 = &p4[0];
    std::string p5 = "tests/test5.cpp.txt";
    char    *path5 = &p5[0];
    std::string str = "";

    //MISSING PARAMETERS
    std::cout << "[DEBUG] : MISSING PARAMETERS" << std::endl;
    ft_sed(path0, "FICHIER TEST", "fichier test");
    ft_sed(path1, "FICHIER TEST", str);
    ft_sed(path1, str, "fichier test");

    //INVALID FILE
    std::cout << "[DEBUG] : INVALID FILE" << std::endl;
    ft_sed(path2, "FICHIER TEST", "fichier test");

    //OK
    ft_sed(path1, "FICHIER TEST", "fichier test");
    ft_sed(path3, "FICHIER\n TEST", "fichier\n test");
    ft_sed(path4, "FICHIER TEST", "fichier\n test");
    ft_sed(path5, "FICHIER TEST", "fichier test");
    return (0);
}