#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	this->br = new Brain();
	std::cout <<" Dog Constructor Called" << std::endl;
}

Dog::~Dog()
{
	delete this->br;
	std::cout << " Dog Destructor Called" << std::endl;
}

Dog::Dog(const Dog &original) : Animal(original)
{
	Animal::operator=(original);
	this->br = new Brain(*(original.br));
	std::cout <<" Dog Copy Constructor Called" << std::endl;
}

Dog &Dog::operator=(const Dog &original)
{
	if (this != &original)
	{
		Animal::operator=(original);
		if (this->br)
			delete this->br;
		this->br = new Brain(*original.br);
	}
	std::cout <<" Dog Copy Assigment Called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain()
{
	return this->br;
}