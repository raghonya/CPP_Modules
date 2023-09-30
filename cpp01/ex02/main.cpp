#include <iostream>

int	main()
{
	std::string	var("HI THIS IS BRAIN");
	std::string	klris("HI THIS IS BRAINklir");
	std::string *varPtr = &var;
	std::string &varRef = var;
	std::string &varRef2 = varRef;

	varRef2 = varRef;

	varRef2[0] = 'a';
	std::cout << "2 add: " << &varRef2 << "   1 add: " << &varRef << std::endl;

	std::cout << "var address: " << &var << std::endl;
	std::cout << "varPtr address: " << varPtr << std::endl;
	std::cout << "varRef address: " << &varRef << std::endl;

	std::cout << "var value: " << var << std::endl;
	std::cout << "varPtr value: " << *varPtr << std::endl;
	std::cout << "varRef value: " << varRef << std::endl;
}
