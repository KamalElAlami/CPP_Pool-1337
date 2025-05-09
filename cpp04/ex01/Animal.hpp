#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string ttype);
		Animal(const Animal &obj);
		Animal& operator=(const Animal &obj);
		std::string getType(void) const;
		virtual ~Animal();
		virtual void makeSound(void) const;
};

#endif