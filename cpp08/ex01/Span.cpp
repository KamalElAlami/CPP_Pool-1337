#include "Span.hpp"

Span::Span() : length(0)
{}

Span::Span(unsigned int l) : length(l)
{}

Span::~Span()
{}

Span::Span(const Span& obj)
{
    *this = obj;
}

Span& Span::operator=(const Span& obj)
{
    if (this != &obj)
    {
        for (size_t i = 0; i < obj.getBackpack().size(); i++)
            this->backpack[i] = obj.getBackpack()[i];
        this->length = obj.getLength();
    }
    return (*this);
}

const std::vector<int>& Span::getBackpack(void) const
{
    return (backpack);
}

const unsigned int& Span::getLength(void) const
{
    return (length);
}

void Span::addNumber(int n)
{
    if (backpack.size() >= length)
        throw std::runtime_error("You have exceed the backpack capacity");
    backpack.push_back(n);
}

int Span::longestSpan()
{
    int largest;
    if (length < 2)
        throw std::runtime_error("not enough elements to perform this comparison");
    std::vector<int> sorted = backpack;
    std::sort(sorted.begin(), sorted.end());

    largest =  sorted.back() - *sorted.begin();
    return (largest);
}

int Span::shortestSpan()
{
    int comp;
    
    if (length < 2)
        throw std::runtime_error("not enough elements to perform this comparison");
    std::vector<int> sorted = backpack;
    std::sort(sorted.begin(), sorted.end());
    int shortest = sorted.back();
    for (size_t i = 1; i < length; i++)
    {
        comp = sorted[i] - sorted[i - 1];
        if (comp < shortest)
            shortest = comp;
    }
    return (shortest);
}