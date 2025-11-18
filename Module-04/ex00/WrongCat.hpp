#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private :

	public :
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &original);
		WrongCat &operator=(const WrongCat &original);

		void makeSound() const;
};

#endif