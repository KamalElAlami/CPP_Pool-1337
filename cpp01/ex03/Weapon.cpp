#include "Weapon.hpp"

Weapon::Weapon(std::string Weapon)
{
	type = Weapon;
}

const std::string& Weapon::getType(void)
{
	return (type);
}
void Weapon::setType(std::string weap)
{
	type = weap;
}
