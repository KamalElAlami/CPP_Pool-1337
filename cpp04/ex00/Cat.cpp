#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}
Cat::Cat(std::string ttype) : Animal(ttype)
{
	std::cout << "Cat Parametrized constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Cat::Cat(const Cat &obj) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = obj;
}
std::string Cat::getType(void) const
{
	return (type);
}
void Cat::makeSound(void) const
{
	std::cout << "Meooow" << std::endl;
}
