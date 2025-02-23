#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}
ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Parametrized constructor called" << std::endl;
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
}
ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
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
ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	*this = obj;
}
ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}
void ScavTrap:: guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints && hitPoints)
	{
		energyPoints--;
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
	else
		std::cout << "You Have No Energy or Hit Points Left" << std::endl;
}