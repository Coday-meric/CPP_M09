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
	std::stack<std::string> rpn;
public:
	RPN();
	~RPN();
	RPN(RPN const &src);
	RPN &operator=(RPN const &rhs);
	void setExpress(std::string expression);
	void calcul();
	bool format(std::string elem);
	class Error : public std::exception {
	public:
		virtual const char *what() const throw() {
			return "Le programme a quitte !";
		}
	};
};

#endif //RPN_HPP
