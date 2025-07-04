#include "Base.hpp"

int main()
{
    Base* try1 = generate();
    Base* try2 = generate();
    Base* try3 = generate();

    identify(try1);
    identify(try2);
    identify(try3);

    Base* try4 = generate();
    Base* try5 = generate();
    Base* try6 = generate();
    
    identify(*try4);
    identify(*try5);
    identify(*try6);
    identify(NULL);

    delete try1;
    delete try2;
    delete try3;
    delete try4;
    delete try5;
    delete try6;
}