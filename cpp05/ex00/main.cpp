#include "Bureaucrat.hpp"

int main() {
    std::cout << "=== TESTING BUREAUCRAT CLASS ===" << std::endl;
    
    try {
        std::cout << "\n## Test 1: Creating valid bureaucrat" << std::endl;
        Bureaucrat bob("Bob", 75);
        std::cout << bob << std::endl;  // Test operator
        
        std::cout << "\n## Test 2: Incrementing grade" << std::endl;
        bob.incrementGrade();
        std::cout << "After increment: " << bob << std::endl;
        
        std::cout << "\n## Test 3: Decrementing grade" << std::endl;
        bob.decrementGrade();
        bob.decrementGrade();
        std::cout << "After decrement: " << bob << std::endl;
        
        std::cout << "\n## Test 4: Creating bureaucrat with too high grade" << std::endl;
        Bureaucrat alice("Alice", 0);  // Should throw GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n## Test 5: Creating bureaucrat with too low grade" << std::endl;
        Bureaucrat charlie("Charlie", 151);  // Should throw GradeTooLowException
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n## Test 6: Incrementing at max grade" << std::endl;
        Bureaucrat dave("Dave", 1);
        std::cout << dave << std::endl;
        dave.incrementGrade();  // Should throw GradeTooHighException
    }
    catch (const Bureaucrat::GradeTooHighException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    try {
        std::cout << "\n## Test 7: Decrementing at min grade" << std::endl;
        Bureaucrat eve("Eve", 150);
        std::cout << eve << std::endl;
        eve.decrementGrade();  // Should throw GradeTooLowException
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== TESTS COMPLETED ===" << std::endl;
    
    return 0;
}