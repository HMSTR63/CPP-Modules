#ifndef CURE_HPP
#define CURE_HPP

#include <iostream>
#include "AMateria.hpp"

class Cure : public AMateria
{
	public :
		Cure();
		Cure(const Cure &O);
		Cure &operator=(const Cure &O);
		virtual ~Cure();

		virtual AMateria *clone() const;
		virtual void use(ICharacter &T);
};

#endif