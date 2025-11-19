#include "Ice.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &O) : AMateria(O) {}

Ice &Ice::operator=(const Ice &O)
{
    AMateria::operator=(O);
    return *this;
}

Ice::~Ice() {
}

AMateria *Ice::clone() const
{
    return new Ice(*this);
}

void Ice::use(ICharacter &T)
{
    std::cout << GREEN << "* " << getType() << " Materia: shoots an ice bolt at " << T.getName() << "! *" << RESET << std::endl;
}