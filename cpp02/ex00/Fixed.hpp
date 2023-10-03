#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					number;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		void	operator=(const Fixed& obj);
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		~Fixed();

};

#endif