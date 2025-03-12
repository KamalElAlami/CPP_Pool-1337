#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Wrong Animal")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}
WrongAnimal::WrongAnimal(std::string ttype) : type(ttype)
{
	std::cout << "WrongAnimal Parametrized constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = obj;
}
std::string WrongAnimal::getType(void) const
{
	return (type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Say Cheese" << std::endl;
}
