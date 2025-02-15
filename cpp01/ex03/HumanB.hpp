#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"


class HumanB
{
	private :
		std::string pName;
		Weapon* weaponB;
	public :
		HumanB(std::string name);
		void setWeapon(Weapon& weap);
		void attack(void);
};


#endif