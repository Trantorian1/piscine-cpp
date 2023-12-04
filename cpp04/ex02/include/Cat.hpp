#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {
public:
	Cat(void);
	Cat(const Cat& other);
	virtual	~Cat(void);

	virtual void	makeSound(void) const;
	const Brain&	getBrain(void) const;

	static const std::string	TYPE;

private:
	const Brain	*_brain;

	Cat	operator=(const Cat& other) const;
};

#endif
