#include "easyfind.hpp"


int main()
{
    std::list<int> l;
    std::deque<int> deq;
    std::vector<int> vec;
    l.push_back(5);
    l.push_back(9);
    l.push_back(10);
    l.push_back(90);
    l.push_back(98);
    l.push_back(12);
    deq.push_back(5);
    deq.push_back(9);
    deq.push_back(10);
    deq.push_back(90);
    deq.push_back(98);
    deq.push_back(12);    
    vec.push_back(5);
    vec.push_back(9);
    vec.push_back(10);
    vec.push_back(90);
    vec.push_back(98);
    vec.push_back(12);
    
    std::cout << "results from list container :" << easyFind(l, 90) << std::endl;
    std::cout << "results from deque container :" << easyFind(deq, 90) << std::endl;
    std::cout << "results from vector container :" << easyFind(vec, 90) << std::endl;
    std::cout << std::endl;
    std::cout << "results from list container :" << easyFind(l, 0) << std::endl;
    std::cout << "results from deque container :" << easyFind(deq, 0) << std::endl;
    std::cout << "results from vector container :" << easyFind(vec, 0) << std::endl;
} 