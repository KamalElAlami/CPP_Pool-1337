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


void sortWithVector(std::vector<int>& vec);
void sortWithDeque(std::deque<int>& vec);
std::deque<int> parseArgsDeque(char **av);
std::vector<int> parseArgsVector(char **av);
int jacobsthal_Sequence(int n);

template <typename T>
void printList(T container)
{
    for (size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}


#endif