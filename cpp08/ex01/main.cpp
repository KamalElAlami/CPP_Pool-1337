#include "Span.hpp"

int main()
{

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    // {
    //     sp.addNumbers(sp.getBackpack().begin(), sp.getBackpack().end());
    //     for (size_t i = 0; i < sp.getBackpack().size(); i++)
    //         std::cout << sp.getBackpack()[i] << std::endl;
    //     return 0;
    // }
}
