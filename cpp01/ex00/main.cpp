#include "Zombie.hpp"

int main(void)
{
	Zombie *heap = newZombie("3alal");
	randomChump("Boujem3a");
	heap->announce();
	delete heap;
}
