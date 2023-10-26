#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	Animal		*bro = new Dog();
	Animal	*animals = new Animal[100];

	for (int i = 0; i < 100; ++i)
	{
		*(animals + i) = Cat();
		if (i > 49)
			*(animals + i) = Dog();
	}
	for (int i = 0; i < 100; ++i)
	{
		(animals + i)->makeSound();
		std::cout << (animals + i)->getType() << std::endl;
	}

	delete[] animals;

	return (0);
}