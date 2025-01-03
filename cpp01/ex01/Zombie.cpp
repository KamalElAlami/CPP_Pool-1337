#include "Zombie.hpp"

Zombie::Zombie()
{
	// name = n;
}
void Zombie::set_name(string n)
{
	name = n;
}

void Zombie::announce(void)
{
	cout << name << " : BraiiiiiiinnnzzzZ..." << endl; 
}
