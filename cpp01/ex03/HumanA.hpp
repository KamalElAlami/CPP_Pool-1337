#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"


class HumanA
{
	private :
		std::string pName;
		Weapon& weaponA;
	public :
		HumanA(std::string name, Weapon& weap);
		void attack(void);
};


#endif