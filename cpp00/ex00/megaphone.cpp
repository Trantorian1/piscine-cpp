#include <cctype>
#include <cstdlib>
#include <iostream>
#include <cstddef>
#include <sstream>
#include <string>

#define DEFAULT "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main (int argc, char *argv[])
{
	std::string			word;
	std::size_t			bound = static_cast<std::size_t>(argc);
	std::ostringstream	stream;

	if (argc < 2)
	{
		std::cout << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}

	for (std::size_t index = 1; index < bound; index++)
	{
		word = argv[index];

		for (size_t jndex = 0; jndex < word.size(); jndex++)
			stream << static_cast<char>(std::toupper(word[jndex]));
	}
	std::cout << stream.str() << std::endl;

	return (EXIT_SUCCESS);
}
