#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria *_T[4];
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &O);
		MateriaSource &operator=(const MateriaSource &O);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria *M);
		virtual AMateria *createMateria(std::string const &T);
};

#endif