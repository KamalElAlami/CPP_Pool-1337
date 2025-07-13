#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private :
        std::vector<int> backpack;
        unsigned int length;
    public :
        Span();
        Span(unsigned int l);
        Span(const Span& obj);
        ~Span();
        Span& operator=(const Span& obj);
        const std::vector<int>& getBackpack(void) const;
        const unsigned int& getLength(void) const;
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        template<typename T>
        void addNumbers(T begin, T end)
        {
            backpack.insert(backpack.end(), begin, end);
        }
};

#endif