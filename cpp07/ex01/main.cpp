#include "iter.hpp"
#include <string.h>

template<typename T1>
void addOne(T1& x)
{
   std::cout << x + 1 << std::endl;
}


int main()
{
    std::cout << "=================== INT ===================" << std::endl;
    int arri[] = {1, 2, 3, 4, 5};
    iter(arri, 5, addOne);
    std::cout << "=================== CHAR ===================" << std::endl;
    char arrs[] = {'a', 'b', 'c', 'd', 'e'};
    iter(arrs, 5, addOne);
     std::cout << "=================== DOUBLE ===================" << std::endl;
    double arrd[] = {1.665464, 54.235, 78.221545, 548.3365, 0.23154};
    iter(arrd, 5, addOne);
}