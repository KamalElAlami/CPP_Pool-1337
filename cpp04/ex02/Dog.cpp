#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called" << std::endl;
	cerveau = new Brain();
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete cerveau;
}
Dog::Dog(std::string ttype) : Animal(ttype)
{
	std::cout << "Dog Parametrized constructor called" << std::endl;
	cerveau = new Brain();
}

Dog& Dog::operator=(const Dog &obj)
{
	if (this != &obj)
	{
		type = obj.type;
		delete this->cerveau;
		this->cerveau = new Brain(*(obj.cerveau));
	}
	return (*this);
}

Dog::Dog(const Dog &obj) : Animal()
{
	std::cout << "Dog Copy constructor called" << std::endl;
	cerveau = NULL;
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
