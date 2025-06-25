#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "=== TESTING BUREAUCRAT CLASS ===" << std::endl;
    {    
      std::cout << "=== NORMAL TEST ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 8);
            std::cout << obj1.getGrade() << std::endl;
            obj1.gradeDecrement();
            std::cout << obj1.getGrade() << std::endl;
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            std::cout << obj1.getGrade() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== THROW GRADE TOO HIGH ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 8);
            std::cout << obj1.getGrade() << std::endl;
            obj1.gradeDecrement();
            std::cout << obj1.getGrade() << std::endl;
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            obj1.gradeIncrement();
            std::cout << obj1.getGrade() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== THROW GRADE TOO LOW ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 142);
            std::cout << obj1.getGrade() << std::endl;
            obj1.gradeDecrement();
            std::cout << obj1.getGrade() << std::endl;
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            obj1.gradeDecrement();
            std::cout << obj1.getGrade() << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== Test shrub ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 8);
            ShrubberyCreationForm obj2 = ShrubberyCreationForm("jerda");
            obj1.signForm(obj2);
            obj2.execute(obj1);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== Test Pardon ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 5);
            PresidentialPardonForm obj2 = PresidentialPardonForm("something");
            obj1.signForm(obj2);
            obj2.execute(obj1);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== Test Robotomy ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 8);
            RobotomyRequestForm obj2 = RobotomyRequestForm("something");
            obj1.signForm(obj2);
            obj2.execute(obj1);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}