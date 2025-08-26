#include <iostream>
#include <vector>


int main()
{
    std::vector<int> vec;
    vec.push_back(9);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(0);
    vec.push_back(8);
    vec.push_back(4);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(10);
    // mergeSort_compact(vec, 0, vec.size());
    mergesort(vec, 0, vec.size());
    for (int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << std::endl;
}