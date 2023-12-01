#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <string>

class FragTrap : public ClapTrap {
public:
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	virtual ~FragTrap(void);

	void	attack(const std::string& target);
	void	highFiveGuys(void);

private:
	FragTrap(void);
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
