#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("Unknown")
{
}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.target)
{
}
PresidentialPardonForm::~PresidentialPardonForm()
{
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}
const std::string& PresidentialPardonForm::getTarget(void) const
{
	return (target);
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}