#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	delete i;
	j->makeSound();
	delete j;
	meta->makeSound();
	delete meta;

	const WrongAnimal* Wrong_i = new WrongCat();
	std::cout << Wrong_i->getType() << " " << std::endl;
	Wrong_i->makeSound();
	delete Wrong_i;
	return 0;
}