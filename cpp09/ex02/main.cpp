#include "PmergeMe.hpp"

void makePairs(std::vector<int>& vec) {
    // if (vect[i] < vect[i + 1])
    
}

int main(int ac, char **av)
{
    std::vector<int> container;
    for (int i = 1; av[i]; i++)
    {
        bool flag =  true;
        for (int j = 0; av[i][j]; j++)
        {
            if (!isdigit(av[i][j]))
            {
                flag = false; 
            }
        }
        long number = atol(av[i]);
        if (flag && number <= INT_MAX && number >= 0)
            container.push_back(number);
        else
            return (std::cerr << "Error" << std::endl, 1);
    }
    
    // for (size_t i = 0; i < container.size(); i++)
    //     std::cout << container[i] << " ";
    // std::cout << std::endl;
}