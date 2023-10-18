#include "ScavTrap.hpp"

int	main()
{
	ScavTrap bro("Bro");
	bro.guardGate();

	bro.takeDamage(15);
	bro.takeDamage(15);
	bro.takeDamage(15);
	bro.attack("NoBro");
	bro.takeDamage(15);
	bro.takeDamage(15);
	bro.takeDamage(15);
	bro.takeDamage(15);
	bro.takeDamage(15);
	return (0);
}