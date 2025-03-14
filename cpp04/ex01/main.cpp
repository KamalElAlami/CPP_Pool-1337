#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // Test Array of Animals
    const int count = 4;
    Animal* animals[count];
    
    // Fill array (half dogs, half cats)
    for (int i = 0; i < count; i++)
    {
        if (i < count / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    
    // Delete all animals
    for (int i = 0; i < count; i++)
        delete animals[i];
    
    // Test deep copy
    Dog* dog1 = new Dog();
    Dog* dog2 = new Dog(*dog1);
    
    // Delete original - should not affect the copy
    delete dog1;
    
    // Copy should still work
    dog2->makeSound();
    
    delete dog2;
    
    return 0;
}