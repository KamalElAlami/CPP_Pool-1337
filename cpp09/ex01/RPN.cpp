#include "RPN.hpp"

bool validateArgs(std::string args)
{
    for (size_t i = 0; i < args.size(); i++)
        if (!isdigit(args[i]) && args[i] != ' ' && args[i] != '+' && args[i] != '-' && args[i] != '*' && args[i] != '/')
            return (false);
    return (true);
}

int doOp(int a, int b, std::string element)
{
    if (element[0] == '+')
        return (a + b);
    if (element[0] == '-')
        return (a - b);
    if (element[0] == '*')
        return (a * b);
    else
        return (a / b);
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
            int b = opStack.top();
            opStack.pop();
            int a  = opStack.top();
            opStack.pop();
            opStack.push(doOp(a, b, element));
        }
        else
            opStack.push(atoi(element.c_str()));
    }
    std::cout << opStack.top() << std::endl;
}