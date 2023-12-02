#ifndef WRONG_CAT_HPP
# define WRONG_CAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat(void);
	WrongCat(const WrongCat& other);
	virtual	~WrongCat(void);

	WrongCat	operator=(const WrongCat& other) const;

	void	makeSound(void) const;

	static const std::string	TYPE;
};

#endif
