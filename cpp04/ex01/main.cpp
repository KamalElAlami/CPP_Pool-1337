#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "========== TESTING ANIMAL ARRAY ==========" << std::endl;
    
    // Create an array of Animal objects (half Dog, half Cat)
    const int count = 6;
    Animal* animals[count];
    
    // Fill the array
    for (int i = 0; i < count; i++)
    {
        if (i < count / 2)
        {
            std::cout << "\nCreating Dog #" << i << std::endl;
            animals[i] = new Dog();
        }
        else
        {
            std::cout << "\nCreating Cat #" << i - count / 2 << std::endl;
            animals[i] = new Cat();
        }
    }
    
    // Make the animals make sounds to verify polymorphism
    std::cout << "\n========== ANIMAL SOUNDS ==========" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "Animal #" << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    // Delete all animals
    std::cout << "\n========== CLEANING ANIMAL ARRAY ==========" << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << "\nDeleting Animal #" << i << " (" << animals[i]->getType() << ")" << std::endl;
        delete animals[i];
    }
    
    // Test deep copy for Dog
    std::cout << "\n========== TESTING DEEP COPY (DOG) ==========" << std::endl;
    
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1);  // Copy constructor test
    
    std::cout << "\nDeleting original dog" << std::endl;
    delete dog1;
    
    std::cout << "\nMaking copied dog bark (should work if deep copy was successful)" << std::endl;
    dog2->makeSound();
    
    std::cout << "\nDeleting copied dog" << std::endl;
    delete dog2;
    
    // Test deep copy for Cat
    std::cout << "\n========== TESTING DEEP COPY (CAT) ==========" << std::endl;
    
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat(*cat1);  // Copy constructor test
    
    std::cout << "\nDeleting original cat" << std::endl;
    delete cat1;
    
    std::cout << "\nMaking copied cat meow (should work if deep copy was successful)" << std::endl;
    cat2->makeSound();
    
    std::cout << "\nDeleting copied cat" << std::endl;
    delete cat2;
    
    // Test assignment operator (deep copy)
    std::cout << "\n========== TESTING ASSIGNMENT OPERATOR ==========" << std::endl;
    
    Cat* cat3 = new Cat();
    Cat* cat4 = new Cat();
    
    std::cout << "\nAssigning cat4 = cat3" << std::endl;
    *cat4 = *cat3;
    
    std::cout << "\nDeleting original cat" << std::endl;
    delete cat3;
    
    std::cout << "\nMaking assigned cat meow (should work if deep copy was successful)" << std::endl;
    cat4->makeSound();
    
    std::cout << "\nDeleting assigned cat" << std::endl;
    delete cat4;
    
    // Uncomment for memory leak testing
    std::cout << "\n========== PRESS ENTER TO EXIT ==========" << std::endl;
    std::cin.get();
    
    return 0;
}