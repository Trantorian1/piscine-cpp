#include "Harl.hpp"
#include "complaint.hpp"
#include "level.hpp"
#include "libmini/array.hpp"
#include "libmini/color.hpp"

#include <cstddef>
#include <iostream>

// ===============================[ FUNCTIONS ]============================== //

void	Harl::complain(std::string level) {
	static std::string	g_levels[] = {
		level::DEBUG,
		level::INFO,
		level::WARNING,
		level::ERROR
	};
	static void	(*f_levels[])(void) = {
		Harl::debug,
		Harl::info,
		Harl::warning,
		Harl::error
	};

	for (std::size_t index = 0; index < mini::size(g_levels); index++) {
		if (level == g_levels[index])
			f_levels[index]();
	}
}

void	Harl::debug(void) {
	std::cout << color::BLUE << complaint::DEBUG << std::endl;
}

void	Harl::info(void) {
	std::cout << color::GREEN << complaint::INFO << std::endl;
}

void	Harl::warning(void) {
	std::cout << color::YELLOW << complaint::WARNING << std::endl;
}

void	Harl::error(void) {
	std::cout << color::RED << complaint::ERROR << std::endl;
}
