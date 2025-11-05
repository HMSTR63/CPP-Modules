#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "Default ClapTrap constructed" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10),  _attackDamage(0)
{
    std::cout << "ClapTrap " << this->_name << " has been constructed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
{
    *this = original;
    std::cout << "ClapTrap " << this->_name << " has been copy-constructed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &original)
{
    if (this != &original)
    {
        this->_name = original._name;
        this->_attackDamage = original._attackDamage;
        this->_energyPoints = original._energyPoints;
        this->_hitPoints = original._hitPoints;
    }
    std::cout << "ClapTrap " << this->_name << " has been assigned" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " has been destroyed" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is out of energy and can't attack" << std::endl;
        return ;
    }
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is broken and can't attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << "  points of damage!" << std::endl;
    this->_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is broken and can't attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " take " << amount << "  points of damage!" << std::endl;
    if (this->_hitPoints <= amount)
    {
        this->_hitPoints = 0;
        std::cout << "ClapTrap " << this->_name << " is down" << std::endl;
        return ;
    }
    this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is broken and can't attack" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0)
    {
        std::cout << "ClapTrap " << this->_name << " is out of energy and can't attack" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " take " << amount << "  points of repair!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints--;
}