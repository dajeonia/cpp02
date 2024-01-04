#include <Fixed.hpp>

// return (this->value + f.getRawBits());

Fixed::Fixed(void) { value = 0; }

Fixed::~Fixed(void) { }

Fixed::Fixed(const Fixed &f) { *this = f; }

Fixed::Fixed(int const n) { value = n << bits; }

Fixed::Fixed(float const fn) { value = roundf(fn * pow(2, bits)); }

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
		value = f.value;
	return (*this);
}

int	Fixed::getRawBits(void) const { return (value); }

void	Fixed::setRawBits(int const raw) { value = raw; }

float	Fixed::toFloat(void) const { return (value / pow(2, bits)); }

int	Fixed::toInt(void) const { return (value >> 8); }

std::ostream&	operator<<(std::ostream& os, const Fixed& f) { return (os << f.toFloat()); }

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->value > other.value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->value < other.value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->value >= other.value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->value <= other.value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->value == other.value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->value != other.value);
}

Fixed	Fixed::operator+(const Fixed& f) const
{
	return (this->toFloat() + f.toFloat());
}

Fixed	Fixed::operator-(const Fixed& f) const
{
	return (this->toFloat() - f.toFloat());
}

Fixed	Fixed::operator*(const Fixed& f) const
{
	return (this->toFloat() * f.toFloat());
}

Fixed	Fixed::operator/(const Fixed& f) const
{
	return (this->toFloat() / f.toFloat());
}

Fixed &Fixed::operator++(void)
{
	++(this->value);
	return (*this);
}

Fixed &Fixed::operator--(void)
{
	--(this->value);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);

	++(this->value);
	return (ret);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);

	--(this->value);
	return (ret);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a < b)
		return (a);
	return (b);
}

/*
Fixed	&Fixed::operator+=(const Fixed& f)
{
	*this = this->toFloat() + f.toFloat();
	return (*this);
}

Fixed	&Fixed::operator-=(const Fixed& f)
{
	*this = this->toFloat() - f.toFloat();
	return (*this);
}

Fixed	&Fixed::operator*=(const Fixed& f)
{
	*this = this->toFloat() * f.toFloat();
	return (*this);
}

Fixed	&Fixed::operator/=(const Fixed& f)
{
	*this = this->toFloat() / f.toFloat();
	return (*this);
}
*/
