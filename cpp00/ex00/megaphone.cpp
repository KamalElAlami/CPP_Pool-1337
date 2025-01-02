#include <iostream>

using std::cout;
using std::string;
using std::endl;

int main(int ac, char **av)
{
    if (ac < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
        return (0);
    }
    for (int i = 1; av[i]; i++)
    {
        string arg(av[i]);
        for (size_t j = 0; j < arg.length(); j++)
            cout << (char)std::toupper(arg[j]);
    }
    cout << endl;
    return (0);
}
