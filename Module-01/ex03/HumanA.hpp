#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"
class HumanA
{
    private :
        std::string name; // bob
        Weapon &wp; // club like Weapon &wp = Weapon("crude spiked club");
    public :
        HumanA(std::string name, Weapon &wp); // wp contains = Weapon("crude spiked club"); and name contains "Bob"
        void attack();
};

#endif