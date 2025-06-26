#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& obj) {
    *this = obj;
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern& obj) {
    if (this != &obj) {
    }
    return *this;
}

const char* Intern::FormNotFoundException::what() const throw() {
    return "FormNotFound";
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (formName == forms[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            switch (i)
            {
                case 0 :
                    return (new ShrubberyCreationForm(target));
                case 1 :
                    return (new RobotomyRequestForm(target));
                case 2:
                    return (new PresidentialPardonForm(target));
                    
                }
            }
    }
    throw FormNotFoundException();
}
