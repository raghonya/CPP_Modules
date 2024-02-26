#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base*	generate( void )
{
	Base	*derivedClasses[3] = {new(A), new(B), new(C)};
	int		rand = std::rand() % 3;

	for (int i = 0; i < 3; ++i)
		if (i != rand)
			delete derivedClasses[i];
	return (derivedClasses[rand]);
	
}

void	identify(Base* p)
{
	std::string	type[4] = {"A", "B", "C", "Base"};
	Base	*derivedClasses[4] = 
	{
		dynamic_cast<A*>(p),
		dynamic_cast<B*>(p),
		dynamic_cast<C*>(p),
		dynamic_cast<Base*>(p)
	};

	int i = 0;
	for (; i < 4 && !derivedClasses[i]; ++i) ;
	std::cout << "The actual type of object is '" << type[i] << "'" << std::endl;
}

void	identify(Base& p)
{
	std::string	type[4] = {"A", "B", "C", "Base"};
	Base	*derivedClasses[4] = 
	{
		dynamic_cast<A*>(&p),
		dynamic_cast<B*>(&p),
		dynamic_cast<C*>(&p),
		dynamic_cast<Base*>(&p)
	};

	int i = 0;
	for (; i < 4 && !derivedClasses[i]; ++i) ;
	std::cout << "The actual type of object is '" << type[i] << "'" << std::endl;
}
