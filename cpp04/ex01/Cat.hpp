#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(std::string ttype);
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat();
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif