#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap& operator=(const ScavTrap& obj);
		ScavTrap(const ScavTrap& obj);
		~ScavTrap();
		void guardGate(void);
		void attack(const std::string& target);
};

#endif