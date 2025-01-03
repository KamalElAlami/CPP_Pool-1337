#include "Zombie.hpp"

int main(void)
{
		Zombie *heap = zombieHorde(5, "");
		for(int i = 0; i < 5; i++)
			heap[i].announce();
		delete[] heap;
}
