#include <Zombie.hpp>
#include <iostream>

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName( std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie with name " << this->name << " was destroyed" << std::endl;
}