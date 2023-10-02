#include <iostream>

int	main()
{
	std::string	var("HI THIS IS BRAIN");
	std::string *varPtr = &var;
	std::string &varRef = var;

	std::cout << "var address: " << &var << std::endl;
	std::cout << "varPtr address: " << varPtr << std::endl;
	std::cout << "varRef address: " << &varRef << std::endl;

	std::cout << "var value: " << var << std::endl;
	std::cout << "varPtr value: " << *varPtr << std::endl;
	std::cout << "varRef value: " << varRef << std::endl;
}
