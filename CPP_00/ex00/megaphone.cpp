#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int i;
    int space;

    if (argc < 2)
    {
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
        cout << endl;
        return 0;
    }
    i = 1;
    space = 0;
    while (argv[i])
    {
        if (space)
            cout << ' ';
        cout << argv[i];
        if (argv[i + 1])
            space = 1;
        i ++;
    }
    cout << endl;
    return 0;
}
