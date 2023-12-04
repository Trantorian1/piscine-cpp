#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include "libmini/define.hpp"

# include <string>
# include <ostream>
# include <cstddef>

class Character : public ICharacter {
public:
	Character(const std::string& name);
	Character(const Character& other);
	~Character(void);

	virtual const std::string&	getName(void) const;
	unsigned char				getSize(void) const;

	virtual void	equip(const AMateria *materia);
	virtual void	unequip(int index);
	virtual void	use(int index, const ICharacter& target) const;
	bool			hasSpaceLeft(void) const;

	static const unsigned char	CAPACITY = 4;

private:
	Character(void) DELETE;

	Character&	operator=(const Character& other);

	const std::string	_name;
	const AMateria*		_inventory[Character::CAPACITY];
	unsigned char		_size;
};

std::ostream&	operator<<(std::ostream& os, const Character& character);

#endif
