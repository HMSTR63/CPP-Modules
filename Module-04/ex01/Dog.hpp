#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private :
		Brain *br;
	public :
		Dog();
		virtual ~Dog();
		Dog(const Dog &original);
		Dog &operator=(const Dog &original);

		void makeSound() const;
		Brain *getBrain();
};

#endif