#include "BitcoinExchange.hpp"

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

void bitcoinExchange::eraseFromString(std::string* str)
{
    if ((*str)[0] == ' ')
        (*str).erase(0, 1);
    if ((*str)[(*str).size() - 1] == ' ')
        (*str).erase((*str).size() - 1, 1);
}
void bitcoinExchange::eraseFromString(std::string* str, char target)
{
    std::string::size_type pos = (*str).find(target);
    while (pos != std::string::npos)
    {
        (*str).erase(pos, 1);
        pos = (*str).find(target);
    }
}