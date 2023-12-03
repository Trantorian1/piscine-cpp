#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <ostream>

class AAnimal {
public:
	virtual		~AAnimal(void);

	const std::string&	getType(void) const;
	virtual void		makeSound(void) const = 0;

protected:
	explicit	AAnimal(const std::string& type);
				AAnimal(const AAnimal& other);

	const std::string	_type;

private:
	AAnimal(void);
};

std::ostream&	operator<<(std::ostream& os, const AAnimal& animal);

#endif
