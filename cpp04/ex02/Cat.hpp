#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* cerveau;
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