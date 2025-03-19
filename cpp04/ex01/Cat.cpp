#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	cerveau = new Brain();
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete cerveau;
}
Cat::Cat(std::string ttype) : Animal(ttype)
{
	std::cout << "Cat Parametrized constructor called" << std::endl;
	cerveau = new Brain();
}

Cat& Cat::operator=(const Cat &obj)
{
	if (this != &obj)
	{
		type = obj.type;
		delete this->cerveau;
		this->cerveau = new Brain(*(obj.cerveau));
	}
	return (*this);
}

Cat::Cat(const Cat &obj) : Animal()
{
	std::cout << "Cat Copy constructor called" << std::endl;
	this->cerveau = NULL;
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
