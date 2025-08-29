#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try{
        if (ac < 2)
            throw std::runtime_error("Error: could not open file.");
        bitcoinExchange obj(av[1]);
        obj.run();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}