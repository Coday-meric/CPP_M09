#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	RPN Rpn;

	Rpn.calcul(static_cast<std::string>(argv[1]));
	return 0;
}
