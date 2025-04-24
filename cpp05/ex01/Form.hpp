#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		const bool beSigned;
		const int  reGrade;
		const int  exeGrade;
	public:
		Form();
		~Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		std::string& getName(void) const;
		bool& getSign(void) const;
		int& getReGrade(void) const;
		int& getExeGrade(void) const;
		void isSignable(const Bureaucrat& obj);
};

#endif