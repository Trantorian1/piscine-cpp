#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Cure : public AMateria {
public:
	Cure(void);
	Cure(const Cure& other);
	virtual ~Cure(void);

	virtual Cure*	clone(void) const;
	virtual void	use(const ICharacter& target) const;

private:
	Cure&	operator=(const Cure& other) const;
};

#endif
