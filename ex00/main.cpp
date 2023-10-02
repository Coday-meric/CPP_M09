#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 0;
	}
	BitcoinExchange Btc;

	Btc.setMap(argv[1]);
	Btc.setMap(static_cast<const char *>("data.csv"));

	Btc.calcul();

	return 0;
}
