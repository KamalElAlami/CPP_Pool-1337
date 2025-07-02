#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <cstdint>

// typedef unsigned int		uintptr_t;

typedef struct
{
    int id;
    std::string name;
} Data;

class Serializer
{
    private :
        Serializer();
        Serializer(const Serializer& obj);
		~Serializer();
		Serializer& operator=(const Serializer& obj);
    public :
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif