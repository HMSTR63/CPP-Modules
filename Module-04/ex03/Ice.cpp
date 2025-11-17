#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &O)
{
	*this = O;
}

Ice &Ice::operator=(const Ice &O)
{
	if (this != &O)
		this->_type = O._type;
	return *this;
}

Ice::~Ice()
{

}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &T)
{
	std::cout << "* shoots an ice bolt at " << T.getName() << " *" << std::endl;
}