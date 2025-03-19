#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &obj);
		Cure& operator=(const Cure& obj);
		~Cure();
		AMateria* clone(void) const;
		void use(ICharacter& target) const;
};


#endif