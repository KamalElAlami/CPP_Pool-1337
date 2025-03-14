#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    // Basic polymorphism test
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;
    
    i->makeSound(); // Will output cat sound
    j->makeSound(); // Will output dog sound
    meta->makeSound(); // Will output animal sound
    
    // Wrong polymorphism test
    const WrongAnimal* wrong_animal = new WrongAnimal();
    const WrongAnimal* wrong_cat = new WrongCat();
    
    wrong_cat->makeSound(); // Will output WrongAnimal sound, not WrongCat
    
    // Cleanup
    delete meta;
    delete j;
    delete i;
    delete wrong_animal;
    delete wrong_cat;
    
    return 0;
}