#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	type = "WrongCat";
}
WrongCat::WrongCat(std::string ttype)
{
	type = ttype;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal()
{
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
