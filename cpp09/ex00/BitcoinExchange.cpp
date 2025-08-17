#include "BitcoinExchange.hpp"

static bool validate_date(std::string date)
{
    size_t start = 0, end = 0, counter = 0;
    std::string datee[3];
    while ((end = date.find('-', start)) != std::string::npos)
    {
        datee[counter] = date.substr(start, end - start);
        start = end + 1;
        counter += 1;
    }
    datee[counter] = date.substr(start);
    for (int i  = 0; i < 3; i++)
        std::cout << datee[i] << std::endl;
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
        validate_date(line);
    }
}