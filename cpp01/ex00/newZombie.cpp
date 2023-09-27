#include <Zombie.hpp>
#include <iostream>

Zombie* newZombie( std::string name )
{
	Zombie	*died = new Zombie;

	died->setName(name);
	return (died);
}