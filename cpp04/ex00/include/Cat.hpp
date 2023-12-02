#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {
public:
	Cat(void);
	Cat(const Cat& other);
	virtual	~Cat(void);

	Cat	operator=(const Cat& other) const;

	virtual void	makeSound(void) const;

	static const std::string	TYPE;
};

#endif
