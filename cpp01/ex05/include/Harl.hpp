#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl {
public:
	static void	complain(std::string level);

private:
	Harl(void);

	static void	debug(void);
	static void	info(void);
	static void	warning(void);
	static void	error(void);
};

#endif
