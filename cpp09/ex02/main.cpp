#include "PmergeMe.hpp"

void makePairs(std::vector<int>& vec) {
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    
    for (size_t i = 0; i < vec.size() - 1 ; i += 2)
    {
        if (vec[i] < vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
    }
    
    std::cout << "After: ";
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

int main(int ac, char **av)
{
    (void)ac;
    std::vector<int> container;
    for (int i = 1; av[i]; i++)
    {
        bool flag =  true;
        for (int j = 0; av[i][j]; j++)
        {
            if (!isdigit(av[i][j]))
                flag = false; 
        }
        long number = atol(av[i]);
        if (flag && number <= INT_MAX && number >= 0)
        container.push_back(number);
        else
        return (std::cerr << "Error" << std::endl, 1);
    }
    makePairs(container);
}