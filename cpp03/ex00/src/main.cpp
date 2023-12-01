#include "ClapTrap.hpp"

#include <cstdlib>
#include <iostream>

int	main(void) {
	ClapTrap	clap("Clappy");

	std::cout << "\n>> CLAP" << std::endl;
	std::cout << clap << std::endl;

	clap.attack("target");
	clap.takeDamage(9);
	clap.beRepaired(8);
	
	std::cout << clap << std::endl;

	clap.setEnergyPoints(0);
	clap.attack("target");
	clap.beRepaired(1);
	clap.setEnergyPoints(10);
	clap.setHitPoints(0);

	std::cout << clap << std::endl;

	clap.attack("target");
	clap.beRepaired(1);

	return (EXIT_SUCCESS);
}
