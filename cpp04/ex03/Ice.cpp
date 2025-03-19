#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{
}

Ice::~Ice()
{
}

Ice& Ice::operator=(const Ice &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Ice::Ice(const Ice &obj) : AMateria("ice")
{
	*this = obj;
}

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) const
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}