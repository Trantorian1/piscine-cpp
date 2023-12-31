#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {
public:
	Dog(void);
	Dog(const Dog& other);
	virtual	~Dog(void);

	virtual void	makeSound(void) const;
	const Brain&	getBrain(void) const;

	static const std::string	TYPE;

private:
	const Brain	*_brain;

	Dog	operator=(const Dog& other) const;
};

#endif
