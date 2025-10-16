#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{

    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    for (int i = 0; i < argc; i++)
    {
        std::string str =  argv[i];
        for (unsigned int j = 0; j < str.size(); j++)
        {
            str[j] = std::toupper(str[j]);
        }
        std::cout << str;
    }
    std::cout << std::endl;
}

