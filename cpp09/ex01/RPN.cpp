#include "RPN.hpp"

std::string* ft_split(const std::string& str, char c)
{
    size_t start = 0, end = 0;
    int count = 0;

    while ((end = str.find(c, start)) != std::string::npos) {
        count++;
        start = end + 1;
    }
    count++;
    
    std::string* words = new std::string[count + 1];
    
    start = 0;
    int index = 0;
    while ((end = str.find(c, start)) != std::string::npos) {
        words[index] = str.substr(start, end - start);
        start = end + 1;
        index++;
    }
    words[index] = str.substr(start); 
    words[index + 1] = "";
    return (words);
}

void eraseFromString(std::string* str, char target)
{
    std::string::size_type pos = (*str).find(target);
    while (pos != std::string::npos)
    {
        (*str).erase(pos, 1);
        pos = (*str).find(target);
    }
}

bool validateArgs(std::string args)
{
    for (size_t i = 0; i < args.size() - 1; i++)
    {
        if ((args[i] == ' ' && args[i + 1] == ' '))
            return (false);
    }
    std::string *dd = ft_split(args, ' ');

    for (int i = 0; !dd[i].empty(); i++)
    {
        if (dd[i].size() > 2)
            return (delete[] dd, false);
        for (size_t j = 0; j < dd[i].size(); j++)
        {
            if (!isdigit(dd[i][j]) && dd[i][j] != ' ' && dd[i][j] != '+' && dd[i][j] != '-' && dd[i][j] != '*' && dd[i][j] != '/')
                return (delete[] dd, false);
            if (isdigit(dd[i][1]) && (dd[i][0] != '-' && dd[i][0] != '+'))
                return (delete[] dd, false);
        }
    }
    
    return (delete[] dd, true);
}

int doOp(int a, int b, std::string element)
{
    if (element[0] == '+')
        return (a + b);
    if (element[0] == '-')
        return (a - b);
    if (element[0] == '/' && b > 0)
        return (a / b);
    else
        return (a * b);
}

void performRPN(std::string args)
{
    std::string *dd = ft_split(args, ' ');
    size_t count = 0;
    while (!dd[count].empty())
        count++;
    std::stack<int> opStack;
    for (size_t i = 0; i < count; i++)
    {
        std::string element = dd[i];
        if ( element.size() == 1 && (element[0] == '+' || element[0] == '*' || element[0] == '-' || element[0] == '/'))
        {
            if (opStack.size() < 2)
                delete[] dd, throw std::runtime_error("Error");
            int b = opStack.top();
            opStack.pop();
            int a  = opStack.top();
            opStack.pop();
            opStack.push(doOp(a, b, element));
        }
        else
            opStack.push(atoi(element.c_str()));
    }
    delete[] dd;
    if (opStack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << opStack.top() << std::endl;
}