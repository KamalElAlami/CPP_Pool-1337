#include "PmergeMe.hpp"

bool compareByFirst(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return a.first < b.first;
}

std::vector<int> parseArgsVector(char **av)
{
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
            throw std::runtime_error("Error");
    }
    return (container);
}

int jacobsthal_Sequence(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    long pre2 = 0, pre1 = 1, current;
    for (int i = 2; i <= n; i++)
    {
        current = pre1 + 2 * pre2;
        pre2 =  pre1;
        pre1 = current;
    }
    return (current);
}

std::vector<long> getJacIndex(int size)
{
    std::vector<long> seq;
    seq.push_back(0);
    seq.push_back(1);
    if (size <= 2)
        return (seq);
    int i = 3, tmp = 0;
    while (1)
    {
        tmp = jacobsthal_Sequence(i);
        if (tmp >= size)
            break ;
        seq.push_back(tmp);
        i++;
    }
    std::vector<long> remaining;
    for (int i = 0; i < size; i++)
    {
        bool found = false;
        for (size_t j = 0; j < seq.size(); j++)
        {
            if (i == seq[j])
            {
                found = true;
                break ;
            }
        }
        if (!found)
            remaining.push_back(i);
    }
    for (size_t i = 0; i < remaining.size(); i++)
        seq.push_back(remaining[i]);
    return (seq);
}
int binarySearch(std::vector<int> vec, int start, int end, int x)
{
    if (start > end)
        return (start);
    int mid = (start + end) / 2;                                                                                      
    if (vec[mid] < x && (mid + 1 >= (int)vec.size() || vec[mid + 1] > x)) // check bounds or check next
        return (mid + 1);
    if (vec[mid] > x)
        return (binarySearch(vec, start, mid -1, x));
    else 
        return (binarySearch(vec, mid + 1, end, x));
}

void createMainAndPend(std::vector<std::pair<int, int> >& vec, std::vector<int>& main, std::vector<int>& pend, int remainder)
{
    main.push_back(vec[0].second);
    main.push_back(vec[0].first);
    for (size_t i = 1; i < vec.size(); i++)
    {
        main.push_back(vec[i].first);
        pend.push_back(vec[i].second);
    }
    std::vector<long> seq = getJacIndex(pend.size());
    
    if (!pend.empty())
    {
        for (size_t i = 0; i < seq.size(); i++)
        {
            int index = binarySearch(main, 0, main.size() - 1, pend[seq[i]]);
            if ((size_t)index < main.size())
                main.insert(main.begin() + index, pend[seq[i]]);
            else
                main.insert(main.end(), pend[seq[i]]);
        }
    }

    if (remainder != -1)
        main.insert(main.begin() + binarySearch(main, 0, main.size() - 1, remainder), remainder);

}

void sortWithVector(std::vector<int>& vec)
{
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> main;
    std::vector<int> pend;
    int remainder = (vec.size() % 2 == 1) ? vec[vec.size() - 1] : -1;
    for (size_t i = 0; i < vec.size() - 1; i += 2)
            pairs.push_back(std::make_pair(std::max(vec[i], vec[i + 1]), std::min(vec[i], vec[i + 1])));
    std::sort(pairs.begin(), pairs.end(), compareByFirst);
    createMainAndPend(pairs, main, pend, remainder);
    std::cout << "Before: ";
    printList(vec);
    std::cout << "After: ";
    printList(main);
}