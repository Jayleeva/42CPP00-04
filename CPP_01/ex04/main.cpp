#include "sed.hpp"

int ft_sed(std::string path, std::string s1, std::string s2);

int main(int argc, char **argv)
{
    std::string str = "";

    std::string   p0 = "";
    std::string   p1 = "tests/test1.txt";
    std::string   p2 = "test";
    std::string   p3 = "tests/test3.txt";
    std::string   p4 = "tests/test4.txt";
    std::string   p5 = "tests/test5.cpp.txt";

    //MISSING PARAMETERS
    std::cout << "[DEBUG] : ** START OF HARD CODED TESTS **" << std::endl << "---------------------------------" << std::endl;
    std::cout << "[DEBUG] : MISSING PARAMETERS" << std::endl;
    ft_sed(p0, "FICHIER TEST", "fichier test");
    ft_sed(p1, "FICHIER TEST", str);
    ft_sed(p1, str, "fichier test");

    //INVALID FILE
    std::cout << "[DEBUG] : INVALID FILE" << std::endl;
    ft_sed(p2, "FICHIER TEST", "fichier test");

    //OK
    ft_sed(p1, "FICHIER TEST", "fichier test");
    ft_sed(p3, "FICHIER\n TEST", "fichier\n test");
    ft_sed(p4, "FICHIER TEST", "fichier\n test");
    ft_sed(p5, "FICHIER TEST", "fichier test");

    //END OF HARD CODED TESTS
    std::cout << "[DEBUG] : ** END OF HARD CODED TESTS **" << std::endl << "---------------------------------" << std::endl;
    if (argc < 4)
	{
		std::cout << YELLOW << "Error: missing parameters." << DEFAULT << std::endl;
		return (1);
	}
    ft_sed(argv[1], argv[2], argv[3]);
    return (0);
}