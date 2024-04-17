#pragma once

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

	Fixed&	operator=(const Fixed& ref);
	void	operator<<(const Fixed& ref);
};