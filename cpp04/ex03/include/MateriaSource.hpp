#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"
# include <string>

class MateriaSource : public IMateriaSource {
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	virtual ~MateriaSource(void);

	unsigned char getSize(void) const;

	virtual void		learnMateria(const AMateria* materia);
	virtual AMateria*	createMateria(const std::string type) const;
	bool				hasSpaceLeft(void) const;
	bool				knows(const AMateria* materia) const;

	static const unsigned char CAPACITY = 4;

private:
	MateriaSource&	operator=(const MateriaSource& other) const;

	std::string		_learned[MateriaSource::CAPACITY];
	unsigned char	_size;
};

#endif
