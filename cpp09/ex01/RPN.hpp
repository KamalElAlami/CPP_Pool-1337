#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <stack>

std::string* ft_split(const std::string& str, char c);
void eraseFromString(std::string* str, char target);
bool validateArgs(std::string args);
int doOp(int a, int b, std::string element);
void performRPN(std::string args);

#endif