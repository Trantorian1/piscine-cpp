#include "HumanA.hpp"
#include "HumanB.hpp"
#include "libmini/color.hpp"

#include <cstdlib>
#include <iostream>

int	main(void) {
	Weapon	scimitar("scimitar");
	Weapon	greatsword("greatsword");
	Weapon	warhammer("warhammer");

	HumanA	saladin("Salah ad-Din", scimitar);
	HumanB	william("William Wallace");
	HumanA	charles("Charles Martel, 'The Hammer'", warhammer);

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
			  << charles
		      << std::endl;

	return (EXIT_SUCCESS);
}
