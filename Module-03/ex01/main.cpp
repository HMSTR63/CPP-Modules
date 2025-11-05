#include "ScavTrap.hpp"

int main()
{
    std::cout << "========= ROUND START: CONSULATE - GARAGE =========\n" << std::endl;

    ClapTrap recruit("Recruit");
    ScavTrap kapkan("Kapkan");
    std::cout << std::endl;

    std::cout << "--- PREP PHASE ---" << std::endl;
    recruit.attack("a reinforced wall");

    kapkan.attack("a doorway");
    kapkan.attack("a window frame");
    kapkan.guardGate();
    std::cout << std::endl;


    std::cout << "--- ACTION PHASE: RECRUIT RUSH! ---" << std::endl;

    recruit.attack("Kapkan");
    std::cout << "--- Kapkan is unfazed ---" << std::endl;
    
    kapkan.attack("Recruit");

    recruit.takeDamage(20);
    std::cout << std::endl;

    std::cout << "--- Recruit is down! ---" << std::endl;
    recruit.attack("the floor");
    recruit.beRepaired(10);
    std::cout << std::endl;

    std::cout << "--- Kapkan gets hit by Ash ---" << std::endl;
    kapkan.takeDamage(80);
    std::cout << std::endl;

    std::cout << "--- Kapkan is low, tries to heal ---" << std::endl;
    kapkan.beRepaired(10);
    kapkan.beRepaired(10);
    std::cout << std::endl;

    std::cout << "--- Ash pushes! Kapkan is finished! ---" << std::endl;
    kapkan.takeDamage(50);
    kapkan.guardGate();
    std::cout << std::endl;

    std::cout << "========= END OF MATCH: ATTACKERS WIN =========\n" << std::endl;
    return 0;
}