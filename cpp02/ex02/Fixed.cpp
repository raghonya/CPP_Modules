#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fpn = 0;
}

Fixed::Fixed(const Fixed& obj)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fpn = obj.getRawBits();
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	this->fpn = (number * (1 << 8));
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	this->fpn = roundf(number * (1 << 8));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

int		Fixed::toInt(void) const
{
	return (static_cast<int>(this->fpn) / static_cast<int>(1 << 8));
}

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->fpn) / static_cast<float>(1 << 8));
}

Fixed&	Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fpn = obj.getRawBits();
}

int		Fixed::getRawBits( void ) const
{
	return (this->fpn);
}

void	Fixed::setRawBits( int const raw )
{
	this->fpn = raw;
}

std::ostream&	operator<<(std::ostream& stream, const Fixed& obj)
{
	stream << obj.toFloat();
	return (stream);
}

///////////////////////// OPERATOR OVERLOADING ///////////////////////////////////////////////////////////////

Fixed	Fixed::operator+(const Fixed& a) const
{
	Fixed	ret;

	ret.fpn = this->toFloat() + a.toFloat();
	return (ret);
}

Fixed	Fixed::operator++(void)
{
	++this->fpn;
	return (*this);
}

Fixed	Fixed::operator++(int ok)
{
	Fixed	ret(*this);

	(void)ok;

	this->fpn += 1;
	return (ret);
}

Fixed	Fixed::operator-(const Fixed& a) const
{
	Fixed	ret;

	ret.fpn = this->toFloat() - a.toFloat();
	return (ret);
}

Fixed	Fixed::operator--(void)
{
	--this->fpn;
	return (*this);
}

Fixed	Fixed::operator--(int ok)
{
	Fixed	ret(*this);

	(void)ok;

	this->fpn -= 1;
	return (ret);
}

Fixed	Fixed::operator*(const Fixed& a) const
{
	Fixed	ret;

	ret = this->toFloat() * a.toFloat();
	return (ret);
}

Fixed	Fixed::operator/(const Fixed& a) const
{
	Fixed	ret;

	if (!a.toFloat())
	{
		std::cout << "Found division by 0!!!" << std::endl;
		std::cout << "Returning left operand..." << std::endl;
		return (this->toFloat());
	}
	ret = this->toFloat() / a.toFloat();
	return (ret);
}

bool	Fixed::operator<(const Fixed& obj) const
{
	return (this->fpn < obj.fpn);
}

bool	Fixed::operator<=(const Fixed& obj) const
{
	return (this->fpn <= obj.fpn);
}

bool	Fixed::operator>(const Fixed& obj) const
{
	return (this->fpn > obj.fpn);
}

bool	Fixed::operator>=(const Fixed& obj) const
{
	return (this->fpn >= obj.fpn);
}

bool	Fixed::operator==(const Fixed& obj) const
{
	return (this->fpn == obj.fpn);
}

bool	Fixed::operator!=(const Fixed& obj) const
{
	return (this->fpn != obj.fpn);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}
