#include "PmergeMe.hpp"

int main(int argc, char **argv) {
	if (argc == 1) {
		std::cerr << "Error: List not found in parameter." << std::endl;
		return 0;
	}

	try{
		PmergeMe Pm(argc, argv);
		Pm.display();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
