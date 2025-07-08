#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template<typename T>
class Array
{
    private :
        T*      array;
        unsigned int  lenght;
    public :
        Array() : array(NULL), lenght(0)
        {}
        Array(unsigned int n) : lenght(n)
        {
            array = new T[lenght];
        }
        Array(const Array& obj)
        {
            *this = obj;
        }
        const Array& operator=(const Array& obj) 
        {
            if (this != &obj)
            {
                this->lenght = obj.lenght;
                delete[] array;
                array = new T[lenght];
                for (size_t i = 0; i < lenght; i++)
                {
                    this->array[i] = obj.array[i];
                }
            }
            return (*this);
        }
        const T& operator[](unsigned int index) const
        {
            if (index > lenght)
                throw std::runtime_error("Out Of Range Index");
            retun (array[index]);
        }
        T& operator[](unsigned int index)
        {
            if (index >= lenght)
                throw std::runtime_error("Out Of Range Index");
            return (array[index]);
        }
        unsigned int size(void) const
        {
            return (lenght);
        }
        T& getArray(void) const
        {
            return (array);
        }
        ~Array()
        {
            delete[] array;
        }

};

#endif