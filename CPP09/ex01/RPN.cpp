/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:34:44 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/21 15:45:37 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN (const RPN& other) : _stack(other._stack) {}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		_stack = other._stack;
	}
	return (*this);
}

RPN::~RPN() {}

bool RPN::isNumberToken(const std::string& token) {
	return (token.length() == 1 && std::isdigit(token[0]));
}

bool RPN::isOperatorToken(const std::string& token) {
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

void RPN::performRPN(const std::string& expression) {
	std::istringstream ss(expression);
	std::string token;

	while (ss >> token) {

		if (isNumberToken(token)) {
			_stack.push(token[0] - '0');
		}

		else if (isOperatorToken(token)) {

			if (_stack.size() < 2) {
				throw std::runtime_error("Error: not enough operands.");
			}

			int op2 = _stack.top();
			_stack.pop();
			int op1 = _stack.top();
			_stack.pop();

			int result = performOperations(op1, op2, token);
			_stack.push(result);
		}

		else {
			throw std::runtime_error("Error: invalid token."); //1 2 a +
		}
	}

	if (_stack.size() != 1) {
		throw std::runtime_error("Error: invalid expression."); //1 2 3 +
	}
	std::cout << _stack.top() << std::endl;
}

int RPN::performOperations(int op1, int op2, const std::string& op) {
	if (op == "+") {
		return (op1 + op2);
	}
	if (op == "-") {
		return (op1 - op2);
	}
	if (op == "*") {
		return (op1 * op2);
	}
	if (op == "/") {
		if (op2 == 0) {
			throw std::runtime_error("Error: Division by zero");
		}
		return (op1 / op2);
	}
	return (0);
}
