#include "BitcoinExchange.hpp"


int main(int ac, char **av)
{
    (void)ac;
    try{
        bitcoinExchange obj(av[1]);
        obj.run();
    }
    catch (const std::runtime_error &e)
    {
        std::cout << e.what() << std::endl;
    }
}