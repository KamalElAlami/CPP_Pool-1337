#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}
Dog::Dog(std::string ttype) : Animal(ttype)
{
	std::cout << "Dog Parametrized constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Dog::Dog(const Dog &obj) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = obj;
}
std::string Dog::getType(void) const
{
	return (type);
}
void Dog::makeSound(void) const
{
	std::cout << "3aaw 3aaw" << std::endl;
}
