#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
	private:
		const std::string name;
		bool isSigned;
		const int  reGrade;
		const int  exeGrade;
	public:
		AForm();
		AForm(const std::string nm, int rGrade, int eGrade);
		~AForm();
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		const std::string& getName(void) const;
		const bool& getSign(void) const;
		const int& getReGrade(void) const;
		const int& getExeGrade(void) const;
		void beSigned(const Bureaucrat& obj);
		class GradeTooHighException : public std::exception
		{
			const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);

#endif