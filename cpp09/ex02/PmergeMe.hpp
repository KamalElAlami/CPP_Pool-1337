#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>
#include <cctype> 
#include <utility>
#include <exception>
#include <algorithm>
#include <ctime>

int jacobsthal_Sequence(int n);
template < template<typename T, typename Allocator = std::allocator<T> > class Container >
class PmergeMe
{
    public :
        PmergeMe() : start(clock()), remainder(-1){};

        void parseInput(char **av)
        {
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
                    unsorted.push_back(number);
                else
                    throw std::runtime_error("Error");
            }
        }
        void sortPairs(Container< std::pair<long,long> >& a, size_t n) {
            if (n <= 1) return;
            sortPairs(a, n - 1);
            std::pair<long,long> key = a[n - 1];
            size_t j = n - 1;
            while (j > 0 && a[j - 1].first > key.first) {
                a[j] = a[j - 1];
                --j;
            }
            a[j] = key;
        }

        void performSorting() 
        {
            before = unsorted;
            if (unsorted.size() % 2 == 1)
            {
                remainder = unsorted[unsorted.size() - 1];
                unsorted.pop_back();
            }
            for (size_t i = 0; i < unsorted.size(); i += 2)
                pairs.push_back(std::make_pair(std::max(unsorted[i], unsorted[i + 1]), std::min(unsorted[i], unsorted[i + 1])));
            sortPairs(pairs, pairs.size());
            splitUnsortedContainer();
        }

        void splitUnsortedContainer()
        {
            main.push_back(pairs[0].second);
            main.push_back(pairs[0].first);
            for (size_t i = 1; i < pairs.size(); i++)
            {
                    main.push_back(pairs[i].first);
                    pend.push_back(pairs[i].second);
            }

            Container<long> seq = genSortingSequence(static_cast<int>(pend.size()));
            
            if (!pend.empty())
            {
                for (size_t i = 0; i < seq.size(); i++)
                {
                    if (seq[i] >= static_cast<int>(pend.size()))
                        continue;
                    int index = binarySearch(0, main.size() - 1, pend[seq[i]]);
                    if (static_cast<size_t>(index) < main.size())
                        main.insert(main.begin() + index, pend[seq[i]]);
                    else
                        main.insert(main.end(), pend[seq[i]]);
                }
            }
            if (remainder != -1)
                main.insert(main.begin() + binarySearch(0, main.size() - 1, remainder), remainder);
            end = clock();
        }

        Container<long> genSortingSequence(int size)
        {
            Container<long> seq;
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
            Container<long> remaining;
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

        long binarySearch(int start, int end, int x)
        {
            if (start > end)
                return (start);
            int mid = (start + end) / 2;                                                                                      
            if (main[mid] < x && (mid + 1 >= (int)main.size() || main[mid + 1] > x)) // check bounds or check next
                return (mid + 1);
            if (main[mid] > x)
                return (binarySearch(start, mid -1, x));
            else 
                return (binarySearch(mid + 1, end, x));
        }

        void printContainer(Container<long>& con)
        {
            for (size_t i = 0; i < con.size(); i++)
                std::cout << con[i] << " ";
            std::cout << std::endl;
        }

        void getElapsedTime(std::string container)
        {
            double time = ((double)(end - start) / CLOCKS_PER_SEC) * 1000000;
            std::cout << "Time to process a range of " << before.size() <<" elements with " <<
                container << " : " << time <<" us" << std::endl;
        }

        Container<long>& getSorted(){return (main);}
        Container<long>& getUnsorted(){return (before);}

    private :
        clock_t start;
        clock_t end;
        Container<long> unsorted;
        Container<long> before;
        Container<std::pair<long, long> > pairs;
        Container<long> main;
        Container<long> pend;
        long remainder;
};

#endif
