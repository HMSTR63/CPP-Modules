#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected :
		std::string type;
	public :
		Animal();
		virtual ~Animal();
		Animal(const std::string _type);
		Animal(const Animal &original);
		Animal &operator=(const Animal &original);

		virtual void makeSound() const = 0;
		std::string getType() const;

};

#endif