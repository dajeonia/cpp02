#include <Fixed.hpp>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &f)
 {
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
 }

Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
		value = f.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
// 	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

Fixed::Fixed(int const n)
{
	std::cout << "Int constructor called" << std::endl;
	value = n << bits;
}

Fixed::Fixed(float const fn)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(fn * pow(2, bits));
}

float Fixed::toFloat(void) const
{
	return (value / pow(2, bits));
}

int Fixed::toInt(void) const
{
	return (value >> 8);
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}
