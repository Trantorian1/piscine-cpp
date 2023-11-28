#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstddef>

#include "libmini/color.hpp"

int	main(int argc, char *argv[]) {
	std::string		fileName;
	std::string		str_pattern;
	std::string		str_replace;
	std::string		str_line;
	std::ifstream	file_read;
	std::ofstream	file_write;
	std::size_t		index;

	if (argc != 4) {
		std::cerr << color::RED
			      << "Invalid argument count"
				  << color::RESET
				  << std::endl;

		return (EXIT_FAILURE);
	}

	fileName = argv[1];
	str_pattern = argv[2];
	str_replace = argv[3];

	if (fileName.empty() || str_pattern.empty()) {
		std::cerr << color::RED
			      << "Empty file name or pattern"
				  << color::RESET
				  << std::endl;

		return (EXIT_FAILURE);
	}

	file_read.open(fileName.c_str());
	if (file_read.good() == false) {
		std::cerr << color::RED
			      << "Error opening file \"" << fileName << '"'
				  << color::RESET
				  << std::endl;

		return (EXIT_FAILURE);
	}

	file_write.open(fileName.append(".replace").c_str());
	if (file_write.good() == false) {
		std::cerr << color::RED
			      << "Error opening file \"" << fileName << '"'
				  << color::RESET
				  << std::endl;

		return (EXIT_FAILURE);
	}
	
	while (file_read.good() == true) {
		std::getline(file_read, str_line);

		index = 0;
		while (true) {
			index = str_line.find(str_pattern, index);
			if (index == std::string::npos)
				break;

			str_line.erase(index, str_pattern.size());
			str_line.insert(index, str_replace);
			index += str_replace.size();
		}

		if (file_read.eof() == false)
			file_write << str_line << '\n';
		else
			file_write << str_line;
	}

	return (EXIT_SUCCESS);
}
