#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed
{
	private:
		int					fpn;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed(const int number);
		Fixed(const float number);
		int				toInt(void) const;
		float			toFloat(void) const;
		Fixed&			operator=(const Fixed& obj);
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		~Fixed();

};

std::ostream&	operator<<(std::ostream& stream, const Fixed& obj);

#endif