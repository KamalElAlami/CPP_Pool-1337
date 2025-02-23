#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : clapName(""),  hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : clapName(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	    std::cout << "ClapTrap parameterized constructor called for " << clapName << std::endl;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	if (this != &obj)
	{
		clapName = obj.clapName;
		hitPoints = obj.hitPoints;
		energyPoints = obj.energyPoints;
		attackDamage = obj.attackDamage;
	}
	return (*this);
}
ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = obj;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints && hitPoints)
	{
		energyPoints--;
		std::cout << "ClapTrap " << clapName << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	}
	else
		std::cout << "You Have No Energy or Hit Points Left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if ((hitPoints - amount) <= 0 )
		hitPoints = 0;
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << clapName <<" takes " << amount << " damage!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints && hitPoints )
	{
		hitPoints += amount;
		energyPoints--;
		std::cout << "ClapTrap " << clapName << " repairs itself for 1 hit point! " << std::endl;
	}
	else
		std::cout << "You Have No Energy or Hit Points Left" << std::endl;
}