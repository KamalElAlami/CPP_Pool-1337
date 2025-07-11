#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class AForm;

class Bureaucrat
{
	private :
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string bname, int bgrade);
		Bureaucrat(const Bureaucrat& obj);
		~Bureaucrat();
		Bureaucrat& operator=(const Bureaucrat& obj);
		const std::string& getName(void) const;
		const int& getGrade(void) const;
		void gradeIncrement(void);
		void gradeDecrement(void);
		class GradeTooHighException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public :
				const char* what() const throw();
		};
		void signForm(AForm &form);
		void executeForm(AForm const & form);

};
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);



#endif