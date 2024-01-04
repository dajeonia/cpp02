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
	Fixed(int const);
	Fixed(float const);

	int getRawBits(void) const;
	void setRawBits(int const);

	float toFloat(void) const;
	int toInt(void) const;

	bool operator>(const Fixed&) const; // 비교 연산자
	bool operator<(const Fixed&) const;
	bool operator>=(const Fixed&) const;
	bool operator<=(const Fixed&) const;
	bool operator==(const Fixed&) const;
	bool operator!=(const Fixed&) const;

	Fixed operator+(const Fixed&) const; // 산술 연산자
	Fixed operator-(const Fixed&) const;
	Fixed operator*(const Fixed&) const;
	Fixed operator/(const Fixed&) const;

	Fixed &operator++(void); // 전위 연산자
	Fixed &operator--(void);
	Fixed operator++(int); // 후위 연산자
	Fixed operator--(int);

	static const Fixed& max(Fixed&, Fixed&); // 보조 함수
	static const Fixed& min(Fixed&, Fixed&);
	static const Fixed& max(const Fixed&, const Fixed&);
	static const Fixed& min(const Fixed&, const Fixed&);

	/*
	Fixed &operator+=(const Fixed&); // 복합 연산자
	Fixed &operator-=(const Fixed&);
	Fixed &operator*=(const Fixed&);
	Fixed &operator/=(const Fixed&);
	*/
};

std::ostream& operator<<(std::ostream&, const Fixed&);

#endif
