#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Parametrized constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setAttackDamage(30);
}
FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
	{
		setName(obj.getName());
		setHitPoints(obj.getHitPoints());
		setEnergyPoints(obj.getEnergyPoints());
		setAttackDamage(obj.getAttackDamage());
	}
	return (*this);
}
FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	*this = obj;
}
FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}
void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap requests a positive high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (energyPoints && hitPoints)
	{
		energyPoints--;
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
		std::cout << "You Have No Energy or Hit Points Left" << std::endl;
}