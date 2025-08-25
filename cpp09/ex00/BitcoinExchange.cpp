#include "BitcoinExchange.hpp"

static std::string to_string_no_sci(double x, int prec) {
    std::ostringstream oss;
    oss.setf(std::ios::fixed, std::ios::floatfield);
    oss << std::setprecision(prec) << x;
    std::string s = oss.str();
    std::string::size_type p = s.find('.');
    if (p != std::string::npos) {
        while (!s.empty() && s[s.size()-1] == '0')
            s.erase(s.size()-1);
        if (!s.empty() && s[s.size()-1] == '.')
            s.erase(s.size()-1);
    }
    return s;
}

bool isLeap(int year, int month, int day)
{
    bool leap = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
    int months[] = {31, (leap) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (months[month - 1] < day)
        return (false);
    return (true);
}

static bool validateDate(std::string date)
{
    int count = 0;
    std::string *splited = ft_split(date, '-');
    while (!splited[count].empty())
        count++;
    if (count != 3)
        return (delete[] splited, false);
    for (int i = 0; !splited[i].empty(); i++)
        for (int j = 0; splited[i][j]; j++)
            if (!isdigit(splited[i][j]))
                return (delete[] splited, false);
    if (strtod(splited[0].c_str(), NULL) > INT_MAX || atoi(splited[1].c_str()) < 1 || atoi(splited[1].c_str()) > 12 || atoi(splited[2].c_str()) < 1 || atoi(splited[2].c_str()) > 31)
        return (delete[] splited, false);
    if (atoi(splited[0].c_str()) < 2009 || (atoi(splited[0].c_str()) == 2009 && atoi(splited[2].c_str()) < 2) || !isLeap(atoi(splited[0].c_str()), atoi(splited[1].c_str()), atoi(splited[2].c_str())))
    {
        delete[] splited;
        throw std::runtime_error("Error: date is invalid");
    }
    return (delete[] splited, true);
}
static bool validateValue(std::string value)
{
    char* track = NULL;
    double newVal = strtod(value.c_str(), &track);
    if (*track != '\0')
        throw std::runtime_error("Error: value is not a number.");
    if (newVal > INT_MAX || newVal > 1000)
            throw std::runtime_error("Error: too large a number.");
    if (newVal < 0 )
            throw std::runtime_error("Error: not a positive number.");
    return (true);
}

bitcoinExchange::bitcoinExchange(std::string file)
{
    rFile.open(file.c_str());
    if (!rFile.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::fstream dFile("data.csv");
    if (!dFile.is_open())
        throw std::runtime_error("Error: could not open database file.");
    std::string line;
    while (getline(dFile, line))
    {
        std::string *splited = ft_split(line, ',');
        if (splited[0] == "date")
        {
            delete[] splited;
            continue;
        }
        eraseFromString(&splited[0], '-');
        Data.insert(std::make_pair(atoi(splited[0].c_str()), strtod(splited[1].c_str(), NULL)));
        delete[] splited;
    }
    dFile.close();
}
bool validateLineSyntax(std::string str)
{
    int count = 0;
    std::string::size_type pos = str.find(" | ");
    while ((pos = str.find(" | ", pos)) != std::string::npos)
        count++, pos++;
    if (count != 1)
        return (false);
    return (true);
}
void bitcoinExchange::run()
{
    std::string line;
    while (getline(rFile, line))
    {
        std::string *splited = ft_split(line, '|');
        eraseFromString(&splited[0], ' ');
        eraseFromString(&splited[1], ' ');
        if (splited[0] == "date")
        {
            delete[] splited;
            continue;
        }
        try{
            if (!validateLineSyntax(line))
                throw std::runtime_error("Error: invalid delimiter syntax");
            if (!validateDate(splited[0]))
                throw std::runtime_error("Error: bad input => " + splited[0]);
            if (validateValue(splited[1]))
            {
                std::string formatedDate = splited[0];
                eraseFromString(&splited[0], '-');
                unsigned long long int searchDate = atoi(splited[0].c_str());
                std::map<unsigned long long int, double>::iterator it = Data.lower_bound(searchDate); 
                if (it->first != searchDate && it != Data.begin())
                    --it; 
                double res = strtod(splited[1].c_str(), NULL) * it->second;
                std::cout << formatedDate << " => " << splited[1] << " = " << to_string_no_sci(res, 6) << std::endl;

                delete[] splited;
            }
        }
        catch (const std::runtime_error &e)
        {
            delete[] splited;
            std::cout << e.what() << std::endl;
        }
    }
}

bitcoinExchange::~bitcoinExchange()
{
    rFile.close();
}
