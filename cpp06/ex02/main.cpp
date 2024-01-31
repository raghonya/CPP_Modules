#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate( void );
void	identify(Base* p);
void	identify(Base& p);

int	main()
{
	Base	*alo;
	
	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	alo = generate();
	identify(alo);
	identify(*alo);
	delete alo;

	return (0);
}