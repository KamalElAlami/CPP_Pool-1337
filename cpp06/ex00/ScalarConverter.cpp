#include "ScalarConverter.hpp"

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

static bool isInt(std::string input)
{
    size_t i = 0;
    if (input.empty())
        return (false);
    if (input[i] == '-' || input[i] == '+')
        i++;
    while (i < input.size())
    {
        if (!isdigit(input[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool isFloat(std::string input)
{
    size_t i = 0;
    if (input.empty())
        return (false);
    if (std::count(input.begin(), input.end(), '.') > 1
        || std::count(input.begin(), input.end(), '.') < 1)
        return (false);
    if (input[input.length() - 1] != 'f')        
        return (false);
    if (input[i] == '-' || input[i] == '-')
        i++;
    while (i < (input.size() - 1))
    {
        if (!isdigit(input[i]) && input[i] != '.')
            return (false);
        i++;
    }
    return (true);
}
static bool isDouble(std::string input)
{
    size_t i = 0;
    if (input.empty())
        return (false);
    if (std::count(input.begin(), input.end(), '.') > 1
        || std::count(input.begin(), input.end(), '.') < 1)
        return (false);
    if (input[i] == '-' || input[i] == '-')
        i++;
    while (i < (input.size() - 1))
    {
        if (!isdigit(input[i]) && input[i] != '.')
            return (false);
        i++;
    }
    return (true);
}

static bool isDisplayable(double result)
{
    if (result >= 32 && result <= 126)
        return (true);
    return (false);
}

static bool isChar(std::string input)
{
    if (!input.empty() && input.size() == 1 && !isdigit(input[0]))
        return (true);
    return (false);
}

bool intOverflow(double f)
{
    if (f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
        return true;
    return false;
}

bool charOverflow(double result)
{
    if (result > std::numeric_limits<char>::max() || result < std::numeric_limits<char>::min())
        return true;
    return false;
}

static Types whichType(std::string input)
{
    if (isInt(input))
        return (INT);
    else if (isChar(input))
        return (CHAR);
    else if (isDouble(input))
        return (DOUBLE);
    else if  (isFloat(input))
        return (FLOAT);
    else
        return (UNKNOWN);
}

bool ft_isinf(double x)
{
    if (x == (1.0 / 0.0) || x == (-1.0 / 0.0))
        return (true);
    return (false);
}

bool ft_isnan(double x)
{
    if (x != x)
        return (true);
    return (false);
}

void ScalarConverter::convert(std::string input)
{
    Types type;
    char *track = NULL;

    type = whichType(input);
    std::string tracker = track;
    double result;
    if (type == CHAR && input.size() == 1)
        result = static_cast<double>(input[0]);
    else
        result = std::strtod(input.c_str(), &track);
    if ((type == UNKNOWN && (!ft_isnan(result) && !ft_isinf(result))))
        std::cout << "char: Impossible" << std::endl << "int: Impossible" <<
        std::endl << "float: Impossible" << std::endl << "double: Impossible" << std::endl;
    else
    {
        if (isDisplayable(result))
            std::cout << "char: " << static_cast<char>(result) << std::endl;
        else if (charOverflow(result) || ft_isnan(result) || ft_isinf(result))
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (!intOverflow(result) && !ft_isnan(result) && !ft_isinf(result))
            std::cout << "int: " << static_cast<int>(result) << std::endl;
        else
            std::cout << "int: Impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1) <<"float: " << static_cast<float>(result) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(result) << std::endl;
    }

}