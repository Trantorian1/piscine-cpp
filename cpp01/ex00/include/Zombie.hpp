#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie {
	public:
		Zombie(void);
		Zombie(const std::string& name);
		Zombie(const Zombie& other);
		~Zombie(void);
		Zombie&	operator=(Zombie& other);

		const std::string&	getName(void) const;
		void				announce(void) const;
	private:
		std::string	_name;
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
