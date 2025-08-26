#include "PmergeMe.hpp"
std::vector<int> sortAll(std::vector<int> unsorted);

int main(int ac, char **av)
{
    if (ac < 2)
        return (std::cerr << "Error" << std::endl, 1);
    try
    {
        int tmp[] = {1, 9, 0, 11, 22, 1000, 3};
        std::vector<int> vec = sortAll(std::vector<int>(tmp, tmp + 7));
        for (int& e : vec) std::cout  << e << " ";
        std::cout << std::endl;
        // PmergeMe<std::vector> vec;
        // PmergeMe<std::deque> dec;

        // vec.parseInput(av);
        // dec.parseInput(av);
        // vec.performSorting();
        // dec.performSorting();
        // vec.printContainer(vec.getUnsorted());
        // dec.printContainer(dec.getUnsorted());
        // vec.printContainer(vec.getSorted());
        // dec.printContainer(dec.getSorted());
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << std::endl;
    }
    
}