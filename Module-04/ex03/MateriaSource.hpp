#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <iostream>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private :
		AMateria *_T[4];
		AMateria *arry[1000];
		int flag;
		void _safeDeepCopy(const MateriaSource &O);
		void _safeCleanup();
	public :
		MateriaSource();
		MateriaSource(const MateriaSource &O);
		MateriaSource &operator=(const MateriaSource &O);
		virtual ~MateriaSource();

		virtual void learnMateria(AMateria *M);
		virtual AMateria *createMateria(std::string const &T);
};

#endif