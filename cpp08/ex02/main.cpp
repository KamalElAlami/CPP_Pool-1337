#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    {
        std::cout << "=== Test: Const Iterators ===" << std::endl;
        
        MutantStack<int> mstack;
        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        
        const MutantStack<int>& const_ref = mstack;
        std::cout << "Using const iterators: ";
        for (MutantStack<int>::const_iterator it = const_ref.begin(); it != const_ref.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl << std::endl;
    }
    {
        std::cout << "=== Test: Empty Stack ===" << std::endl;
    
        MutantStack<int> empty_stack;
        std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
        std::cout << "Empty: " << (empty_stack.empty() ? "true" : "false") << std::endl;
        
        // Test iteration on empty stack
        std::cout << "Iteration result: ";
        for (MutantStack<int>::iterator it = empty_stack.begin(); it != empty_stack.end(); ++it) {
            std::cout << *it << " "; // Should not print anything
        }
        std::cout << "(nothing)" << std::endl << std::endl;
    }
    {
         std::cout << "=== Test: String Stack ===" << std::endl;
    
        MutantStack<std::string> string_stack;
        string_stack.push("first");
        string_stack.push("second");
        string_stack.push("third");
        
        std::cout << "Top: " << string_stack.top() << std::endl;
        std::cout << "Contents: ";
        for (MutantStack<std::string>::iterator it = string_stack.begin(); it != string_stack.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        
        string_stack.pop();
        std::cout << "After pop, size: " << string_stack.size() << std::endl;
        std::cout << std::endl;
    }
    return 0;
}