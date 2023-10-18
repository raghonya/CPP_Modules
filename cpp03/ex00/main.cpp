#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	bro("Bro");

	bro.attack("someone");
	bro.attack("someoneElse");

	bro.beRepaired(200);
	bro.takeDamage(10);
	bro.attack("barev");
	return (0);
}