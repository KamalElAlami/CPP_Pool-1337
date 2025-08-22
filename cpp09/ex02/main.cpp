#include "PmergeMe.hpp"


int binarySearch(std::vector<int> vec, int start, int end, int x)
{
    if (start > end)
        return (start);
    int mid = (start + end) / 2;                                                                                      
    if (vec[mid] == x)
        return (mid);
    if (vec[mid] > x)
        return (binarySearch(vec, start, mid -1, x));
    else 
        return (binarySearch(vec, mid + 1, end, x));
}

void createMainAndPend(std::vector<int>& vec, std::vector<int>& main, std::vector<int>& pend)
{    
    for (size_t i = 0; i < vec.size(); i++)
    {
        if (!i)
        {
            main.push_back(vec[1]);
            main.push_back(vec[0]);
            i += 2;
        }
        if (i % 2 == 0)
            main.push_back(vec[i]);
        else
            pend.push_back(vec[i]);
    }
}

void makePairs(std::vector<int>& vec)
{
    std::vector<int> main;
    std::vector<int> pend;
    for (size_t i = 0; i < vec.size() - 1 ; i += 2)
    {
        if (vec[i] < vec[i + 1])
            std::swap(vec[i], vec[i + 1]);
    }
    createMainAndPend(vec, main, pend);
    std::cout << binarySearch(main, 0, main.size(), 9) << std::endl;
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