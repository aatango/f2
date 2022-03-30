#include <chrono>
#include <iostream>

#include "f2io.hpp"


// Simple command line version of the application:
int main(int argc, const char* argv[]) {

	// 1. Parse input file
	/* TO DO:
	 * - Validate file format before parsing;
         */
	std::string file_path;

	if (argc >= 2) {
		file_path = argv[1];
	} else {
		std::cout << "Enter filepath to structure input file: ";
		std::cin >> file_path;
	}

	std::cout << "Parsing input file: " << file_path << std::endl;


	// 2 Calculate structure
	auto start_time = std::chrono::high_resolution_clock::now();

	/* calculation here */

	auto end_time = std::chrono::high_resolution_clock::now();
	auto time_difference = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);


	// 3 Produce detailed results file
	// push to class later.
	auto const format_point = file_path.find_last_of('.');
	std::string output_file = file_path.substr(0, format_point) + "-results";
	std::ofstream file(output_file);
	file << "Hello, world" << std::endl;



	// 4 print out summary of results
	std::cout << "Calculation time [ms]: " << time_difference.count() << std::endl;


	return 0;
}
