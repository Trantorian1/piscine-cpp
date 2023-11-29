#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>
# include <ostream>

class Weapon {
public:
	Weapon(void);
	Weapon(const std::string& type);
	Weapon(const Weapon& other);
	~Weapon(void);

	Weapon&	operator=(const Weapon& other);

	std::string	getType(void) const;
	void		setType(const std::string& newType);

private:
	std::string	_type;
};

std::ostream&	operator<<(std::ostream& os, const Weapon& other);

#endif
