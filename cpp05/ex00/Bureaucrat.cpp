#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unknown"), grade(150)
{
}
Bureaucrat::Bureaucrat(std::string bname, int bgrade) : name(bname)
{
	if (bgrade <= 0)
		throw GradeTooHighException();
	else if (bgrade > 150 )
		throw GradeTooLowException();
	else
		grade = bgrade;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this != &obj)
	{
		this->grade = obj.grade;
	}
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) : name(obj.name), grade(obj.grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

const std::string& Bureaucrat::getName(void) const
{
	return (name);
}
const int& Bureaucrat::getGrade(void) const
{
	return (grade);
}


const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("GradeTooHighException");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("GradeTooLowException");
}

void Bureaucrat::gradeIncrement(void)
{
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}
void Bureaucrat::gradeDecrement(void)
{
	if (grade >= 150 )
		throw GradeTooLowException();
	grade++;
}
std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
	out << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
	return (out);
}