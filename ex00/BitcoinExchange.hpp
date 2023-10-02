//
// Created by aymeric on 22/09/23.
//

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <map>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <iomanip>

class BitcoinExchange {
private:
	std::map<std::string, float> db;
	std::multimap<std::string, float> input;
	void splitData(std::string line, std::string del);
	void insertData(std::multimap<std::string, float> & container, std::string key, float value);
	void insertData(std::map<std::string, float> & container, std::string key, float value);
public:
	BitcoinExchange();
	~BitcoinExchange();
	void setMap(const char *file);
	void calcul();
};

#endif //BITCOINEXCHANGE_HPP
