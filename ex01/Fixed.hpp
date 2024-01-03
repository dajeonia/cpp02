#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed {
	int value;
	static const int bits=8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &);

	int getRawBits(void) const;
	void setRawBits(int const);

	Fixed(int const);
	Fixed(float const);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
