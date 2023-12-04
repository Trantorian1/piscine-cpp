#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include <cstddef>

class AMateria;

class ICharacter {
public:
	virtual ~ICharacter(void) {};

	virtual const std::string&	getName(void) const = 0;

	virtual void equip(const AMateria* materia) = 0;
	virtual void unequip(int index) = 0;
	virtual void use(int index, const ICharacter& target) const = 0;
};

#endif
