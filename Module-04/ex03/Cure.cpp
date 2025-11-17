#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &O)
{
	*this = O;
}

Cure &Cure::operator=(const Cure &O)
{
	if (this != &O)
		this->_type = O._type;
	return *this;
}

Cure::~Cure()
{

}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &T)
{
	std::cout << "* heals " << T.getName() << "’s wounds *" << std::endl;
}