#include "Serializer.hpp"

int main(void)
{
    Data* row = new Data();
    row->id = 15;
    row->name = "mahmoud";

    uintptr_t test = Serializer::serialize(row);
    Data* test2 = Serializer::deserialize(test);

    std::cout << "ID : " << test2->id << std::endl;
    std::cout << "name : " << test2->name << std::endl;

}