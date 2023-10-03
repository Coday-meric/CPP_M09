//
// Created by aymeric on 02/10/23.
//

#include "RPN.hpp"

RPN::RPN() {

}

RPN::~RPN() {

}

void RPN::calcul() {
	int res;
	int first;
	int last;

	first = std::stoi(this->rpn.top());
	this->rpn.pop();
	last = std::stoi(this->rpn.top());
	this->rpn.pop();
	std::string s = this->rpn.top();
	switch (s[0]) {
		case '+':
			res = first + last;
			break;
		case '-':
			res = first - last;
			break;
		case '/':
			if (first == 0 or last == 0)
			{
				res = 0;
				break;
			}
			res = first / last;
			break;
		case '*':
			res = first * last;
			break;
	}
	this->rpn.pop();
	while (!this->rpn.empty()) {
		last = std::stoi(this->rpn.top());
		this->rpn.pop();
		s = this->rpn.top();
		switch (s[0]) {
			case '+':
				res = res + last;
				break;
			case '-':
				res = res - last;
				break;
			case '/':
				if (first == 0 or last == 0)
				{
					res = 0;
					break;
				}
				res = first / last;
				break;
			case '*':
				res = res * last;
				break;
		}
		this->rpn.pop();
	}
	std::cout << res << std::endl;
}

bool RPN::format(std::string elem) {
	if (elem.size() != 1) {
		std::cerr << "Error : Number or arithmetic symbol too long" << std::endl;
		return false;
	}
	if (elem == "+" or elem == "-" or elem == "/" or elem == "*")
		return true;
	try {
		if (std::stoi(elem) >= 0 and std::stoi(elem) <= 9)
			return true;
		std::cerr << "Error : Number is not 0 to 10" << std::endl;
		return false;

	}
	catch (std::exception &e) {
		std::cerr << "Error : Number is not number" << std::endl;
		return false;
	}
}

void RPN::setExpress(std::string expression) {
	std::string del = " ";

	std::reverse(expression.begin(), expression.end());
	int end = expression.find(del);
	if (!this->format(expression.substr(0, end)))
		throw Error();
	this->rpn.push(expression.substr(0, end));
	while (end != -1) {
		expression.erase(expression.begin(), expression.begin() + end + del.size());
		end = expression.find(del);
		if (!this->format(expression.substr(0, end)))
			throw Error();
		this->rpn.push(expression.substr(0, end));
	}
}