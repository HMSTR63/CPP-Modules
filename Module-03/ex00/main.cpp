#include "ClapTrap.hpp"

int main()
{
    std::cout << "========= ROUND START: OREGON - BASEMENT =========\n" << std::endl;

    ClapTrap ash("Ash");
    ClapTrap kapkan("Kapkan");
    std::cout << std::endl;

    std::cout << "--- PREP PHASE ---" << std::endl;
    ash.attack("a soft wall");
    kapkan.attack("a doorway");
    kapkan.attack("another doorway");
    std::cout << std::endl;

    std::cout << "--- ACTION PHASE: 1v1 ENGAGEMENT ---" << std::endl;
    ash.attack("Kapkan");
    kapkan.attack("Ash");
    std::cout << std::endl;

    std::cout << "--- Ash gets flanked by a roamer! ---" << std::endl;
    ash.takeDamage(7);
    std::cout << std::endl;

    std::cout << "--- Ash is low, tries to find cover and heal ---" << std::endl;
    ash.beRepaired(2);
    std::cout << std::endl;

    std::cout << "--- Ash runs through a doorway... it's a trap! ---" << std::endl;
    ash.takeDamage(5);
    std::cout << std::endl;

    std::cout << "--- Ash is down! ---" << std::endl;
    ash.attack("Kapkan");
    ash.beRepaired(10);
    std::cout << std::endl;

    std::cout << "--- DEFENDERS WIN ---" << std::endl;
    kapkan.beRepaired(1);
    std::cout << std::endl;

    std::cout << "========= END OF MATCH =========\n" << std::endl;
    return 0;
}