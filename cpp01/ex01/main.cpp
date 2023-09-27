#include <iostream>
#include <Zombie.hpp>

int	main()
{
	Zombie	*diedPeople;

	diedPeople = zombieHorde(4, "Michael");
	for (int i = 0; i < 4; i++)
		(diedPeople + i)->announce();
	delete[] diedPeople;
	return (0);
}