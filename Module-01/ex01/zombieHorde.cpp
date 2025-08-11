#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *z = new Zombie[N];
    if (!z)
        return NULL;
    int i = 0;
    while (i < N)
    {
        z[i].setZombie(name);
        i++;
    }
    return z;
}
