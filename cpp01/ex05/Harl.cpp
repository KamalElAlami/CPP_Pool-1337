#include "Harl.hpp"

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

static std::string strToLower(std::string str)
{
	for (size_t i = 0; i <= str.length(); i++)
		str[i] = (char)std::tolower(str[i]);
	return(str);
}

static t_Levels getLevel(std::string level)
{
	level = strToLower(level);
	std::string lvls[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i < 4; i++)
		if (!level.compare(lvls[i]))
			return ((t_Levels)i);
		return (INVALID);
}

void Harl::complain(std::string level)
{
	switch (getLevel(level))
	{
		case DEBUG :
			debug();
			break ;
		case INFO :
			info();
			break ;
		case WARNING :
			warning();
			break ;
		case ERROR :
			error();
			break ;
		default :
			std::cout << "Invalid Choice Try Again" << std::endl;
			break ;
	}
}