#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::~Cure()
{
}

Cure& Cure::operator=(const Cure &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

Cure::Cure(const Cure &obj) : AMateria("cure")
{
	*this = obj;
}

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) const
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}