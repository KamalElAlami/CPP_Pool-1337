#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error" << std::endl, 1);
    try
    {
        std::vector<int> vec = parseArgsVector(av);
        std::deque<int> dec = parseArgsDeque(av);
        clock_t dstart = clock();
        sortWithDeque(dec);
        clock_t dend = clock();
        clock_t vstart = clock();
        sortWithVector(vec);
        clock_t vend = clock();
        double time_taken_deque = ((double)(dend - dstart) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
        double time_taken_vector = ((double)(vend - vstart) / CLOCKS_PER_SEC) * 1000000; // Convert to microseconds
        std::cout << "Time to process a range of " << vec.size() << " elements with std::deque : " << time_taken_deque << " us" << std::endl;
        std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << time_taken_vector << " us" << std::endl;
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}