#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("Default")
{

}

AMateria::AMateria(std::string type)
{	
	_type = type;
}

// AMateria::AMateria(const AMateria &O)
// {
// 	*this = O;
// }

AMateria &AMateria::operator=(const AMateria &O)
{
	(void)O;
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
	std::cout << "* materia " << this->getType() << " used on " << T.getName() << std::endl;
}