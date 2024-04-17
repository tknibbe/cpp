#pragma once

class	Fixed{
	private:
		int					_Value;
		static const int	_Bits = 8;
	public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed& ref);
	Fixed& operator=(const Fixed& ref);
	int		getRawBits() const;
	void	setRawBits(int const raw);
};