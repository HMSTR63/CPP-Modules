#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "A horde of Zombies has ben Born" << '\n';
}

Zombie::~Zombie()
{
    std::cout << "A horde of Zombies has bes destroyed" << '\n';
}

void    Zombie::setZombie(std::string name)
{
    this->name = name;
}

void Zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << '\n';
}
