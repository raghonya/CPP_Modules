#include "FlagTrap.hpp"

int	main()
{
	// ClapTrap	bro("Bro");

	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");
	// bro.attack("someone");

	// bro.beRepaired(200);
	// bro.takeDamage(10);
	// bro.takeDamage(1000);
	// bro.attack("barev");
	{
		FlagTrap bro("flagBro");
		FlagTrap	bro2(bro);
	}
	return (0);
}