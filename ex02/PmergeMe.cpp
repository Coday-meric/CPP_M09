//
// Created by aymeric on 02/10/23.
//

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){

}

PmergeMe::~PmergeMe() {

}

PmergeMe::PmergeMe(int argc, char **argv) {
	int i = 1;
	int temp;
	std::string temps;

	while (i < argc)
	{
		temp = std::atoi(argv[i]);
		temps = static_cast<std::string>(argv[i]);
		for (int i = 0; i < temps.length (); i++)
			if (!isdigit(temps[i]))
				throw NumberNotNumber();
		if (temp <= 0)
			throw NumberNotNumber();
		listv.push_back(temp);
		listd.push_back(temp);
		listbase.push_back(temp);
		i++;
	}
}

void PmergeMe::sortd() {
	std::deque<unsigned int>::iterator it1, it2;
	for (it1 = listd.begin() + 1; it1 != listd.end(); ++it1)
	{
		int temp = *it1;
		it2 = it1;
		while (it2 != listd.begin() && *(std::prev(it2)) > temp)
		{
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = temp;
	}
}

void PmergeMe::sortv() {
	std::vector<unsigned int>::iterator it1, it2;
	for (it1 = listv.begin() + 1; it1 != listv.end(); ++it1)
	{
		int temp = *it1;
		it2 = it1;
		while (it2 != listv.begin() && *(std::prev(it2)) > temp)
		{
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = temp;
	}
}

void PmergeMe::display() {
	clock_t start;
	clock_t end;

	start = clock();
	this->sortd();
	end = clock();
	double d = end - start;

	start = clock();
	this->sortv();
	end = clock();
	double v = end - start;

	double diffv = v / ( CLOCKS_PER_SEC / 1000 );
	double diffd = d / ( CLOCKS_PER_SEC / 1000 );

	std::cout << "Before : ";
	for (std::vector<unsigned int>::iterator it = listbase.begin() ; it != listbase.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "After : ";
	for (std::vector<unsigned int>::iterator it = listv.begin() ; it != listv.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "Time to process a range of " << listbase.size() << " elements with std::vector : " << diffv << " us" << std::endl;
	std::cout << "Time to process a range of " << listbase.size() << " elements with std::deque : " << diffd << " us" << std::endl;
}