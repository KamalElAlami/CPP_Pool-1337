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
        std::map<std::string, double> Data;
        std::fstream rFile;
    public :
        bitcoinExchange(std::string file);
};

#endif