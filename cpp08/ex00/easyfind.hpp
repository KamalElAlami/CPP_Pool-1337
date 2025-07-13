#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

template<typename T>
bool easyFind(T container, int occ)
{
    typename T::iterator it = find(container.begin(), container.end(), occ);
    if (it == container.end())
        return (false);
    return (true);
}

#endif