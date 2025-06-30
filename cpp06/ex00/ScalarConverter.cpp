#include "ScalarConverter.hpp"
#include <cfloat> 
#include <cmath>

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& obj)
{
    *this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
    (void)obj;
    return (*this);
}

// static bool isInt(std::string input)
// {
//     size_t i = 0;
//     if (input.empty())
//         return (false);
//     if (input[i] == '-' || input[i] == '+')
//         i++;
//     while (i < input.size())
//     {
//         if (!isdigit(input[i]))
//             return (false);
//         i++;
//     }
//     return (true);
// }

// static bool isFloat(std::string input)
// {
//     size_t i = 0;
//     if (input.empty())
//         return (false);
//     if (std::count(input.begin(), input.end(), '.') > 1
//         || std::count(input.begin(), input.end(), '.') < 1)
//         return (false);
//     if (input[input.length() - 1] != 'f' || input[input.length() - 2] == '.')        
//         return (false);
//     if (input[i] == '-' || input[i] == '-')
//         i++;
//     if (input[i] == '.')
//         return (false);
//     while (i < (input.size() - 1))
//     {
//         if (!isdigit(input[i]) && input[i] != '.')
//             return (false);
//         i++;
//     }
//     return (true);
// }
// static bool isDouble(std::string input)
// {
//     size_t i = 0;
//     if (input.empty())
//         return (false);
//     if (std::count(input.begin(), input.end(), '.') > 1
//         || std::count(input.begin(), input.end(), '.') < 1)
//         return (false);
//     if (input[input.length() - 1] == '.')        
//         return (false);
//     if (input[i] == '-' || input[i] == '-')
//         i++;
//     if (input[i] == '.')
//         return (false);
//     while (i < (input.size() - 1))
//     {
//         if (!isdigit(input[i]) && input[i] != '.')
//             return (false);
//         i++;
//     }
//     return (true);
// }

// static bool is_displayable(std::string input)
// {
//     if (!input.empty() && input.size() == 1 && !isdigit(input[0]) &&
//         (input[0] >= 32 && input[0] <= 126))
//         return (true);
//     return (false);
// }

// static bool isChar(std::string input)
// {
//     if (!input.empty() && input.size() == 1 && !isdigit(input[0]))
//         return (true);
//     return (false);
// }
#include <cstdio>

void ScalarConverter::convert(std::string input)
{
    char *tracker;
    double res = std::strtod(input.c_str(), &tracker);

    printf("tracker = %d\n", *tracker);

    std::cout << "result = " << res << std::endl;
    if (std::isnan(res)) // CORRECT way to check for NaN
    {
        std::cout << "sidko" << std::endl;
    }
    // You might also want to handle infinity
    else if (std::isinf(res)) // Optional: Check for infinity
    {
        std::cout << "This is infinity!" << std::endl;
    }
    // float s = static_cast<float>(res);

    // long double res = LDBL_MAX;
    // std::cout << "defef" << std::endl;

}