#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include "libmini/define.hpp"

# include <string>
# include <ostream>

class WrongAnimal {
public:
	explicit	WrongAnimal(const std::string& type);
				WrongAnimal(const WrongAnimal& other);
	virtual		~WrongAnimal(void);

	const std::string&	getType(void) const;
	void				makeSound(void) const;

protected:
	const std::string	_type;

private:
	WrongAnimal(void) DELETE;
	WrongAnimal	operator=(const WrongAnimal& other) const;
};

std::ostream&	operator<<(std::ostream& os, const WrongAnimal& animal);

#endif
