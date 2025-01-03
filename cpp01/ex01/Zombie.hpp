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
		Zombie();
		void announce(void);
		void set_name(string n);
};

Zombie* zombieHorde(int N, string name);

#endif