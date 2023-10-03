#include "Fixed.hpp"

Fixed::Fixed() { std::cout << "Default constructor called" << std::endl; }

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->number = obj.getRawBits();
}

void	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->number = obj.getRawBits();
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->number);
}

void	Fixed::setRawBits( int const raw )
{
	this->number = raw;
}