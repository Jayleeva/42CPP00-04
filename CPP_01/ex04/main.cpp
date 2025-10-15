#include "sed.hpp"

int ft_sed(char *path, string s1, string s2);

int main()
{
    //char    *path0 = NULL;
    string p1 = "tests/test1.txt";
    char *path1 = &p1[0];
    string p2 = "test";
    char *path2 = &p2[0];
    string p3 = "tests/test3.txt";
    char *path3 = &p3[0];
    string p4 = "tests/test4.txt";
    char *path4 = &p4[0];
    string p5 = "tests/test5.cpp.txt";
    char *path5 = &p5[0];

    //MISSING PARAMETERS
    //ft_sed(path0, "FICHIER TEST", "fichier test");
    //ft_sed(argv[1], "FICHIER TEST", NULL);
    //ft_sed(argv[1], NULL, s2);

    //INVALID FILE
    ft_sed(path2, "FICHIER TEST", "fichier test");

    //OK
    ft_sed(path1, "FICHIER TEST", "fichier test");
    ft_sed(path3, "FICHIER\n TEST", "fichier\n test");
    ft_sed(path4, "FICHIER TEST", "fichier\n test");
    ft_sed(path5, "FICHIER TEST", "fichier test");
    return (0);
}