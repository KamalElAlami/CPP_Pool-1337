#include "iostream"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"


class Intern
{
    public:
        Intern();
        Intern(const Intern& obj);
        ~Intern();
        Intern& operator=(const Intern& obj);
        AForm* makeForm(const std::string& formName, const std::string& target);

        class FormNotFoundException : public std::exception
        {
            public:
                const char* what() const throw();
        };
};