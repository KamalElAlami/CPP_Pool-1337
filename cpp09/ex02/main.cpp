#include "PmergeMe.hpp"
std::vector<int> sortAll(std::vector<int> unsorted);

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error" << std::endl, 1);
    try
    {
        PmergeMe<std::vector> vec;
        PmergeMe<std::deque> dec;

        vec.parseInput(av);
        dec.parseInput(av);
        vec.performSorting();
        dec.performSorting();
        std::cout << "Before: ";
        vec.printContainer(vec.getUnsorted());
        std::cout << "After: ";
        dec.printContainer(dec.getSorted());
        vec.getElapsedTime("std::vector");
        dec.getElapsedTime("std::deque");
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}