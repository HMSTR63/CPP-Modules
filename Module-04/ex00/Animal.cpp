#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << this->type <<" Constructor Called" << std::endl;
}

Animal::~Animal()
{
	std::cout << this->type <<" Destructor Called" << std::endl;
}

Animal::Animal(const std::string _type) : type(_type)
{
	std::cout << this->type <<" is spowen" << std::endl;
}

Animal::Animal(const Animal &original)
{
	*this = original;
	std::cout <<"Copy Constructor Called" << std::endl;
}

Animal &Animal::operator=(const Animal &original)
{
	if (this != &original)
		this->type = original.type;
	std::cout <<"Copy Assigment Called" << std::endl;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal Make sound" << std::endl;
}

std::string Animal::getType() const 
{
	return this->type;
}

