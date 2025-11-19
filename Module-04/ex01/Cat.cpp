#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	this->br = new Brain();
	std::cout <<" Cat Constructor Called" << std::endl;
}

Cat::~Cat()
{
	delete this->br;
	std::cout << " Cat Destructor Called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original)
{
	this->br = NULL;
	*this = original;
	std::cout <<" Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &original)
{
	if (this != &original)
	{
		this->type = original.type;
		if (this->br)
			delete this->br;
		this->br = new Brain(*original.br);
	}
	std::cout <<" Cat Copy Assigment Called" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

Brain *Cat::getBrain()
{
	return this->br;
}