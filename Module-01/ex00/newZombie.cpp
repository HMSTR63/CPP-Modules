#include "Zombie.hpp"

Zombie *newZombie(std::string name)
{
    Zombie *new_Zombie = new Zombie(name);
    if (!new_Zombie)
        return NULL;
    return new_Zombie;
}