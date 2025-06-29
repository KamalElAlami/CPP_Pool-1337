#include "Bureaucrat.hpp"
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
        std::cout << "=== Other Tests ===" << std::endl;
        try {
            Bureaucrat obj1 = Bureaucrat("L9ayeed", 8);
            Bureaucrat obj2 = obj1;
            Bureaucrat obj3 = Bureaucrat(obj1);
            std::cout << obj1.getName() << std::endl; 
            std::cout << obj2.getName() << std::endl; 
            std::cout << obj3.getName() << std::endl; 
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
    std::cout << "=== OPERATOR<< TEST ===" << std::endl;
    try {
        Bureaucrat obj1("Hassan", 42);
        std::cout << obj1;  // Should print: Hassan, bureaucrat grade 42
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
}