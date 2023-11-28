#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"
# include <ostream>
# include <string>

class HumanB {
public:
	HumanB(const std::string& name);
	HumanB(const HumanB& other);
	~HumanB(void);

	HumanB&	operator=(const HumanB& other);

	const Weapon&		getWeapon(void) const;
	const std::string&	getName(void) const;
	void				setWeapon(Weapon& newWeapon);

	void	attack(void) const;

private:
	std::string	_name;
	Weapon*		_weapon;
};

std::ostream&	operator<<(std::ostream& os, const HumanB& humanB);

#endif
