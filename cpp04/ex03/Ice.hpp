#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &obj);
		Ice& operator=(const Ice& obj);
		~Ice();
		AMateria* clone(void) const;
		void use(ICharacter& target) const;
};


#endif