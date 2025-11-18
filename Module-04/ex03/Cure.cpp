#include "Cure.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &O) : AMateria(O) {}

Cure &Cure::operator=(const Cure &O)
{
    AMateria::operator=(O);
    return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const
{
    return new Cure(*this);
}

void Cure::use(ICharacter &T)
{
    std::cout << GREEN << "* " << getType() << " Materia: heals " << T.getName() << "’s wounds! *" << RESET << std::endl;
}