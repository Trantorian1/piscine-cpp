#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);
	Fixed&	operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(const int newRawBits);

private:
	static const int	SIGN_BITS = 8;
	int					_rawBits;
};

#endif
