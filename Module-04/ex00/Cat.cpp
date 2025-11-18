#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout <<" Cat Constructor Called" << std::endl;
}

Cat::~Cat()
{
	std::cout << " Cat Destructor Called" << std::endl;
}

Cat::Cat(const Cat &original) : Animal(original)
{
	*this = original;
	std::cout <<" Cat Copy Constructor Called" << std::endl;
}

Cat &Cat::operator=(const Cat &original)
{
	if (this != &original)
		Animal::operator=(original);
	std::cout <<" Cat Copy Assigment Called" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}