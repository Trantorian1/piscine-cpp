#include "Harl.hpp"
#include "level.hpp"

#include <cstdlib>

int	main(void) {
	Harl::complain(level::DEBUG);
	Harl::complain(level::INFO);
	Harl::complain(level::WARNING);
	Harl::complain(level::ERROR);
	Harl::complain("bogus");

	return (EXIT_SUCCESS);
}
