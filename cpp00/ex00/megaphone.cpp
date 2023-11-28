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
	std::ostringstream	stream;

	if (argc < 2)
	{
		std::cout << DEFAULT << std::endl;
		return (EXIT_FAILURE);
	}

	for (int index = 1; index < argc; index++)
	{
		word = argv[index];

		for (size_t jndex = 0; jndex < word.size(); jndex++)
			stream << static_cast<char>(std::toupper(word[jndex]));
	}
	std::cout << stream.str() << std::endl;

	return (EXIT_SUCCESS);
}
