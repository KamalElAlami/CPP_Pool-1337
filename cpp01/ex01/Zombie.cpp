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

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *obj = new Zombie[N];

	if (name.empty())
		name = "kael-ala";
	for (int i = 0; i < N; i++)
		obj[i].set_name(name);
	return (obj);
}