/* Parses input file.
*/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <regex>

#include "geom2d.hpp"

namespace f2{

int parse_file(const std::string& file_path) {
	std::ifstream file(file_path);
	if (!file.is_open()) { return 1; };

	for (std::string line; std::getline(file, line); ) {
		if (line[0] == '#') { continue; };
		std::cout << line.substr(0, 2) << std::endl;
	};
	
	return 0;
};
	/* Use REGEX to parse the expected code.
         */
	auto parse_nodes(const std::string& file_path, const int count) {
		std::ifstream file(file_path); 
		std::string line;
		std::unordered_map<int, geom2d::point2d> nodes;

		for (int i = 0; i <= count; ++i) {
			std::getline(file, line);
		};

		return nodes;
	};

	/* input parser to use factory design pattern: have a function that is called that defines objects
         */
	int structure (const std::string& file_path) {
		std::ifstream file(file_path);
		if (!file.is_open()) { return 1; };

		for (std::string line; std::getline(file, line); ) {

		};
		
		return 0;
	};

	
	class file {
	};


	class structure : file {
		private:
			int ignore_line(const char* line) {
				std::cout << "Ignoring line" << std::endl;
				return (line and !line[0]) || line[0] == '#';
			};

		public:
			std::string file_path;

			structure(std::string string) { file_path = string; };
	};


	class results : file {
	};
};
