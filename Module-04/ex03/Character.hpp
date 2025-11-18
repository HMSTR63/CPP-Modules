#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : public ICharacter
{
	private :
		std::string _name;
		AMateria *arry[1000];
		int flag;
		AMateria *_inv[4];
		void _safeDeepCopy(const Character &O);
        void _safeCleanup();
	public :
		Character();
		Character(std::string name);
		Character(const Character &O);
		Character &operator=(const Character &O);

		virtual ~Character();

		std::string const &getName() const;
		void equip(AMateria *M);
		void unequip(int idx);
		void use(int idx, ICharacter &T);
};
#endif