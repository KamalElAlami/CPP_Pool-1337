#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    private :
        T*      array;
        size_t  size;
    public :
        Array()
        Array(unsigned int n);
        Array(const Array& obj);
        Array& operator=(const Array& obj);
        ~Array();

};

#endif