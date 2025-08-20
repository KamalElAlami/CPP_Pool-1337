#include "RPN.hpp"

int main(int ac, char** av)
{
    try
    {
        if (ac != 2 || !validateArgs(av[1]))
            throw std::runtime_error("Error");
        performRPN(av[1]);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
        
}