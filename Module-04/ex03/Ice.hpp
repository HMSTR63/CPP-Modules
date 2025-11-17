#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "AMateria.hpp"

class Ice : public AMateria
{
	Ice();
	Ice(const Ice &O);
	Ice &operator=(const Ice &O);
	virtual ~Ice();

	virtual AMateria *clone() const;
	virtual void use(ICharacter &T);
};

#endif