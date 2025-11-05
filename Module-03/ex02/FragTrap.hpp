#ifndef FRAGTARP_HPP
#define FRAGTARP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public :
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &original);
        FragTrap &operator=(const FragTrap &original);
        ~FragTrap();

        void highFivesGuys(void);
        void attack(const std::string& target);
};

#endif