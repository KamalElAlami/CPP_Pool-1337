#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    // const Animal* meta = new Animal();
    
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    Animal *originalDog = new Dog("Doggy");
    Animal *copyDog = new Dog (*(Dog *)originalDog);

    std::cout << "Original address: " << originalDog << std::endl;
    std::cout << "Copy address: " << copyDog << std::endl;
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    
    i->makeSound();
    j->makeSound();
    copyDog->makeSound();
    
    delete j;
    delete i;
    delete copyDog;
    delete originalDog;
    
    return 0;
}