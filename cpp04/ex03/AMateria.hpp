#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string spell);
		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria& obj);
		virtual ~AMateria();
		std::string const &getType() const;
		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target) const;
};



#endif