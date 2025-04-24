#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Unknown"), beSigned(false), reGrade(1), exeGrade(1)
{
}
Form::Form(const std::string nm, int rGrade, int eGrade) : name(nm), beSigned(false), reGrade(rGrade), exeGrade(eGrade)
{
    if (rGrade < 1 || eGrade < 1)
        throw GradeTooHighException();
    if (rGrade > 150 || eGrade > 150)
        throw GradeTooLowException();
}
Form::~Form()
{
}
Form& Form::operator=(const Form& obj)
{
    if (this != &obj)
    {
        this->beSigned = obj.beSigned;
    }
    return (*this);
}

Form::Form(const Form& obj) : name(obj.name), beSigned(obj.beSigned), reGrade(obj.reGrade), exeGrade(obj.exeGrade)
{
}

const std::string& Form::getName(void) const
{
    return (name);
}
const bool& Form::getSign(void) const
{
    return (beSigned);
}
const int& Form::getReGrade(void) const
{
    return (reGrade);
}
const int& Form::getExeGrade(void) const
{
    return (exeGrade);
}
void Form::isSignable(const Bureaucrat& obj)
{
    if (obj.getGrade() <= reGrade)
        beSigned = true;
    else
        throw GradeTooLowException();  
}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("GradeTooHighException");
}
const char* Form::GradeTooLowException::what() const throw()
{
    return ("GradeTooLowException");
}