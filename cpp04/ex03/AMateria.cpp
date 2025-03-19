#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : type("The Void")
{
}
AMateria::AMateria(std::string spell) : type(spell)
{
}

AMateria::~AMateria()
{
}

AMateria& AMateria::operator=(const AMateria &obj)
{
	if (this != &obj)
		type = obj.type;
	return (*this);
}

AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
}

void AMateria::use(ICharacter& target) const
{
	std::cout << "* you're trying to attack from A Materia " << target.getName() << " *" << std::endl;
}

std::string const& AMateria::getType() const
{
	return (type);
}