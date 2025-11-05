#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default FragTrap constructed" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_attackDamage =  100;
    this->_attackDamage = 30;
    std::cout << "FragTrap " << this->_name << " constructed!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &original) : ClapTrap(original)
{
    *this = original;
    std::cout << "FragTrap " << this->_name << " copy constructed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &original)
{
    if (this != &original)
        ClapTrap::operator=(original);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_name << " destroyed!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "FragTrap " << this->_name << " is out of energy and can't attack" << std::endl;
        return ;
    }
    if (this->_hitPoints == 0)
    {
        std::cout << "FragTrap " << this->_name << " is broken and can't attack" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << "  points of damage!" << std::endl;
    this->_energyPoints--;
}

void FragTrap::highFivesGuys()
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is broken and can't high Five mode" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " : high Five Guys!!!!!!" << std::endl;
}