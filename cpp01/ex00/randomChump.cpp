#include <Zombie.hpp>
#include <iostream>

void randomChump( std::string name )
{
	Zombie	died;

	died.setName(name);
	died.announce();
}