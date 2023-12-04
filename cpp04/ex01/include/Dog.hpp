#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& other);
	virtual	~Dog(void);

	virtual void	makeSound(void) const;
	const Brain&	getBrain(void) const;

	static const std::string	TYPE;

private:
	Dog&	operator=(const Dog& other) const;

	const Brain	*_brain;
};

#endif
