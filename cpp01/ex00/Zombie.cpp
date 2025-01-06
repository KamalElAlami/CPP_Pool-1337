#include "Zombie.hpp"

Zombie::Zombie(string n)
{
	name = n;
}

void Zombie::announce(void)
{
	cout << name << " : BraiiiiiiinnnzzzZ..." << endl; 
}
