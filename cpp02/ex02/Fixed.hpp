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
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static Fixed&		min(Fixed& a, Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		Fixed				operator*( const Fixed& obj ) const;
		Fixed				operator/( const Fixed& obj ) const;
		Fixed				operator-( const Fixed& b ) const;
		Fixed				operator+( const Fixed& b ) const;
		Fixed				operator--(int ok);
		Fixed				operator--( void );
		Fixed				operator++( int ok );
		Fixed				operator++( void );
		float				toFloat( void ) const;
		Fixed&				operator=( const Fixed& obj );
		bool				operator<( const Fixed& obj ) const;
		bool				operator>( const Fixed& obj ) const;
		bool				operator<=( const Fixed& obj ) const;
		bool				operator>=( const Fixed& obj ) const;
		bool				operator==( const Fixed& obj ) const;
		bool				operator!=( const Fixed& obj ) const;
		void				setRawBits( int const raw );
		int					getRawBits( void ) const;
		int					toInt( void ) const;
		~Fixed();

};

std::ostream&	operator<<(std::ostream& stream, const Fixed& obj);

#endif