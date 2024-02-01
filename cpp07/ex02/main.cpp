#include "Array.hpp"

int	main()
{

	int *id = new int[5];

	Array<int> a(4);

	try
	{

		a[7] = 5;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);	
}