
#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <cctype> 
#include <utility>
#include <exception>

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

long binarySearch(int start, int end, int x, std::vector<int> &main)
{
    if (start > end)
        return (start);
    int mid = (start + end) / 2;                                                                                      
    if (main[mid] < x && (mid + 1 >= (int)main.size() || main[mid + 1] > x)) // check bounds or check next
        return (mid + 1);
    if (main[mid] > x)
        return (binarySearch(start, mid -1, x, main));
    else 
        return (binarySearch(mid + 1, end, x, main));
}

std::vector<long> genSortingSequence(int size)
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

   
std::vector<int> sortAll(std::vector<int> unsorted) {

        if (unsorted.size() <= 2) {
            if (unsorted.size() == 2 && unsorted[0] > unsorted[1])
                std::swap(unsorted[0], unsorted[1]);
            return unsorted;
        }
        std::vector<int> main, pend;
        std::vector<std::pair<int, int> >  pairs;
        
        long remainder = (unsorted.size() % 2 == 1) ? unsorted[unsorted.size() - 1] : -1;
        if (remainder != -1) unsorted.pop_back();
        for (size_t i = 0; i < unsorted.size() - 1; i += 2)
                pairs.push_back(std::make_pair(std::max(unsorted[i], unsorted[i + 1]), std::min(unsorted[i], unsorted[i + 1])));

        // main.push_back(pairs[0].second);
        // main.push_back(pairs[0].first);
        for (size_t i = 0; i < pairs.size(); i++)
        {
                main.push_back(pairs[i].first);
                pend.push_back(pairs[i].second);
        }

        main = sortAll(main);
        std::vector<long> seq = genSortingSequence(static_cast<int>(pend.size()));
        
        if (!pend.empty())
        {
            for (size_t i = 0; i < seq.size(); i++)
            {
                int index = binarySearch(0, main.size() - 1, pend[seq[i]], main);
                if (static_cast<size_t>(index) < main.size())
                    main.insert(main.begin() + index, pend[seq[i]]);
                else
                    main.insert(main.end(), pend[seq[i]]);
            }
        }
        if (remainder != -1)
            main.insert(main.begin() + binarySearch(0, main.size() - 1, remainder, main), remainder);
        return main;
}