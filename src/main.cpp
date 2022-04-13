#include <iostream>
#include <stdexcept>


// Simple command line version of the application:
int main(int argc, const char* argv[]) {
	if (argc < 3) { throw std::logic_error("Interactive mode not implemented"); };
	throw std::logic_error("Geometry parser not implemented");
	for (int i = 2; i < argc; ++i) { throw std::logic_error("Load case parser not implemented"); }
	throw std::logic_error("Calculation of structure not implementeed");
	throw std::logic_error("Output of results not implemented");

	return 0;
}
