#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("DefaultScavName")
{
    this->_hitPoints = 100;
    this->_attackDamage =  50;
    this->_attackDamage = 20;
    std::cout << "Default " << this->_name << " ScavTrap constructed" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_attackDamage =  50;
    this->_attackDamage = 20;
    std::cout << "ScavTrap " << this->_name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &original) : ClapTrap(original)
{
    *this = original;
    std::cout << "ScavTrap " << this->_name << " copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &original)
{
    if (this != &original)
        ClapTrap::operator=(original);
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

void ScavTrap::guardGate(void)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is broken and can't enter Gatekeeper mode" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " is in Gatekeeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is out of energy and can't attack" << std::endl;
        return ;
    }
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is broken and can't attack" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << "  points of damage!" << std::endl;
    this->_energyPoints--;
}