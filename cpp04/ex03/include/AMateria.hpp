#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include "libmini/define.hpp"

# include <string>
# include <ostream>

class AMateria {
public:
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	virtual ~AMateria(void);

	const std::string&	getType(void) const;

	virtual AMateria*	clone(void) const = 0;
	virtual void		use(const ICharacter& target) const = 0;

private:
	AMateria(void)		DELETE;
	
	AMateria&	operator=(const AMateria& other) const;

	const std::string	_type;
};

std::ostream&	operator<<(std::ostream& os, const AMateria& materia);

#endif
