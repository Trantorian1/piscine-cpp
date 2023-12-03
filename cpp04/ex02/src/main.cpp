#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "libmini/pointer.hpp"

#include <cstdlib>
#include <iostream>

typedef mini::UniquePtr<AAnimal> AnimalPtr;

int	main(void) {
	// AnimalPtr	animal   = mini::UniquePtr<AAnimal>(new Animal("bear"));
	AnimalPtr	dog      = mini::UniquePtr<AAnimal>(new Dog());
	AnimalPtr	cat      = mini::UniquePtr<AAnimal>(new Cat());
	AnimalPtr	dogCpy   = mini::UniquePtr<AAnimal>(new Dog(*(Dog *)dog.getPtr()));
	AnimalPtr	catCpy   = mini::UniquePtr<AAnimal>(new Cat(*(Cat *)cat.getPtr()));

	std::cout << "\n>> Animals" << std::endl;
	std::cout << dog << ": " << *dog << std::endl;
	std::cout << cat << ": " << *cat << std::endl;
	std::cout << dogCpy << ": " << *dogCpy << std::endl;
	std::cout << catCpy << ": " << *catCpy << std::endl;

	std::cout << "\n>> MakeSound" << std::endl;

	std::cout << "dog: " << std::endl;
	dog->makeSound();

	std::cout << "dog copy: " << std::endl;
	dogCpy->makeSound();

	std::cout << "cat: " << std::endl;
	cat->makeSound();

	std::cout << "cat copy: " << std::endl;
	catCpy->makeSound();

	return (EXIT_SUCCESS);
}
