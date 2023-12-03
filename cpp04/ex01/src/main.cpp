#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "libmini/pointer.hpp"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <sstream>

typedef mini::UniquePtr<Animal> AnimalPtr;

int	main(void) {
	Animal*	herd[10];

	for (std::size_t index = 0; index < 10; index++) {
		if (index % 2 == 0)
			herd[index] = new Dog();
		else
			herd[index] = new Cat();
	}

	std::cout << "\n>> Herd" << std::endl;
	for (std::size_t index = 0; index < 10; index++) {
		std::cout << index << ": " << *herd[index] << std::endl;
	}

	std::cout << "\n>> Sound" << std::endl;
	for (std::size_t index = 0; index < 10; index++) {
		std::cout << index << ": ";
		herd[index]->makeSound();
	}

	for (std::size_t index = 0; index < 10; index++) {
		delete (herd[index]);
	}

	return (EXIT_SUCCESS);
}
