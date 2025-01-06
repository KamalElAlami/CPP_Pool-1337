#include "HumanB.hpp"

HumanB::HumanB(std::string name):
 pName(name),
 weaponB(NULL)
{}

void HumanB::take_weapon(Weapon& weap)
{
	weaponB = &weap;
}

void HumanB::attack(void)
{
	if (weaponB)
		std::cout << pName << " attacks with their " << weaponB->getType() << std::endl;
	else
	 	std::cout << pName << " has no weapon meskin " << std::endl;
}