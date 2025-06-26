#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
    try
    {
        Intern someRandomIntern;
        Bureaucrat obj = Bureaucrat("3arbi", 1);
        AForm* rrf;
        rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
        rrf->beSigned(obj);
        rrf->execute(obj);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}