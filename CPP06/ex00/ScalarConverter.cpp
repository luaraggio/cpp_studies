/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 19:52:16 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/19 16:39:53 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib> // strtod
#include <climits> // INT_MIN, INT_MAX
#include <cfloat> // FLT_MAX, FLT_MIN
#include <cctype> // isprint

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

HandleScalarTypes::HandleScalarTypes() {}

HandleScalarTypes::~HandleScalarTypes() {}

void ScalarConverter::converter(const std::string input) {
	HandleScalarTypes::handleChar(input);
	HandleScalarTypes::handleInt(input);
	HandleScalarTypes::handleFloat(input);
	HandleScalarTypes::handleDouble(input);
}

bool isPseudoLiteral(const std::string& str) {
	return (str == "nan" || str == "nanf"
		|| str == "+inf" || str == "-inf"
		|| str == "+inff" || str == "-inff");
}

bool	isPrintableChar(char c) {
	return (std::isprint(static_cast<unsigned char>(c)));
}

void HandleScalarTypes::handleChar(const std::string& input) {
	std::cout << "char: ";

	if (isPseudoLiteral(input)) { //Verifico se é um valor válido para char!!
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (input.length() == 1 && !std::isdigit(input[0])) { //Verifico se é um literal simples!! 'a'
		char c = input[0];

		if (!isPrintableChar(c)) {
			std::cout << "Non displayable" << std::endl;
		}
		else {
			std::cout << "'" << c << "'" << std::endl;
		}
		return ;
	}

	char* end;
	double value = std::strtod(input.c_str(), &end);

	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (value < 0 || value > 127) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	char c = static_cast<char>(value);

	if (!isPrintableChar(c)) {
		std::cout << "Non displayable" << std::endl;
		return ;
	}

	std::cout << "'" << c << "'" << std::endl;
}

void	HandleScalarTypes::handleInt(const std::string& input) {
	std::cout << "int: ";

	if (isPseudoLiteral(input)) { //Verifico se é um valor válido para int
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (input.length() == 1 && !std::isdigit(input[0])) {
		std::cout << static_cast<int>(input[0]) << std::endl;
		return ;
	}

	char* end;
	double value = std::strtod(input.c_str(), &end);

	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	if (value < INT_MIN || value > INT_MAX) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	int i = static_cast<int>(value);
	std::cout << i << std::endl;
}

void	HandleScalarTypes::handleFloat(const std::string& input) {
	std::cout << "float: ";

	if (input == "nan" || input == "nanf") {
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (input == "+inf" || input == "+inff") {
		std::cout << "+inff" << std::endl;
		return ;
	}
	if (input == "-inf" || input == "-inff") {
		std::cout << "-inff" << std::endl;
		return ;
	}

	if (input.length() == 1 && !std::isdigit(input[0])) {
		float f = static_cast<float>(input[0]);
		std::cout << f << ".0f" << std::endl;
		return ;
	}

	char* end;
	double value = std::strtod(input.c_str(), &end);

	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
		std::cout << "impossible" << std::endl;
		return;
	}

	if (value < -FLT_MAX || value > FLT_MAX) {
		std::cout << "impossible" << std::endl;
		return ;
	}

	float f = static_cast<float>(value);

	std::cout << f;
	if (f == static_cast<int>(f)) {
		std::cout << ".0";
	}
	std::cout << "f" << std::endl;
}

void	HandleScalarTypes::handleDouble(const std::string& input) {
	std::cout << "double: ";

	if (input == "nan" || input == "nanf") {
		std::cout << "nan" << std::endl;
		return ;
	}
	if (input == "+inf" || input == "+inff") {
		std::cout << "+inf" << std::endl;
		return ;
	}
	if (input == "-inf" || input == "-inff") {
		std::cout << "-inf" << std::endl;
		return ;
	}

	if (input.length() == 1 && !std::isdigit(input[0])) {
		double f = static_cast<double>(input[0]);
		std::cout << f << ".0" << std::endl;
		return ;
	}

	char* end;
	double value = std::strtod(input.c_str(), &end);

	if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
		std::cout << "impossible" << std::endl;
		return;
	}

	std::cout << value;
	if (value == static_cast<long>(value)) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}
