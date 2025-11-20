#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default")
{
}

AMateria::AMateria(std::string type) : _type(type)
{   
}

AMateria::AMateria(const AMateria &O) : _type(O._type)
{
}

AMateria &AMateria::operator=(const AMateria &O)
{
    if (this != &O)
        this->_type = O._type;
    return *this;
}

AMateria::~AMateria()
{

}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &T)
{
    std::cout << GREEN << "* AMateria " << this->getType() << " used on " << T.getName() << " *" << RESET << std::endl;
}