#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "--------- BASIC ANIMAL TESTS ---------\n" << std::endl;
    
    // Test 1: Base Animal class
    std::cout << "Creating a base Animal:" << std::endl;
    const Animal* meta = new Animal();
    std::cout << "Type: " << meta->getType() << std::endl;
    std::cout << "Sound: ";
    meta->makeSound();
    std::cout << std::endl;
    
    // Test 2: Dog class (polymorphism)
    std::cout << "Creating a Dog through Animal pointer:" << std::endl;
    const Animal* dog = new Dog();
    std::cout << "Type: " << dog->getType() << std::endl;
    std::cout << "Sound: ";
    dog->makeSound();
    std::cout << std::endl;
    
    // Test 3: Cat class (polymorphism)
    std::cout << "Creating a Cat through Animal pointer:" << std::endl;
    const Animal* cat = new Cat();
    std::cout << "Type: " << cat->getType() << std::endl;
    std::cout << "Sound: ";
    cat->makeSound();
    std::cout << std::endl;
    
    // Test 4: Direct Dog instantiation
    std::cout << "Creating a Dog directly:" << std::endl;
    const Dog directDog;
    std::cout << "Type: " << directDog.getType() << std::endl;
    std::cout << "Sound: ";
    directDog.makeSound();
    std::cout << std::endl;
    
    // Test 5: Direct Cat instantiation
    std::cout << "Creating a Cat directly:" << std::endl;
    const Cat directCat;
    std::cout << "Type: " << directCat.getType() << std::endl;
    std::cout << "Sound: ";
    directCat.makeSound();
    std::cout << std::endl;
    
    std::cout << "\n--------- WRONG ANIMAL TESTS (non-polymorphic) ---------\n" << std::endl;
    
    // Test 6: Base WrongAnimal class
    std::cout << "Creating a base WrongAnimal:" << std::endl;
    const WrongAnimal* wrongMeta = new WrongAnimal();
    std::cout << "Type: " << wrongMeta->getType() << std::endl;
    std::cout << "Sound: ";
    wrongMeta->makeSound();
    std::cout << std::endl;
    
    // Test 7: WrongCat through WrongAnimal pointer (NO polymorphism)
    std::cout << "Creating a WrongCat through WrongAnimal pointer:" << std::endl;
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << "Type: " << wrongCat->getType() << std::endl;
    std::cout << "Sound: ";
    wrongCat->makeSound(); // This will call WrongAnimal::makeSound() since it's not virtual!
    std::cout << std::endl;
    
    // Test 8: Direct WrongCat instantiation
    std::cout << "Creating a WrongCat directly:" << std::endl;
    const WrongCat directWrongCat;
    std::cout << "Type: " << directWrongCat.getType() << std::endl;
    std::cout << "Sound: ";
    directWrongCat.makeSound(); // This will call WrongCat::makeSound() since we use the exact type
    std::cout << std::endl;
    
    // Clean up memory
    std::cout << "\n--------- CLEANING UP MEMORY ---------\n" << std::endl;
    delete meta;
    delete dog;
    delete cat;
    delete wrongMeta;
    delete wrongCat;
    
    return 0;
}