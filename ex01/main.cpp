#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	RPN Rpn;

	try {
		Rpn.setExpress(static_cast<std::string>(argv[1]));
		Rpn.calcul();
	}
	catch (std::invalid_argument &e) {
		std::cout << 0 << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
