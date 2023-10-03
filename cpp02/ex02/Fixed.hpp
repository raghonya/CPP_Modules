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
		Fixed( const Fixed& obj );
		Fixed( const int number );
		Fixed( const float number );
		int				toInt( void ) const;
		float			toFloat( void ) const;
		void			operator=( const Fixed& obj );
		// bool			operator<(const Fixed& obj);
		// bool			operator>(const Fixed& obj);
		// bool			operator<=(const Fixed& obj);
		// bool			operator>=(const Fixed& obj);
		// bool			operator==(const Fixed& obj);
		// bool			operator!=(const Fixed& obj);
		// void			operator*(const Fixed& obj);
		// void			operator/(const Fixed& obj);
		Fixed			operator-( const Fixed& b );
		Fixed			operator--(int ok);
		Fixed			operator--( void );
		Fixed			operator+( const Fixed& b );
		Fixed			operator++(int ok);
		Fixed			operator++( void );
		int				getRawBits( void ) const;
		void			setRawBits( int const raw );
		~Fixed();

};

std::ostream&	operator<<(std::ostream& stream, const Fixed& obj);

#endif