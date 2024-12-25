#include <iostream>

using std::cout;
using std::string;

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
    for (int i = 1; av[i]; i++)
    {
        string arg(av[i]);
        for (int j = 0; j < (int)arg.length(); j++)
            cout << (char)std::toupper(arg[j]);
    }
    cout << std::endl;
}
