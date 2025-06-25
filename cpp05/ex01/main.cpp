#include "Bureaucrat.hpp"
#include "Form.hpp"
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
        std::cout << "=== Signing Normal Test ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("Lm9adem", 40);
            Form obj2 = Form("Promotion", 39, 20);
            obj1.gradeIncrement();
            obj2.beSigned(obj1);
            std::cout << obj2 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== Signing struggled Test ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("Lm9adem", 40);
            Form obj2 = Form("Promotion", 39, 20);
            obj2.beSigned(obj1);
            std::cout << obj2 << std::endl;
        }
        catch (const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << "=== Other Tests ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 8);
            Bureaucrat obj2 = obj1;
            Bureaucrat obj3 = Bureaucrat(obj1);
            Form obj4 = Form("simple form", 10, 20);
            Form obj5 = obj4;
            Form obj6 = Form(obj4);
            std::cout << obj1.getName() << std::endl; 
            std::cout << obj2.getName() << std::endl; 
            std::cout << obj3.getName() << std::endl;
            std::cout << obj4.getName() << std::endl; 
            std::cout << obj5.getName() << std::endl; 
            std::cout << obj6.getName() << std::endl; 
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
    std::cout << "=== signForm() Test ===" << std::endl;
        try {
            Bureaucrat boss("Boss", 30);
            Form contract("Contract", 35, 20);
            
            boss.signForm(contract);  // Should work
            std::cout << contract << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}