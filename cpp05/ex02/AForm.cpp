#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Unknown"), isSigned(false), reGrade(1), exeGrade(1)
{
}
AForm::AForm(const std::string nm, int rGrade, int eGrade) : name(nm), isSigned(false), reGrade(rGrade), exeGrade(eGrade)
{
    if (rGrade < 1 || eGrade < 1)
        throw GradeTooHighException();
    if (rGrade > 150 || eGrade > 150)
        throw GradeTooLowException();
}
AForm::~AForm()
{
}
AForm& AForm::operator=(const AForm& obj)
{
    if (this != &obj)
    {
        this->isSigned = obj.isSigned;
    }
    return (*this);
}

AForm::AForm(const AForm& obj) : name(obj.name), isSigned(obj.isSigned), reGrade(obj.reGrade), exeGrade(obj.exeGrade)
{
}

const std::string& AForm::getName(void) const
{
    return (name);
}
const bool& AForm::getSign(void) const
{
    return (isSigned);
}
const int& AForm::getReGrade(void) const
{
    return (reGrade);
}
const int& AForm::getExeGrade(void) const
{
    return (exeGrade);
}
void AForm::beSigned(const Bureaucrat& obj)
{
    if (obj.getGrade() <= reGrade)
        isSigned = true;
    else
        throw GradeTooLowException();  
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException");
}
const char* AForm::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException");
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << obj.getName() << " Grade To Sign, " << obj.getReGrade() << " Grade To Execute, "
        << obj.getExeGrade() << " Signed : " << obj.getSign() <<   std::endl;
	return (out);
}