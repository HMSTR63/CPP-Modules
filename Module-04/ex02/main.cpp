#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	int I = 10;
	int i = 0;
	Animal *dazai[I];

	while (i < I / 2)
	{
		dazai[i] = new Dog();
		dazai[i]->makeSound();
		i++;
	}

	i = I / 2;
	while (i < I)
	{
		dazai[i] = new Cat();
		dazai[i]->makeSound();
		i++;
	}

	i = 0;

	while (i < I)
	{
		delete dazai[i];
		i++;
	}

	Dog d1;
	Dog d2 = d1;

	std::cout << d1.getBrain() << '\n';
	std::cout << d2.getBrain() << '\n';

	return 0;

}