/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraggio <lraggio@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 14:47:28 by lraggio           #+#    #+#             */
/*   Updated: 2026/01/21 15:40:47 by lraggio          ###   ########.fr       */
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
		_rates = rhs._rates;
	}
	return (*this);
}

bool	BitcoinExchange::isValidValue(double value) const {
	if (value < 0) {
		return (false);
	}
	if (value > 1000) {
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::isValidDate(const std::string& date) const {
	if (date.length() != 10) { //para ver se tem a quantidade para 21-05-2001
		return (false);
	}

	if (date[4] != '-' || date[7] != '-') { //se houver outro separador em DD-MM-YEAR
		return (false);
	}

	int year  = std::atoi(date.substr(0, 4).c_str());
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

	if (month == 2) { //ano bissextp
		bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
		if (day > (leap ? 29 : 28)) {
			return (false);
		}
	} else {
		if (day > daysInMonth[month - 1]) {
			return (false);
		}
	}
	return (true);
}

double BitcoinExchange::getRateForDate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

	if (it == _rates.end()) {
		--it; // usa a última data disponível
		return (it->second);
	}

	if (it->first == date)
		return (it->second);

	if (it == _rates.begin())
		return (it->second); // usa a mais antiga disponível

	--it;
	return (it->second);
}

void BitcoinExchange::parseDatabase(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		throw std::runtime_error("Error: could not open database.");
	}

	std::string line;
	std::getline(file, line); // ignore header

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		std::string rateStr;

		if (!std::getline(ss, date, ',') || !std::getline(ss, rateStr))
			continue;

		double rate = std::strtod(rateStr.c_str(), NULL);
		_rates[date] = rate;
	}
}

void BitcoinExchange::parseInputFile(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: could not open file." << std::endl;
		return ;
	}

	std::string line;
	std::getline(file, line); // ignora header

	while (std::getline(file, line)) {
		std::istringstream ss(line);
		std::string date;
		std::string valueStr;

		if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr)) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}

		// trim
		date.erase(date.find_last_not_of(" \t") + 1);
		valueStr.erase(0, valueStr.find_first_not_of(" \t"));

		if (!isValidDate(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue ;
		}

		double value = std::strtod(valueStr.c_str(), NULL);

		if (value < 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}

		double rate = getRateForDate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
