#pragma once
#include <iostream>

class	Fixed{

	private:
		int					_Value;
		static const int	_Bits = 8;
	
	public:
	Fixed(void);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed(void);
	Fixed(const Fixed& ref);
	int		getRawBits() const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	static Fixed&		min(Fixed& left, Fixed& right);
	static Fixed&		max(Fixed& left, Fixed& right);
	static const Fixed&	min(const Fixed& left, const Fixed& right);
	static const Fixed&	max(const Fixed& left, const Fixed& right);


	Fixed&	operator=(const Fixed& ref);

	//comparison
	bool	operator>(const Fixed& ref) const;
	bool	operator<(const Fixed& ref) const;
	bool	operator<=(const Fixed& ref) const;
	bool	operator>=(const Fixed& ref) const;
	bool	operator==(const Fixed& ref) const;
	bool	operator!=(const Fixed& ref) const;

	//arithmic
	Fixed	operator+(const	Fixed& ref);
	Fixed	operator-(const	Fixed& ref);
	Fixed	operator*(const	Fixed& ref);
	Fixed	operator/(const	Fixed& ref);

	//in-decrement
	Fixed&	operator++();
	float	operator++(int num);
	Fixed&	operator--();
	float	operator--(int num);
};
std::ostream&	operator<<(std::ostream& os, const Fixed& ref);