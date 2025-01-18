#include <iostream>

class heloo
{
	public :
		int i = 10;
		void printadd()
		{
			std::cout << this;
		}
};

int main()
{
	std::string hell = "kamal";
	heloo obj;

	obj.printadd();

	// std::cout << this;
}