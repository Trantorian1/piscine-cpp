#ifndef FIXED_HPP
# define FIXED_HPP

# include <ostream>

class Fixed {
public:
	Fixed(void);
	Fixed(const int n);
	Fixed(const float f);
	Fixed(const Fixed& other);
	~Fixed(void);
	Fixed&	operator=(const Fixed& other);

	operator	float(void) const;
	operator	int(void) const;

	int		getRawBits(void) const;
	void	setRawBits(const int newRawBits);
	float	toFloat(void) const;
	int		toInt(void) const;

private:
	static const int	FRACTIONAL_BITS = 8;
	int					_rawBits;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);

#endif
