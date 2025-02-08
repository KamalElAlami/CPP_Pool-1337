#include "Zombie.hpp"

Zombie::Zombie()
{
}
void Zombie::set_name(std::string n)
{
	name = n;
}

void Zombie::announce(void)
{
	std::cout << name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}