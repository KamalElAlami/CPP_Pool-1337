#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}
Animal::Animal(std::string ttype) : type(ttype)
{
	std::cout << "Animal Parametrized constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = obj;
}
std::string Animal::getType(void) const
{
	return (type);
}
