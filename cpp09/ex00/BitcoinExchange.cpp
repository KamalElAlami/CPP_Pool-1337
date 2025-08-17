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

static bool validate_date(std::string date)
{
    std::string 
    return (true);
}

bitcoinExchange::bitcoinExchange(std::string file)
{
    rFile.open(file);
    if (!rFile.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::fstream dFile("data.csv");
    if (!dFile.is_open())
        throw std::runtime_error("Error: could not open database file.");
    std::string line;
    while (getline(dFile, line))
    {
        std::string *splited = ft_split(line, ',');
        validate_date(splited[0]);
    }
}