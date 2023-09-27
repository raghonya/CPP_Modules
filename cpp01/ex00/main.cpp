#include <iostream>
#include <Zombie.hpp>

int	main()
{
	Zombie	*one;

	one = newZombie("Pipex");
	one->announce();
	randomChump("Minishell");

	delete one;
	return (0);
}