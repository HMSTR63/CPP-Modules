#include "HumanA.hpp"

void HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->wp.getType() << '\n';
}

HumanA::HumanA(std::string name, Weapon &wp) : wp(wp)
{
    this->name = name;
}