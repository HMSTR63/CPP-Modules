#include "Zombie.hpp"

int main()
{
    int N = 5;
    Zombie *zombie = zombieHorde(N, "HMSTR");
    if (!zombie)
    {
        std::cerr << "Failed to create zombie horde." << std::endl;
        return 1;
    }
    int h = 0;
    while (h < N)
    {
        zombie[h].announce();
        h++;
    }
    delete[] zombie;
    return 0;
}