//
// Created by aymeric on 02/10/23.
//

#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <exception>

class RPN {
private:
	std::stack<double> numbers;
public:
	RPN();
	~RPN();
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
	void calcul(std::string input);
};

#endif //RPN_HPP
