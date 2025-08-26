#include "PmergeMe.hpp"


int jacobsthal_Sequence(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    long pre2 = 0, pre1 = 1, current;
    for (int i = 2; i <= n; i++)
    {
        current = pre1 + 2 * pre2;
        pre2 =  pre1;
        pre1 = current;
    }
    return (current);
}