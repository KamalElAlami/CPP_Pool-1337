#include <iostream>
#include <vector>

long jacobsthalseq(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthalseq((n - 1)) + 2 * jacobsthalseq(n - 2));
}

int main()
{
    int lent = 3 ;
    std::vector<int> re;
    for(int i = 0 ;  ;i++)
    {
        int tmp = jacobsthalseq(i);
        std::cout << tmp << std::endl; 
         re.push_back(tmp) ;
        if(  lent  <= tmp )
        {
                break;
        }

    }
    
}

