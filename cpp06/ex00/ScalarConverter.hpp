#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cfloat> 
#include <cmath>
#include <iomanip>
#include <limits>
#include <cstdio>

typedef enum {
    CHAR,
    FLOAT,
    DOUBLE,
    INT,
    UNKNOWN,
} Types;



class ScalarConverter
{
    private :
        ScalarConverter();
		ScalarConverter(const ScalarConverter& obj);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& obj);
    public :
        static void convert(std::string input);
};

#endif