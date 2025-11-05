#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "Default DiamondTrap constructed" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_attackDamage =  ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << this->_name << " constructed!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &original) : ClapTrap(original), ScavTrap(original), FragTrap(original), _name(original._name)
{
    std::cout << "DiamondTrap " << this->_name << " copy constructed!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &original)
{
    if (this != &original)
    {
        ScavTrap::operator=(original);
        FragTrap::operator=(original);
        this->_name = original._name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " destroyed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << this->_name << std::endl;
    std::cout << "ClapTrap name is " << ClapTrap::_name << std::endl;
}