#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout <<" WrongCat Constructor Called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << " WrongCat Destructor Called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
	*this = original;
	std::cout <<" WrongCat Copy Constructor Called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &original)
{
	if (this != &original)
		this->type = original.type;
	std::cout <<" WrongCat Copy Assigment Called" << std::endl;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}