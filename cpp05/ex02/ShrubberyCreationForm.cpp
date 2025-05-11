#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Unknown")
{
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), target(obj.target)
{
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}
const std::string& ShrubberyCreationForm::getTarget(void) const
{
	return (target);
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if ()
}