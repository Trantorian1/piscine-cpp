#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <string>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main (int argc, char *argv[])
{
	std::string	word;
	std::size_t	bound = static_cast<std::size_t>(argc);

	if (argc < 2)
	{
		std::cout << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}

	for (std::size_t index = 1; index < bound; index++)
	{
		word = argv[index];
		std::transform(word.begin(), word.end(), word.begin(), ::toupper);

		std::cout << word;
	}
	std::cout << std::endl;

	return (EXIT_SUCCESS);
}
