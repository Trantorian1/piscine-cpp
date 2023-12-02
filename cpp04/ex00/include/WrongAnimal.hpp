#ifndef WRONG_ANIMAL_HPP
# define WRONG_ANIMAL_HPP

# include <string>
# include <ostream>

class WrongAnimal {
public:
	explicit	WrongAnimal(const std::string& type);
				WrongAnimal(const WrongAnimal& other);
	virtual		~WrongAnimal(void);

	WrongAnimal	operator=(const WrongAnimal& other) const;

	const std::string&	getType(void) const;
	void				makeSound(void) const;

protected:
	const std::string	_type;

private:
	WrongAnimal(void);
};

std::ostream&	operator<<(std::ostream& os, const WrongAnimal& animal);

#endif
