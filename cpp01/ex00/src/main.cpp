#include "Zombie.hpp"
#include "libmini/pointer.hpp"

#include <cstdlib>

int	main(void) {
	mini::UniquePtr<Zombie>	zombie = mini::UniquePtr<Zombie>(newZombie("Steve"));

	zombie->announce();
	randomChump("Alex");

	return (EXIT_SUCCESS);
}
