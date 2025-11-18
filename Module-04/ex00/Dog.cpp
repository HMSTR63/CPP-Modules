#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout <<" Dog Constructor Called" << std::endl;
}

Dog::~Dog()
{
	std::cout << " Dog Destructor Called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original)
{
	*this = original;
	std::cout <<" Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
	if (this != &original)
		Animal::operator=(original);
	std::cout <<" Dog Copy Assigment Called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}