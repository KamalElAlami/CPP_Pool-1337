#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <cstdlib>
#include <algorithm>

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