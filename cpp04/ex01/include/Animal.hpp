#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include "libmini/define.hpp"

# include <string>
# include <ostream>

class Animal {
public:
	explicit	Animal(const std::string& type);
				Animal(const Animal& other);
	virtual		~Animal(void);

	const std::string&	getType(void) const;
	virtual void		makeSound(void) const;

protected:
	const std::string	_type;

private:
	Animal(void) DELETE;

	Animal&	operator=(const Animal& other) const;
};

std::ostream&	operator<<(std::ostream& os, const Animal& animal);

#endif
