#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error" << std::endl, 1);
    try
    {
        std::vector<int> vec = parseArgsVector(av);
        std::deque<int> dec = parseArgsDeque(av);
        sortWithDeque(dec);
        sortWithVector(vec);
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}