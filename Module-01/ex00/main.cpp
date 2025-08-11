#include "Zombie.hpp"

int main()
{
	std::cout << "stack Zombie" << '\n';
	randomChump("stackz");

	Zombie *heapz = newZombie("heapz");
	heapz->announce();
	delete heapz;
}