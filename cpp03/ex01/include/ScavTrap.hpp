#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class ScavTrap : public ClapTrap {
public:
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	virtual ~ScavTrap(void);

	void	attack(const std::string& target);
	void	guardGate(void);

private:
	ScavTrap(void);
	void	init(
		unsigned int hitPoints,
		unsigned int energyPoints,
		unsigned int attackDamage
	);

	static const unsigned int	BASE_HP;
	static const unsigned int	BASE_EP;
	static const unsigned int	BASE_AD;
};

#endif
