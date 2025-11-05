#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "========= ROUND START: HOSTAGE - HOUSE =========\n" << std::endl;

    DiamondTrap ash("Ash");
    ScavTrap    kapkan("Kapkan");
    std::cout << std::endl;

    std::cout << "--- Ash's Identity Check ---" << std::endl;
    ash.whoAmI();
    std::cout << std::endl;

    std::cout << "--- Ash's Abilities (Hybrid) ---" << std::endl;
    ash.guardGate();
    ash.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- FIGHT! ---" << std::endl;

    ash.attack("Kapkan"); 
    kapkan.takeDamage(30);
    std::cout << std::endl;

    kapkan.attack("Ash");
    ash.takeDamage(20);
    std::cout << std::endl;

    ash.attack("Kapkan"); 
    kapkan.takeDamage(30);
    std::cout << std::endl;

    kapkan.attack("Ash");
    ash.takeDamage(20);
    std::cout << std::endl;

    ash.attack("Kapkan"); 
    kapkan.takeDamage(30);
    std::cout << std::endl;

    kapkan.attack("Ash");
    ash.takeDamage(20);
    std::cout << std::endl;

    ash.attack("Kapkan"); 
    kapkan.takeDamage(30);
    std::cout << std::endl;

    std::cout << "--- Kapkan is down! ---" << std::endl;
    kapkan.attack("Ash");
    kapkan.guardGate();
    std::cout << std::endl;

    std::cout << "--- ELITE WINS ---" << std::endl;
    ash.whoAmI();
    std::cout << std::endl;

    std::cout << "========= END OF MATCH =========\n" << std::endl;
}