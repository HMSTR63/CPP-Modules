#include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{

}

AMateria::AMateria(std::string type) : _type(type)
{	

}

AMateria::AMateria(const AMateria &O)
{
	*this = O;
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
	std::cout << "* materia " << this->getType() << " used on " << T.getName() << std::endl;
}