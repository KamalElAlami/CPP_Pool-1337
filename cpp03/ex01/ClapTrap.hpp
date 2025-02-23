#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string clapName;
		unsigned int hitPoints;
		unsigned int energyPoints;
		unsigned attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& obj);
		~ClapTrap();
		ClapTrap& operator=(const ClapTrap& obj);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;
		void setName(const std::string name);
		void setHitPoints(const unsigned int amount);
		void setEnergyPoints(const unsigned int amount);
		void setAttackDamage(const unsigned int amount);
};

#endif