#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T1>
void iter(T1& array, size_t size, void (*func)(T1&))
{
    if (!func)
        return ;
    for (size_t i = 0; i < size; i++)
    {
        func(array[i])
    }
}

#endif
