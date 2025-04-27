#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int  reGrade;
		const int  exeGrade;
	public:
		//constructors
		Form();
		Form(const std::string nm, int rGrade, int eGrade);
		~Form();
		Form(const Form& obj);
		Form& operator=(const Form& obj);

		//getters
		const std::string& getName(void) const;
		const bool& getSign(void) const;
		const int& getReGrade(void) const;
		const int& getExeGrade(void) const;
		//methods
		void beSigned(const Bureaucrat& obj);
		// exceptions 
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);

#endif