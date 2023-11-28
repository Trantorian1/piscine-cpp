#include "Zombie.hpp"
#include "libmini/pointer.hpp"

#include <cstdlib>

int	main(void) {
	Zombie	*horde = zombieHorde(12, "Steve");

	for (int index = 0; index < 12; index++) {
		horde[index].announce();
	}

	delete[] (horde);

	return (EXIT_SUCCESS);
}
