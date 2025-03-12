#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(std::string ttype);
		WrongCat(const WrongCat &obj);
		WrongCat& operator=(const WrongCat &obj);
		std::string getType(void) const;
		void makeSound(void) const;
};

#endif