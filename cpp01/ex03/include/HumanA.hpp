#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"
# include <ostream>
# include <string>

class HumanA {
public:
	HumanA(const std::string& name, Weapon& weapon);
	HumanA(const HumanA& other);
	~HumanA(void);

	HumanA&	operator=(const HumanA& other);

	const Weapon&		getWeapon(void) const;
	const std::string&	getName(void) const;
	void				setWeapon(Weapon& newWeapon);

	void	attack(void) const;

private:
	std::string	_name;
	Weapon&		_weapon;
};

std::ostream&	operator<<(std::ostream& os, const HumanA& humanA);

#endif
