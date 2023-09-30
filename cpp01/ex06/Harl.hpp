#include <iostream>

class Harl
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
	public:
		void	complain( std::string level );
		void	(Harl::*funcPtr[5]) ( void );
		void	setPtrs( void );
	private:
		void	cantComplain( void );
};