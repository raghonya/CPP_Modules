#include <iostream>
#include "Harl.hpp"

int	main()
{
	Harl	a;

	a.setPtrs();
	a.complain("DEBUG");
	a.complain("INFO");
	a.complain("WARNING");
	a.complain("ERROR");
	a.complain("some other message");
	return (0);
}