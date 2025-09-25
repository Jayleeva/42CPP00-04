#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        return 0;
    }
    cout << argv[1];
    return 0;
}
