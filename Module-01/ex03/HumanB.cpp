#include "HumanB.hpp"

HumanB::HumanB(std::string name) { this->name = name; }

void HumanB::setWeapon(Weapon &wp) { this->wp = &wp; }

void HumanB::attack() {
  std::cout << this->name << " attacks with their " << this->wp->getType()
            << '\n';
}
