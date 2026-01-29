/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:47:28 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/28 22:16:09 by lraggio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs) {
	if (this != &rhs) {
		this->_rates = rhs._rates;
	}
	return (*this);
}

bool	BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10) { //para ver se tem a quantidade para 21-05-2001
		return (false);
	}

	if (date[4] != '-' || date[7] != '-') { //verifica posição dos separadores
		return (false);
	}

	int year  = std::atoi(date.substr(0, 4).c_str()); //substring p/ ano -> char -> int
	int month = std::atoi(date.substr(5, 2).c_str());
	int day   = std::atoi(date.substr(8, 2).c_str());

	if (year < 2009) {
		return (false);
	}
	if (month < 1 || month > 12) {
		return (false);
	}
	if (day < 1) {
		return (false);
	}

	int daysInMonth[] = {
		31, // Jan
		28, // Feb
		31, // Mar
		30, // Apr
		31, // May
		30, // Jun
		31, // Jul
		31, // Aug
		30, // Sep
		31, // Oct
		30, // Nov
		31  // Dec
	};

	if (month == 2) { //tratamento de fevereiro p/ ano bissexto
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (leap ? 29 : 28)) {
			return (false);
		}
	} else { //trata 30 e 31 de outros anos
		if (day > daysInMonth[month - 1]) {
			return (false);
		}
	}
	return (true);
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = this->_rates.lower_bound(date);
	//lower_bound retorna a menor chave >= data ou end() se todas forem menores

	if (it == this->_rates.end()) {
		--it; // usa a última data disponível, se a data data do input for maior que todas do banco
		return (it->second);
	}

	if (it->first == date) {
		return (it->second); //retorna o exato valor daquela 'first' (data) específica
	}

	if (it == this->_rates.begin()) { //caso da data menor que tudo
		return (it->second); // usa a mais antiga disponível
	}

	--it;
	return (it->second); //data não existe -> usa a anterior
}

void BitcoinExchange::parseDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open database.");
	}

	std::string line;
	std::getline(file, line); // ignora header

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr)) {
			continue ;
		}

		double rate = std::strtod(rateStr.c_str(), NULL);
		this->_rates[date] = rate;
	}
}

bool	BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const {
	char *end;
	value = std::strtod(valueStr.c_str(), &end);

	if (end == valueStr.c_str() || *end != '\0') { //valor não foi convertido ou sobru lixo depois do número
		std::cerr << "Error: bad input => " << valueStr << std::endl;
		return (false);
	}

	if (value < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
		return (false);
	}

	if (value > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}


void BitcoinExchange::parseInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str()); //precisa ser c_str() porque file() não compila com std::string
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line); // ignora header

	while (std::getline(file, line)) { //lê o arquivo linha por linha
		std::istringstream ss(line); //transforma string em stream p/ facilitar gerenciamento
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) { //divide a linha usando "|" como separador
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ; //pula pra próxima linha
		}

		//remove espaços no final da data e no início do valor
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		double value;
		if (!isValidValue(valueStr, value)) {
			continue ;
		}

		double rate = getRateForDate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl; //faz a conta e o formato
	}
}
