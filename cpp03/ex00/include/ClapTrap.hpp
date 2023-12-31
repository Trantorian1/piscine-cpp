#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <ostream>

class ClapTrap {
public:
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap(void);

	ClapTrap&	operator=(const ClapTrap& other);

	const std::string&	getName(void) const;
	unsigned int		getHitPoints(void) const;
	unsigned int		getEnergyPoints(void) const;
	unsigned int		getAttackDamage(void) const;
	void				setName(const std::string& newName);
	void				setHitPoints(unsigned int newHitPoints);
	void				setEnergyPoints(unsigned int newHitPoints);
	void				setAttackDamage(unsigned int newAttackDamage);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:
	ClapTrap(void);

	void	init(
		const std::string& name,
		unsigned int hitPoints,
		unsigned int energypoints,
		unsigned int attackDamage
	);
	bool	tryAct(void);

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

	static const unsigned int	BASE_HP;
	static const unsigned int	BASE_EP;
	static const unsigned int	BASE_AD;

};

std::ostream&	operator<<(std::ostream& os, const ClapTrap& clapTrap);

#endif
