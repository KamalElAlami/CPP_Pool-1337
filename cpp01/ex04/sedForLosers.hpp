#ifndef SEDFORLOSERS_HPP
#define SEDFORLOSERS_HPP


#include <iostream>
#include <fstream>


class Replace
{
	private :
		std::string infile;
		std::string outfile;
		std::string str1;
		std::string str2;
	public :
		Replace(std::string s1, std::string s2, std::string file);
		void giga_sed();
		std::string findAndReplace(std::string line, std::string word);
};

#endif