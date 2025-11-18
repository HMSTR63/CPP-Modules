#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("default")
{
    std::cout << BLUE << "AMateria (default) constructed." << RESET << std::endl;
}

AMateria::AMateria(std::string type) : _type(type)
{   
    std::cout << BLUE << "AMateria (" << _type << ") constructed." << RESET << std::endl;
}

AMateria::AMateria(const AMateria &O) : _type(O._type)
{
    std::cout << BLUE << "AMateria (" << _type << ") copied." << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &O)
{
    if (this != &O)
        this->_type = O._type;
    std::cout << MAGENTA << "AMateria assignment operator called." << RESET << std::endl;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << BLUE << "AMateria (" << _type << ") destroyed." << RESET << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter &T)
{
    std::cout << GREEN << "* AMateria " << this->getType() << " used on " << T.getName() << " *" << RESET << std::endl;
}