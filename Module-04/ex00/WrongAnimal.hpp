#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected :
		std::string type;
	public :
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const std::string _type);
		WrongAnimal(const WrongAnimal &original);
		WrongAnimal &operator=(const WrongAnimal &original);

		void makeSound() const;
		std::string getType() const;

};

#endif