#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("Unknown")
{
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target)
{
}
RobotomyRequestForm::~RobotomyRequestForm()
{
}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this != &obj)
	{
		this->target = obj.target;
	}
	return (*this);
}
const std::string& RobotomyRequestForm::getTarget(void) const
{
	return (target);
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
    int raNum;
    srand(time(NULL));

    raNum = rand();
    if (executor.getGrade() > this->getExeGrade())
        throw AForm::GradeTooLowException();
    else if (!getSign())
		throw AForm::FormNotSignedException();
    std::cout << "* DRILLING NOISES *" << std::endl;
    if (raNum % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else 
        std::cout << "Robotomy failed on " << target << "." << std::endl;

}