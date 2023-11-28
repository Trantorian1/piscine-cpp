#include "Zombie.hpp"

#include <cstddef>

Zombie*	zombieHorde(int N, std::string name) {
	Zombie	*horde;

	if (N < 1)
		return (NULL);

	horde = new Zombie[N];

	for (int index = 0; index < N; index++) {
		horde[index].setName(name);
	}

	return (horde);
}
