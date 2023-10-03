//
// Created by aymeric on 22/09/23.
//

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {

}

BitcoinExchange::~BitcoinExchange() {

}

void BitcoinExchange::splitData(std::string line, std::string del) {
	std::string date;
	std::string nbr_t;
	float nbr;

	int end = line.find(del);
	date = line.substr(0, end);
	if (end != 10) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	line.erase(line.begin(), line.begin() + end + del.size());
	end = line.find(del);
	nbr_t = line.substr(0, end);
	if (end != -1) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	try {
		nbr = std::stof(nbr_t);
	}
	catch (std::exception &e) {
		std::cerr << "Error: bad input => " << date << std::endl;
		return;
	}
	if (del == " | ")
		this->insertData(this->input, date, nbr);
	else if (del == ",")
		this->insertData(this->db, date, nbr);
}

void BitcoinExchange::insertData(std::multimap<std::string, float> &container, std::string key, float value) {
	container.insert(std::pair<std::string, float>(key, value));
}

void BitcoinExchange::insertData(std::map<std::string, float> &container, std::string key, float value) {
	container.insert(std::pair<std::string, float>(key, value));
}

void BitcoinExchange::setMap(const char *file) {
	std::string del;
	std::ifstream f(file);
	if (!f) {
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}
	std::string f_line;
	std::getline(f, f_line);
	if (f_line == "date | value")
		del = " | ";
	else if (f_line == "date,exchange_rate")
		del = ",";
	else {
		std::cerr << "Error: not correct file." << std::endl;
		return;
	}
	std::string line;
	while (std::getline(f, line))
		this->splitData(line, del);
	f.close();
}

void BitcoinExchange::calcul() {
	float res;

	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::key_compare mycomp = db.key_comp();
	for (it = this->input.begin(); it != this->input.end(); ++it) {

		if (this->db.find(it->first) == this->db.end()) {
			std::map<std::string, float>::iterator it2 = db.begin();
			do {
			} while (mycomp((*it2++).first, it->first));
			*it2--;
			*it2--;
			res = it->second * it2->second;
		} else {
			res = it->second * this->db.find(it->first)->second;
		}
		if (res >= 1000) {
			std::cerr << "Error: too large number." << std::endl;
		} else if (it->second < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
		} else
			std::cout << it->first << " => " << it->second << " = " << res << std::endl;
	}
}