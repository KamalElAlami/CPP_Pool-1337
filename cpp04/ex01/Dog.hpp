#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(std::string ttype);
		Dog(const Dog &obj);
		~Dog();
		Dog& operator=(const Dog &obj);
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif