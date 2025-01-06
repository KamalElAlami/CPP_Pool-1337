#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
using std::cout;
using std::string;
using std::endl;

class Zombie
{
	private :
		string name;
	public :
		Zombie(string n);
		void announce(void);
};

Zombie*	newZombie(string name);
void	randomChump(string name);

#endif