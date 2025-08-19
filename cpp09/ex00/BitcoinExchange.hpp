#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <exception>


class bitcoinExchange
{
    private :
        std::map<long int, double> Data;
        std::fstream rFile;
    public :
        bitcoinExchange(std::string file);
        void run();
};

std::string* ft_split(const std::string& str, char c);
void eraseFromString(std::string* str, char target);

#endif