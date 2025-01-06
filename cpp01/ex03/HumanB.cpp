#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	pName = name;
}

void HumanB::take_weapon(Weapon& weap)
{
	weaponB = &weap;
}

void HumanB::attack(void)
{
	std::cout << pName << " attacks with their " << weaponB->getType() << std::endl;
}