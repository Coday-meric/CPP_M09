//
// Created by aymeric on 02/10/23.
//

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <time.h>
#include <exception>
#include <cctype>

class PmergeMe {
private:
	std::vector<unsigned int> listbase;
	std::vector<unsigned int> listv;
	std::deque<unsigned int> listd;
	PmergeMe();
public:
	PmergeMe(int argc, char **argv);
	~PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	void sortd();
	void sortv();
	void display();
	class NumberNotNumber : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Error : Parameter is not a positive number.";
		}
	};
};


#endif //PMERGEME_HPP
