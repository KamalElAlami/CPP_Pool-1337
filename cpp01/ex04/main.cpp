#include "sedForLosers.hpp"

int main(int ac, char **av)
{
	if (ac == 4)
	{
		Replace seed(av[2], av[3], av[1]);
		seed.giga_sed();
	}
	else
		std::cout << "Something is wrong with the Args" << std::endl;
}
