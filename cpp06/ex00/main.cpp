#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Usage : ./convert DATA" << std::endl, 1);
    ScalarConverter::convert(av[1]);
}