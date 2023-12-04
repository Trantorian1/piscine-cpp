#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

class Ice : public AMateria {
public:
	Ice(void);
	Ice(const Ice& other);
	virtual ~Ice(void);

	virtual Ice*	clone(void) const;
	virtual void	use(const ICharacter& target) const;

private:
	Ice&	operator=(const Ice& other) const;
};

#endif
