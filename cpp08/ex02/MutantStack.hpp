#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> // here is the default conainer type for std::stack is std::deque<T>
{
    public:
        typedef typename std::stack<T>::container_type::iterator iterator; //here i m accessing the iterator type of the underlying container
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
        iterator begin() { return std::stack<T>::c.begin(); }
        iterator end() { return std::stack<T>::c.end(); }
        const_iterator begin() const { return std::stack<T>::c.begin(); }
        const_iterator end() const { return std::stack<T>::c.end(); }

};

#endif


