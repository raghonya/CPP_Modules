#include "ScavTrap.hpp"

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
		ScavTrap bro("Bro");
		bro.guardGate();

		bro.takeDamage(15);
		bro.takeDamage(15);
		bro.takeDamage(15);
		bro.takeDamage(15);
		bro.takeDamage(15);
		bro.takeDamage(15);
		bro.takeDamage(15);
		bro.takeDamage(15);
	}
	return (0);
}