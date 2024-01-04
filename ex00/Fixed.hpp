#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed {
	int value;
	static const int bits=8;
public:
	Fixed();
	Fixed(const Fixed &f);
	Fixed& operator=(const Fixed &);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const);
};

#endif
