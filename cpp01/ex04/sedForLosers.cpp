#include "sedForLosers.hpp"


Replace::Replace(std::string s1, std::string s2, std::string file) :
infile(file),
outfile(file + ".replace"),
str1(s1),
str2(s2)
{
	// if (s1.empty() || s2.empty() || file.empty())
	// 	std::cout << "invalid args" << std::endl;
}

std::string Replace::findAndReplace(std::string line, std::string word)
{

	std::string new_line = line;
	while (new_line.find(str1) != std::string::npos)
		new_line = new_line.substr(0, new_line.find(str1.c_str())) + word + new_line.substr((new_line.find(str1) + str1.length()), new_line.length());
	return (new_line);
}
void Replace::giga_sed(void)
{
	std::string str;
	std::ifstream instream(infile.c_str(), std::ios::in);
	std::ofstream outstream(outfile.c_str(), std::ios::out);
	while (std::getline(instream, str))
	{
		if (str.find(str1) != std::string::npos)
			outstream << findAndReplace(str, str2) << std::endl;
		else
			outstream << str << std::endl;
	}

}