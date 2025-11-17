#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
	protected :
		std::string _type;
	public :
		AMateria();
		AMateria(std::string type);
		AMateria(const AMateria &O);
		AMateria &operator=(const AMateria &O);
		virtual ~AMateria();
		// PURE VIRTUAL "clone()"
		// This makes the class abstract.
		// It's a "virtual copy constructor" - it promises to return a 
		// new copy of whatever the *real* class is
		std::string const &getType() const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &T);
};

#endif