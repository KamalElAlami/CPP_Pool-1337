#include "PmergeMe.hpp"
#include <utility>

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

void createMainAndPend(std::vector<std::pair<int, int> >& vec, std::vector<int>& main, std::vector<int>& pend, int remainder)
{    
    for (size_t i = 0; i < vec.size() - 1; i++)
    {
        if (!i)
        {
            main.push_back(vec[i].second);
            main.push_back(vec[i].first);
        }
        else
        {
            main.push_back(vec[i].first);
            pend.push_back(vec[i].second);
        }
    }
    if (remainder != -1)
        pend.push_back(remainder);
    std::cout << "Main Chain" << std::endl;
    for (size_t i = 0; i < main.size() - 1; i++)
        std::cout << main[i] << " ";
    std::cout << std::endl;
    std::cout << "pend Chain" << std::endl;
    for (size_t i = 0; i < pend.size() - 1; i++)
        std::cout << pend[i] << " ";
    std::cout << std::endl;
}


void makePairs(std::vector<int>& vec)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> main;
    std::vector<int> pend;
    int remainder = (vec.size() % 2 == 1) ? vec[vec.size() - 1] : -1;
    for (size_t i = 0; i < vec.size() - 1 ; i += 2)
            pairs.push_back(std::make_pair(std::max(vec[i], vec[i + 1]), std::min(vec[i], vec[i + 1])));
    std::sort(pairs.begin(), pairs.end());
    createMainAndPend(pairs, main, pend, remainder);
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