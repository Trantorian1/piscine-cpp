#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#include <iostream>

int	main(void) {
	ClapTrap	clap("Clappy");
	ScavTrap	scav("Scavvy");

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

	std::cout << "\n>> SCAV" << std::endl;
	std::cout << scav << std::endl;

	scav.attack("target");
	scav.takeDamage(9);
	scav.beRepaired(8);
	scav.guardGate();
	
	std::cout << scav << std::endl;

	scav.setEnergyPoints(0);
	scav.attack("target");
	scav.beRepaired(1);
	scav.setEnergyPoints(10);
	scav.setHitPoints(0);

	std::cout << scav << std::endl;

	scav.attack("target");
	scav.beRepaired(1);
}
