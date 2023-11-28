#include <string>
#include <iostream>
#include <cstdlib>

std::string global = "HI THIS IS THE BRAIN";

int	main(void) {
	std::string		*stringPTR = &global;
	std::string		&stringREF = global;

	std::cout << "ADDRESS\n"
		      << "global   : " << std::hex << &global << '\n'
			  << "stringPTR: " << std::hex << stringPTR << '\n'
			  << "stringREF: " << std::hex << &stringREF << '\n'
			  << '\n'
			  << "VALUE\n"
			  << "global   : " << global << '\n'
			  << "stringPTR: " << *stringPTR << '\n'
			  << "stringREF: " << stringREF << std::endl;

	return (EXIT_SUCCESS);
}
