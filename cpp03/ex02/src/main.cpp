#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <iostream>

int	main(void) {
	ClapTrap	clap("Clappy");
	ScavTrap	scav("Scavvy");
	FragTrap	frag("Fraggy");

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

	std::cout << "\n>> FRAG" << std::endl;
	std::cout << frag << std::endl;

	frag.attack("target");
	frag.takeDamage(9);
	frag.beRepaired(8);
	frag.highFiveGuys();
	
	std::cout << frag << std::endl;

	frag.setEnergyPoints(0);
	frag.attack("target");
	frag.beRepaired(1);
	frag.setEnergyPoints(10);
	frag.setHitPoints(0);

	std::cout << frag << std::endl;

	frag.attack("target");
	frag.beRepaired(1);
}
