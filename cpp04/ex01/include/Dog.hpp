#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal {
public:
	Dog(void);
	Dog(const Dog& other);
	virtual	~Dog(void);

	Dog	operator=(const Dog& other) const;

	virtual void	makeSound(void) const;
	const Brain&	getBrain(void) const;

	static const std::string	TYPE;

private:
	const Brain	*_brain;
};

#endif
