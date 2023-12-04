#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "libmini/pointer.hpp"

#include <cstdlib>
#include <iostream>

typedef mini::uniqueptr<Animal> AnimalPtr;
typedef mini::uniqueptr<WrongAnimal> WAnimalPtr;

int	main(void) {
	AnimalPtr	animal   = mini::uniqueptr<Animal>(new Animal("bear"));
	AnimalPtr	dog      = mini::uniqueptr<Animal>(new Dog());
	AnimalPtr	cat      = mini::uniqueptr<Animal>(new Cat());
	WAnimalPtr	wrongCat = mini::uniqueptr<WrongAnimal>(new WrongCat());
	AnimalPtr	dogCpy   = mini::uniqueptr<Animal>(new Dog(*(Dog *)dog.getPtr()));
	AnimalPtr	catCpy   = mini::uniqueptr<Animal>(new Cat(*(Cat *)cat.getPtr()));

	std::cout << "\n>> Animals" << std::endl;
	std::cout << animal << ": " << *animal << std::endl;
	std::cout << dog << ": " << *dog << std::endl;
	std::cout << cat << ": " << *cat << std::endl;
	std::cout << wrongCat << ": " << *wrongCat << std::endl;
	std::cout << dogCpy << ": " << *dogCpy << std::endl;
	std::cout << catCpy << ": " << *catCpy << std::endl;

	std::cout << "\n>> MakeSound" << std::endl;

	std::cout << "animal: " << std::endl;
	animal->makeSound();

	std::cout << "dog: " << std::endl;
	dog->makeSound();

	std::cout << "dog copy: " << std::endl;
	dogCpy->makeSound();

	std::cout << "cat: " << std::endl;
	cat->makeSound();

	std::cout << "cat copy: " << std::endl;
	catCpy->makeSound();

	std::cout << "wrong cat: " << std::endl;
	wrongCat->makeSound();

	return (EXIT_SUCCESS);
}
