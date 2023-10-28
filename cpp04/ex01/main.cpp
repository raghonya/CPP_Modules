#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal	**animals = new Animal*[100];

	for (int i = 0; i < 100; ++i)
	{
		if (i > 49)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 100; ++i)
	{
		animals[i]->makeSound();
		delete animals[i];
	}
	delete[] animals;

	return (0);
}