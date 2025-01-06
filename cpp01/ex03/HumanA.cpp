#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weap)
	: pName(name),
	weaponA(weap)
{
}

void HumanA::attack(void)
{
	std::cout << pName << " attacks with their " << weaponA.getType() << std::endl;
}