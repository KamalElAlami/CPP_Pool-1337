#include "PmergeMe.hpp"

std::deque<int> parseArgsDeque(char **av)
{
    std::deque<int> container;
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

std::deque<long> getJacIndexDeque(int size)
{
    std::deque<long> seq;
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
    std::deque<long> remaining;
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
int binarySearchDeque(std::deque<int> vec, int start, int end, int x)
{
    if (start > end)
        return (start);
    int mid = (start + end) / 2;                                                                                      
    if (vec[mid] < x && (mid + 1 >= (int)vec.size() || vec[mid + 1] > x)) // check bounds or check next
        return (mid + 1);
    if (vec[mid] > x)
        return (binarySearchDeque(vec, start, mid -1, x));
    else 
        return (binarySearchDeque(vec, mid + 1, end, x));
}

void createMainAndPendDeque(std::deque<std::pair<int, int> >& vec, std::deque<int>& main, std::deque<int>& pend, int remainder)
{
    main.push_back(vec[0].second);
    main.push_back(vec[0].first);
    for (size_t i = 1; i < vec.size(); i++)
    {
            main.push_back(vec[i].first);
            pend.push_back(vec[i].second);
    }

    std::deque<long> seq = getJacIndexDeque(pend.size());
    
    if (!pend.empty())
    {
        for (size_t i = 0; i < seq.size(); i++)
        {
            int index = binarySearchDeque(main, 0, main.size() - 1, pend[seq[i]]);
            if ((size_t)index < main.size())
                main.insert(main.begin() + index, pend[seq[i]]);
            else
                main.insert(main.end(), pend[seq[i]]);
        }
    }
    if (remainder != -1)
        main.insert(main.begin() + binarySearchDeque(main, 0, main.size() - 1, remainder), remainder);

}


void sortWithDeque(std::deque<int>& vec)
{
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> main;
    std::deque<int> pend;
    int remainder = (vec.size() % 2 == 1) ? vec[vec.size() - 1] : -1;
    for (size_t i = 0; i < vec.size() - 1; i += 2)
            pairs.push_back(std::make_pair(std::max(vec[i], vec[i + 1]), std::min(vec[i], vec[i + 1])));
    std::sort(pairs.begin(), pairs.end());
    createMainAndPendDeque(pairs, main, pend, remainder);
    std::cout << "Before: ";
    printList(vec);
    std::cout << "After: ";
    printList(main);
}