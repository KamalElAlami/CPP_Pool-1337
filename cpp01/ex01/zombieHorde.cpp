#include "Zombie.hpp"

Zombie* zombieHorde(int N, string name)
{
	Zombie *obj = new Zombie[N];

	if (name.empty())
		name = "kael-ala";
	for (int i = 0; i < N; i++)
		obj[i].set_name(name);
	return (obj);
}