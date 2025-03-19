#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat(std::string ttype) : WrongAnimal(ttype)
{
	std::cout << "WrongCat Parametrized constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = obj;
}
std::string WrongCat::getType(void) const
{
	return (type);
}
void WrongCat::makeSound(void) const
{
	std::cout << "BechBech" << std::endl;
}
