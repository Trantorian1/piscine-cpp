#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "materia.hpp"
#include "libmini/pointer.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>

int main(void) {
	static const int		width = 12;
	Ice						ice;
	Cure					cure;
	mini::uniqueptr<Cure>	tmp = mini::make_unique<Cure>();
	MateriaSource			materiaSource;
	Character				mule("The Mule");
	Character				hanPritcher("Han Pritcher");

	// =======================[ SIMPLE MATERIA TESTS ]======================= //

	std::cout << ">> Materia\n"
		      << std::setw(width) << "ice: " << ice << '\n'
		      << std::setw(width) << "cure: " << cure << '\n'
			  << std::endl;

	// =======================[ MATERIA SOURCE TESTS ]======================= //

	materiaSource.learnMateria(&ice);
	materiaSource.learnMateria(&cure);
	materiaSource.learnMateria(&cure);
	materiaSource.learnMateria(&cure);
	materiaSource.learnMateria(&cure);

	std::cout << ">> Materia Source\n"
	          << std::setw(width) << std::boolalpha
 			  << "knows ice: " << materiaSource.knows(&ice) << '\n'
	          << std::setw(width) << std::boolalpha
			  << "knows cure: " << materiaSource.knows(&cure) << '\n'
	          << std::setw(width) << std::boolalpha
			  << "is full: " << !materiaSource.hasSpaceLeft() << '\n'
			  << std::endl;

	// ========================[ CHARACTER USE TESTS ]======================= //

	std::cout << ">> Materia Use" << std::endl;

	hanPritcher.use(0, mule);
	hanPritcher.equip(materiaSource.createMateria(materia::ICE));
	hanPritcher.equip(tmp);
	hanPritcher.equip(materiaSource.createMateria(materia::ICE));

	// copying a character should crete new materia, hence not resulting in a
	// segfault when deleting
	Character	dup = hanPritcher;

	// unequip should still let have remove heal from hanPritcher's materias
	// (also means no segfault since tmp will be freed by smart pointer)
	hanPritcher.unequip(1);
	hanPritcher.use(0, mule);
	hanPritcher.use(1, hanPritcher);
	hanPritcher.use(2, mule);

	dup.use(1, dup);

	std::cout << std::setw(width) << std::boolalpha
		      << "\nspace left: " << dup.hasSpaceLeft() << '\n'
			  << "*adding materia*"
			  << std::endl;

	// no more space left here
	dup.equip(materiaSource.createMateria(materia::CURE));
	dup.equip(tmp);

	std::cout << std::setw(width) << std::boolalpha
		      << "space left: " << dup.hasSpaceLeft() << '\n'
			  << std::endl;

	std::cout << ">> Double Equip\n"
		      << "*should segfault if not protected"
		      << std::endl;

	AMateria	*doubleEquip = materiaSource.createMateria(materia::ICE);
	Character	test("fred");

	// you should not be able to add the same materia twice, as this causes
	// segfaults when calling the Character destructor
	test.equip(doubleEquip);
	test.equip(doubleEquip);

	return (EXIT_SUCCESS);
}
