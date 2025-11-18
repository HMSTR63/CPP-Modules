#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

class AMateria
{
	protected :
		std::string _type;
	public :
		AMateria();
		AMateria(std::string type);
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