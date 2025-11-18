#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << this->type <<" Constructor Called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << this->type <<" Destructor Called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string _type) : type(_type)
{
	std::cout << this->type <<" is spowen" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original)
{
	*this = original;
	std::cout <<"Copy Constructor Called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &original)
{
	if (this != &original)
		this->type = original.type;
	std::cout <<"Copy Assigment Called" << std::endl;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Make sound" << std::endl;
}

std::string WrongAnimal::getType() const 
{
	return this->type;
}