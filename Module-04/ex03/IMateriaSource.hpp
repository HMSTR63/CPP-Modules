#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <iostream>
class AMateria;

class IMateriaSource
{
	public :
		virtual ~IMateriaSource() {};
		virtual void learnMateria(AMateria *M) = 0;
		virtual AMateria *createMateria(std::string const &T) = 0;
};

#endif