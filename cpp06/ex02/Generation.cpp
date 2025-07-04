#include "Base.hpp"

Base * generate(void)
{
    static int helper = 0;
    int luckyNumber;
    Base *obj = NULL;
    srand(time(NULL) + helper);
    luckyNumber = rand() % 3;

    switch (luckyNumber)
    {
        case 0:
            obj = new A();
            break ;
        case 1:
            obj = new B();
            break ;
        case 2:
            obj = new C();
            break ;
    }
    helper++;
    return (obj);
}
void identify(Base* p)
{
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "C" << std::endl;
    else 
        std::cout << "Unknown" << std::endl;

}
void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch(const std::exception& e)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B" << std::endl;
        }
        catch(const std::exception& e)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C" << std::endl;
            }
            catch(const std::exception& e)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
    
}