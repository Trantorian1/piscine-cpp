#include "HumanA.hpp"
#include "HumanB.hpp"

#include <cstdlib>
#include <iostream>

int	main(void) {
	Weapon	scimitar("scimitar");
	Weapon	greatsword("greatsword");
	Weapon	warhammer("warhammer");

	HumanA	saladin("Salah ad-Din", scimitar);
	HumanB	william("William Wallace");
	HumanA	charles("Charles Martel, 'The Hammer'", warhammer);

	william.attack();
	william.setWeapon(greatsword);

	saladin.attack();
	william.attack();
	charles.attack();

	std::cout << "\nSwaperoooo" << std::endl;

	scimitar.setType("shamshir");
	greatsword.setType("wallace sword");
	warhammer.setType("lazcannon");

	std::cout << "\nInfo\n" 
		      << saladin << '\n'
			  << william << '\n'
			  << charles << '\n'
		      << std::endl;

	saladin.attack();
	william.attack();
	charles.attack();

	return (EXIT_SUCCESS);
}
