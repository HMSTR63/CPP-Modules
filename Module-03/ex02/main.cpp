#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "========= ROUND START: HOSTAGE - HOUSE =========\n" << std::endl;
    
    ScavTrap kapkan("Kapkan");
    FragTrap fuze("Fuze");
    std::cout << std::endl;

    std::cout << "--- PREP PHASE ---" << std::endl;
    kapkan.guardGate();
    std::cout << std::endl;

    std::cout << "--- ACTION PHASE: 1v1 ---" << std::endl;

    fuze.attack("the objective room");
    fuze.attack("the objective room");
    fuze.highFivesGuys();
    std::cout << std::endl;

    std::cout << "--- Kapkan ambushes Fuze! ---" << std::endl;
    
    kapkan.attack("Fuze");
    fuze.takeDamage(20);
    std::cout << std::endl;

    fuze.attack("Kapkan");
    kapkan.takeDamage(30);
    std::cout << std::endl;

    std::cout << "--- They trade shots! ---" << std::endl;
    kapkan.attack("Fuze");
    fuze.takeDamage(20);
    std::cout << std::endl;

    fuze.attack("Kapkan");
    kapkan.takeDamage(30);
    std::cout << std::endl;

    kapkan.attack("Fuze");
    fuze.takeDamage(20);
    std::cout << std::endl;

    fuze.attack("Kapkan");
    kapkan.takeDamage(30);
    std::cout << std::endl;
    
    fuze.attack("Kapkan");
    kapkan.takeDamage(30);
    std::cout << std::endl;

    std::cout << "--- Kapkan is down! ---" << std::endl;
    kapkan.guardGate();
    std::cout << std::endl;

    std::cout << "--- ATTACKERS WIN ---" << std::endl;
    fuze.highFivesGuys();
    std::cout << std::endl;

    std::cout << "========= END OF MATCH =========\n" << std::endl;
}