#include "Character.hpp"

Character::Character() : name("")
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string n) : name(n)
{
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::~Character()
{
	// for (int i = 0; i < 4; i++)
	// {
	// 	if (inventory[i])
	// 		delete inventory[i];
	// }
}

Character& Character::operator=(const Character &obj)
{
	if (this != &obj)
	{
		this->name = obj.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
			this->inventory[i] = NULL;
			if (obj.inventory[i])
				this->inventory[i] = obj.inventory[i]->clone();
		}
	}
	return (*this);
}

Character::Character(const Character &obj)
{
	for (int i = 0; i < 4; i++)
        this->inventory[i] = NULL;
	*this = obj;
}

std::string const& Character::getName(void) const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (m == inventory[i])
			return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return;
	inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || inventory[idx] == NULL)
		return;
	inventory[idx]->use(target);
}